package com.zeroone.star.paymentmanagement.service.impl;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.paymentmanagement.entity.FinPaymentReq;
import com.zeroone.star.paymentmanagement.mapper.FinPaymentReqMapper;
import com.zeroone.star.paymentmanagement.service.IFinPaymentReqService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.query.paymentmanagement.FinPaymentReqQuery;
import com.zeroone.star.project.vo.paymentmanagement.FinPaymentReqVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * <p>
 * 付款申请单 服务实现类
 * </p>
 *
 * @author pyramid
 * @since 2023-02-15
 */
@Service
public class FinPaymentReqServiceImpl extends ServiceImpl<FinPaymentReqMapper, FinPaymentReq> implements IFinPaymentReqService {
    @Autowired
    private FinPaymentReqMapper finPaymentReqMapper;
    /**
     * 付款申请列表查询
     *
     * @param condition 单据列表查询对象
     * @return 付款申请列表
     */
    @Override
    public Page<FinPaymentReqVO> queryAll(FinPaymentReqQuery condition) {
        Page<FinPaymentReq> page = new Page<>(1,10);
        return  finPaymentReqMapper.queryAll(page, condition.getBillNo(), condition.getBillDate(), condition.getSupplierId());
    }

    @Override
    public List<FinPaymentReq> test() {
        List<FinPaymentReq> finPaymentReqs = finPaymentReqMapper.selectList(null);
        return finPaymentReqs;
    }

}
