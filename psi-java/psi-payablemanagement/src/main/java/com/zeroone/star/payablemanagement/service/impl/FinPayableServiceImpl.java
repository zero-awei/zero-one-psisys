package com.zeroone.star.payablemanagement.service.impl;

import cn.hutool.core.bean.BeanUtil;
import org.springframework.context.annotation.Bean;
import com.zeroone.star.project.query.payablemanagement.PayableBillNoQuery;
import com.alibaba.nacos.common.utils.StringUtils;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.payablemanagement.entity.FinPayable;
import com.zeroone.star.payablemanagement.mapper.FinPayableMapper;
import com.zeroone.star.payablemanagement.service.IFinPayableService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.query.payablemanagement.PayableQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payablemanagement.PayableVO;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 应付单 服务实现类
 * </p>
 *
 * @author chosen1, G.
 * @since 2023-02-14
 */
@Service
public class FinPayableServiceImpl extends ServiceImpl<FinPayableMapper, FinPayable> implements IFinPayableService {

    @Override
    public PageVO<PayableVO> getAll(PayableQuery query) {
        Page<FinPayable> payablePage = new Page<>(query.getPageIndex(), query.getPageSize());
        QueryWrapper<FinPayable> wrapper = new QueryWrapper<>();
        // TODO 编写wrapper、mapper
        Page<FinPayable> result = baseMapper.selectPage(payablePage, wrapper);
        return PageVO.create(result, PayableVO.class);
    }

    @Override
    public PayableVO getByBillNO(PayableBillNoQuery query) {
        QueryWrapper<FinPayable> wrapper = new QueryWrapper<>();
        wrapper.eq("bill_no", query.getBillNO());
        FinPayable finPayable = baseMapper.selectOne(wrapper);
        PayableVO payableVO = new PayableVO();
        // TODO 待完成 编写wrapper mapper
        BeanUtil.copyProperties(finPayable, payableVO);
        return payableVO;
    }


    public PageVO<PayableVO> queryAll(PayableQuery query) {
        // 构建分页对象
        Page<FinPayable> finPayablePage = new Page<>(query.getPageIndex(), query.getPageSize());
        // 构建查询条件
        QueryWrapper<FinPayable> finPayableQueryWrapper = new QueryWrapper<>();
        // 1.单据编号查询
        finPayableQueryWrapper.eq(StringUtils.hasText(query.getBillNo()), "bill_no", query.getBillNo());
        // 2.单据日期查询
        if(query.getBillDateBegin() != null){
            // 条件为空时，报空指针异常，换为if判断
            //finPayableQueryWrapper.ge(StringUtils.hasText(query.getBillDate_begin().toString()),"bill_date", query.getBillDate_begin());
            //finPayableQueryWrapper.le(StringUtils.hasText(query.getBillDate_end().toString()),"bill_date", query.getBillDate_end());
            finPayableQueryWrapper.ge("bill_date", query.getBillDateBegin());
        }
        if(query.getBillDateEnd() != null){
            finPayableQueryWrapper.le("bill_date", query.getBillDateEnd());
        }
        // 3.单据主题查询
        finPayableQueryWrapper.eq(StringUtils.hasText(query.getSubject()), "subject", query.getSubject());
        // 4.供应商查询
        finPayableQueryWrapper.eq(StringUtils.hasText(query.getSupplierId()), "supplier_id", query.getSupplierId());
        // 5.单据阶段查询
        finPayableQueryWrapper.eq(StringUtils.hasText(query.getBillStage()), "bill_stage", query.getBillStage());
        // 6.已生效(与日期查询问题一样，换为if判断)
        if(query.getIsEffective() != null){
            finPayableQueryWrapper.eq("is_effective", query.getIsEffective());
        }
        // 7.已关闭
        if(query.getIsClosed() != null){
            finPayableQueryWrapper.eq("is_closed", query.getIsClosed());
        }
        // 8.已作废
        if(query.getIsVoided() != null){
            finPayableQueryWrapper.eq("is_voided", query.getIsVoided());
        }
        // 执行分页查询
        Page<FinPayable> result = baseMapper.selectPage(finPayablePage, finPayableQueryWrapper);
        return PageVO.create(result,PayableVO.class);
    }

    @Override
    public PayableVO getByBillNo(String billNo) {
        // 构建查询条件
        QueryWrapper<FinPayable> wrapper = new QueryWrapper<>();
        wrapper.eq("bill_no", billNo);
        // 执行查询
        FinPayable f = baseMapper.selectOne(wrapper);
        // 返回结果
        if(f == null){
            return null;
        }
        PayableVO payableVO = new PayableVO();
        BeanUtil.copyProperties(f, payableVO);
        return payableVO;
    }
}
