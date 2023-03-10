package com.zeroone.star.payablemanagement.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.payablemanagement.entity.FinPayableCheck;
import com.zeroone.star.payablemanagement.entity.FinPayableCheckEntry;
import com.zeroone.star.payablemanagement.mapper.FinPayableCheckMapper;
import com.zeroone.star.payablemanagement.service.IFinPayableCheckEntryService;
import com.zeroone.star.payablemanagement.service.IFinPayableCheckService;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.payablemanagement.CheckPayableDTO;
import com.zeroone.star.project.dto.payablemanagement.CheckPayableEntryDTO;
import com.zeroone.star.project.query.payablemanagement.CheckPayableQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payablemanagement.CheckPayableVO;
import com.zeroone.star.project.vo.payablemanagement.PayableVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.util.CollectionUtils;

import javax.annotation.Resource;
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

    @Resource
    private UserHolder userHolder;

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

    @Resource
    FinPayableCheckMapper mapper;

    /**
     * 重构
     *
     * @param query 查询条件
     * @return 分页后VO
     * @author spk
     */
    @Override
    public PageVO<CheckPayableVO> getAll(CheckPayableQuery query) {
        List<CheckPayableVO> list = mapper.getAllCheckPayable(query);
        if (list.isEmpty()) {
            return null;
        }
        long pages = list.size() % query.getPageSize() == 0 ? list.size() / query.getPageSize() : list.size() / query.getPageSize() + 1;
        if (pages < query.getPageIndex() + 1) return null;
        return new PageVO<>(query.getPageIndex(),
                query.getPageSize(),
                (long) list.size(),
                pages,
                list.subList((int) query.getPageIndex() * (int) query.getPageSize(),
                        pages == query.getPageIndex() + 1 ? list.size() : (int) (query.getPageSize() * (query.getPageIndex() + 1))));
    }


    private void updateWithEntry(CheckPayableDTO dto) {
        FinPayableCheck finPayableCheck = new FinPayableCheck();
        BeanUtil.copyProperties(dto, finPayableCheck);
        this.updateById(finPayableCheck);
        finPayableCheckEntryService.remove(new LambdaQueryWrapper<FinPayableCheckEntry>()
            .eq(FinPayableCheckEntry::getMid, dto.getId()));
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
    public void removeWithEntry(List<String> ids) {
        // 删除应付核销表数据
        this.removeByIds(ids);
        // 删除应付核销明细表对应的数据
        finPayableCheckEntryService.remove(new LambdaQueryWrapper<FinPayableCheckEntry>()
            .in(FinPayableCheckEntry::getMid, ids));
    }

    @Override
    public boolean isCheckPass(String id, String approvalResultType, String approvalRemark) {
        String username = "";
        try {
            username = userHolder.getCurrentUser().getUsername();
        } catch (Exception e) {
            log.error("无法获取当前用户！", e);
        }
        if ("1".equals(approvalResultType)) {
            this.lambdaUpdate()
                .set(FinPayableCheck::getApprovalResultType, approvalResultType)
                .set(FinPayableCheck::getApprovalRemark, approvalRemark)
                .set(FinPayableCheck::getIsClosed, 1)
                .set(FinPayableCheck::getBillStage, "3")
                .set(FinPayableCheck::getApprover, username)
                .eq(FinPayableCheck::getId, id)
                .update();
            return true;
        } else if ("2".equals(approvalResultType)) {
            this.lambdaUpdate()
                .set(FinPayableCheck::getApprovalResultType, approvalResultType)
                .set(FinPayableCheck::getApprovalRemark, approvalRemark)
                .set(FinPayableCheck::getIsClosed, 0)
                .set(FinPayableCheck::getBillStage, "4")
                .set(FinPayableCheck::getApprover, username)
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
