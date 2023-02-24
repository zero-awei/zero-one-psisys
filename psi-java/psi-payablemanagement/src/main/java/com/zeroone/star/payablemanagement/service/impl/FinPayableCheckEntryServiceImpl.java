package com.zeroone.star.payablemanagement.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.payablemanagement.entity.FinPayable;
import com.zeroone.star.payablemanagement.entity.FinPayableCheckEntry;
import com.zeroone.star.payablemanagement.mapper.FinPayableCheckEntryMapper;
import com.zeroone.star.payablemanagement.service.IFinPayableCheckEntryService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.payablemanagement.service.IFinPayableService;
import com.zeroone.star.project.query.payablemanagement.CheckPayableEntryQuery;
import com.zeroone.star.project.vo.payablemanagement.CheckPayableEntryVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.math.BigDecimal;
import java.util.List;
import java.util.stream.Collectors;

/**
 * <p>
 * 应付核销明细 服务实现类
 * </p>
 *
 * @author j3
 * @since 2023-02-14
 */
@Service
public class FinPayableCheckEntryServiceImpl extends ServiceImpl<FinPayableCheckEntryMapper, FinPayableCheckEntry> implements IFinPayableCheckEntryService {


    static IFinPayableService finPayableService = new FinPayableServiceImpl();

    @Override
    public List<CheckPayableEntryVO> getByMainId(CheckPayableEntryQuery query) {
        //构建查询条件
        QueryWrapper<FinPayableCheckEntry> wrapper = new QueryWrapper<>();
        //根据Id查询
        wrapper.eq("mid", query.getId());
        //执行查询
        List<FinPayableCheckEntry> result = baseMapper.selectList(wrapper);
        return createCheckPayableEntryVOS(result);
    }

    /**
     * TODO 得到uncheckAmt，基于Payable表中的checkedAmt和Amt，查询
     * 并返回VOS
     */
    private static List<CheckPayableEntryVO> createCheckPayableEntryVOS(List<FinPayableCheckEntry> entries) {
        List<CheckPayableEntryVO> result = entries.stream().map(finPayableCheckEntry -> {
            //构建VO
            CheckPayableEntryVO checkPayableEntryVO = new CheckPayableEntryVO();
            //查询对应PayableVO
//            FinPayable byId = finPayableService.getById(finPayableCheckEntry.getSrcBillId());

            //构建查询条件
//            QueryWrapper<FinPayable> wrapper = new QueryWrapper<>();
//            //根据源单Id查询
//            wrapper.eq("src_bill_id", finPayableCheckEntry.getId());
//            //执行查询
//            FinPayable finPayable = finPayableService.getBaseMapper().selectOne(wrapper);
//            //得到checkedAmt
//            BigDecimal checkedAmt = finPayable.getCheckedAmt();
//            //得到Amt
//            BigDecimal amt = finPayableCheckEntry.getAmt();
//            //得到unCheckedAmt
//            BigDecimal unCheckedAmt = BigDecimal.valueOf(0.00);
//            if (checkedAmt != null && amt != null) {
//                unCheckedAmt = amt.subtract(checkedAmt);
//            }
//            checkPayableEntryVO.setUncheckedAmt(unCheckedAmt);
            checkPayableEntryVO.setId(finPayableCheckEntry.getId());
            checkPayableEntryVO.setMid(finPayableCheckEntry.getMid());
            checkPayableEntryVO.setBillNo(finPayableCheckEntry.getBillNo());
            checkPayableEntryVO.setEntryNo(finPayableCheckEntry.getEntryNo());
            checkPayableEntryVO.setSrcBillType(finPayableCheckEntry.getSrcBillType());
            checkPayableEntryVO.setSrcBillId(finPayableCheckEntry.getSrcBillId());
            checkPayableEntryVO.setSrcEntryId(finPayableCheckEntry.getSrcEntryId());
            checkPayableEntryVO.setSrcNo(finPayableCheckEntry.getSrcNo());
            checkPayableEntryVO.setCheckSide(finPayableCheckEntry.getCheckSide());
            checkPayableEntryVO.setAmt(finPayableCheckEntry.getAmt());
            checkPayableEntryVO.setRemark(finPayableCheckEntry.getRemark());
            checkPayableEntryVO.setCustom1(finPayableCheckEntry.getCustom1());
            checkPayableEntryVO.setCustom2(finPayableCheckEntry.getCustom2());
            checkPayableEntryVO.setVersion(finPayableCheckEntry.getVersion());
            return checkPayableEntryVO;
        }).collect(Collectors.toList());

        return result;
    }
}
