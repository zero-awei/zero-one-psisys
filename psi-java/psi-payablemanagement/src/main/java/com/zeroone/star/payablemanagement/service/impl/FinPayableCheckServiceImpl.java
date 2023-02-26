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
        isAllowSubmit(dto);
        addWithEntry(dto);
    }

    @Transactional(rollbackFor = Exception.class)
    @Override
    public void saveAdd(CheckPayableDTO dto) {
        isEmpty(dto);
        addWithEntry(dto);
    }

    private void addWithEntry(CheckPayableDTO dto) {
        FinPayableCheck finPayableCheck = new FinPayableCheck();
        BeanUtil.copyProperties(dto, finPayableCheck);
        this.save(finPayableCheck);
        List<FinPayableCheckEntry> list = BeanUtil.copyToList(dto.getCheckPayableEntryList(),
            FinPayableCheckEntry.class);
        list.forEach(item -> item.setBillNo(dto.getBillNo()));
        finPayableCheckEntryService.saveBatch(list);
    }

    @Transactional(rollbackFor = Exception.class)
    @Override
    public void submitModify(CheckPayableDTO dto) {
        isAllowSubmit(dto);
        updateWithEntry(dto);
    }

    @Transactional(rollbackFor = Exception.class)
    @Override
    public void saveModify(CheckPayableDTO dto) {
        isEmpty(dto);
        updateWithEntry(dto);
    }

    private void updateWithEntry(CheckPayableDTO dto) {
        FinPayableCheck finPayableCheck = new FinPayableCheck();
        BeanUtil.copyProperties(dto, finPayableCheck);
        this.updateById(finPayableCheck);
        finPayableCheckEntryService.remove(new LambdaQueryWrapper<FinPayableCheckEntry>()
            .eq(FinPayableCheckEntry::getBillNo, dto.getBillNo()));
        List<FinPayableCheckEntry> list = BeanUtil.copyToList(dto.getCheckPayableEntryList(),
            FinPayableCheckEntry.class);
        list.forEach(item -> item.setBillNo(dto.getBillNo()));
        finPayableCheckEntryService.saveBatch(list);
    }

    @Transactional(rollbackFor = Exception.class)
    @Override
    public void removeWithEntry(List<String> ids) {
        this.removeByIds(ids);
        List<FinPayableCheck> list = this.listByIds(ids);
        List<String> billNos = list.stream().map(FinPayableCheck::getBillNo).collect(Collectors.toList());
        finPayableCheckEntryService.remove(new LambdaQueryWrapper<FinPayableCheckEntry>()
            .in(FinPayableCheckEntry::getBillNo, billNos));
    }

    private static void isEmpty(CheckPayableDTO dto) {
        // 判空
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
            b1 = b1.add(item.getAmt());
        }
        // 比较是否一致
        if (b1.compareTo(b2) != 0) {
            throw new RuntimeException("上下核销不一致，无法提交！");
        }
    }
}
