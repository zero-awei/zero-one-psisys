package com.zeroone.star.payablemanagement.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.payablemanagement.entity.FinPayableCheck;
import com.zeroone.star.payablemanagement.entity.FinPayableCheckEntry;
import com.zeroone.star.payablemanagement.mapper.FinPayableCheckMapper;
import com.zeroone.star.payablemanagement.service.IFinPayableCheckEntryService;
import com.zeroone.star.payablemanagement.service.IFinPayableCheckService;
import com.zeroone.star.project.dto.payablemanagement.CheckPayableDTO;
import com.zeroone.star.project.dto.payablemanagement.CheckPayableEntryDTO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.util.CollectionUtils;

import java.math.BigDecimal;
import java.time.LocalDateTime;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

/**
 * <p>
 * 应付核销单 服务实现类
 * </p>
 *
 * @author j3
 * @since 2023-02-14
 */
@Service
public class FinPayableCheckServiceImpl extends ServiceImpl<FinPayableCheckMapper, FinPayableCheck> implements
    IFinPayableCheckService {

    @Autowired
    private IFinPayableCheckEntryService finPayableCheckEntryService;

    @Transactional(rollbackFor = Exception.class)
    @Override
    public void submitAdd(CheckPayableDTO dto) {
        // 判断是否允许提交 即上下核销金额是否一致
        isAllowSubmit(dto);
        // 设置单据状态为编制完
        dto.setBillStage("2");
        // 执行写库操作
        addWithEntry(dto);
    }

    @Transactional(rollbackFor = Exception.class)
    @Override
    public void saveAdd(CheckPayableDTO dto) {
        // 判空
        isEmpty(dto);
        // 设置单据状态为编制中
        dto.setBillStage("1");
        // 执行写库操作
        addWithEntry(dto);
    }

    private void addWithEntry(CheckPayableDTO dto) {
        FinPayableCheck finPayableCheck = new FinPayableCheck();
        BeanUtil.copyProperties(dto, finPayableCheck);
        finPayableCheck.setIsEffective(true);
        finPayableCheck.setEffectiveTime(LocalDateTime.now());
        this.save(finPayableCheck);
        List<FinPayableCheckEntry> list = BeanUtil.copyToList(dto.getCheckPayableEntryList(),
            FinPayableCheckEntry.class);
        list.forEach(item -> {
            item.setBillNo(finPayableCheck.getBillNo());
            item.setMid(finPayableCheck.getId());
        });
        finPayableCheckEntryService.saveBatch(list);
    }

    @Transactional(rollbackFor = Exception.class)
    @Override
    public void submitModify(CheckPayableDTO dto) {
        // 判断是否允许提交 即上下核销金额是否一致
        isAllowSubmit(dto);
        // 设置单据状态为编制完
        dto.setBillStage("2");
        // 执行写库操作
        updateWithEntry(dto);
    }

    @Transactional(rollbackFor = Exception.class)
    @Override
    public void saveModify(CheckPayableDTO dto) {
        // 判空
        isEmpty(dto);
        // 设置单据状态为编制中
        dto.setBillStage("1");
        // 执行写库操作
        updateWithEntry(dto);
    }

    private void updateWithEntry(CheckPayableDTO dto) {
        FinPayableCheck finPayableCheck = new FinPayableCheck();
        BeanUtil.copyProperties(dto, finPayableCheck);
        this.updateById(finPayableCheck);
        List<FinPayableCheckEntry> list = BeanUtil.copyToList(dto.getCheckPayableEntryList(),
            FinPayableCheckEntry.class);
        // TODO:明细表的修改或许应该先删除再新增 待测试
        finPayableCheckEntryService.updateBatchById(list);
    }

    @Transactional(rollbackFor = Exception.class)
    @Override
    public void removeWithEntry(List<String> ids) {
        // 删除应付核销表数据
        this.removeByIds(ids);
        // 删除应付核销明细表对应的数据
        finPayableCheckEntryService.remove(new LambdaQueryWrapper<FinPayableCheckEntry>()
            .in(FinPayableCheckEntry::getMid, ids));
    }

    @Override
    public boolean isCheckPass(String id, String approvalResultType, String approvalRemark) {
        if ("1".equals(approvalResultType)) {
            this.lambdaUpdate()
                .set(FinPayableCheck::getApprovalResultType, approvalResultType)
                .set(FinPayableCheck::getApprovalRemark, approvalRemark)
                .set(FinPayableCheck::getIsClosed, 1)
                .set(FinPayableCheck::getBillStage, "3")
                .eq(FinPayableCheck::getId, id)
                .update();
            return true;
        } else if ("2".equals(approvalResultType)) {
            this.lambdaUpdate()
                .set(FinPayableCheck::getApprovalResultType, approvalResultType)
                .set(FinPayableCheck::getApprovalRemark, approvalRemark)
                .set(FinPayableCheck::getBillStage, "4")
                .eq(FinPayableCheck::getId, id)
                .update();
            return false;
        }
        return false;
    }

    private static void isEmpty(CheckPayableDTO dto) {
        // 判空 明细为空直接抛异常
        List<CheckPayableEntryDTO> checkPayableEntryList = dto.getCheckPayableEntryList();
        if (CollectionUtils.isEmpty(checkPayableEntryList)) {
            throw new RuntimeException("应付核销单明细为空！");
        }
    }

    private static void isAllowSubmit(CheckPayableDTO dto) {
        // 判空
        isEmpty(dto);
        // 按核销方向分组
        Map<String, List<CheckPayableEntryDTO>> collect = dto.getCheckPayableEntryList().stream()
            .collect(Collectors.groupingBy(CheckPayableEntryDTO::getCheckSide));
        List<CheckPayableEntryDTO> list1 = collect.get("1");
        List<CheckPayableEntryDTO> list2 = collect.get("2");
        // 计算各自的核销金额是否一致
        BigDecimal b1 = new BigDecimal(0);
        for (CheckPayableEntryDTO item : list1) {
            b1 = b1.add(item.getAmt());
        }
        BigDecimal b2 = new BigDecimal(0);
        for (CheckPayableEntryDTO item : list2) {
            b2 = b2.add(item.getAmt());
        }
        // 比较是否一致 不一致直接抛异常
        if (b1.compareTo(b2) != 0) {
            throw new RuntimeException("上下核销不一致，无法提交！");
        }
    }
}
