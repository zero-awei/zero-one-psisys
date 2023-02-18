package com.zeroone.star.prepayment.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.prepayment.entity.FinPaymentReq;
import com.zeroone.star.prepayment.mapper.FinPaymentReqMapper;
import com.zeroone.star.prepayment.service.IFinPaymentReqService;
import com.zeroone.star.project.query.prepayment.PurchaseListQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.prepayment.FinPaymentReqVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

/**
 * @Author: Kong
 * @License: (C) Copyright 2005-2019, xxx Corporation Limited.
 * @Contact: xxx@xxx.com
 * @Date: 2023-02-18 15:14
 * @Version: 1.0
 * @Description:
 */
@Service
public class FinPaymentReqServiceImpl extends ServiceImpl<FinPaymentReqMapper, FinPaymentReq> implements IFinPaymentReqService {

    @Autowired
    FinPaymentReqMapper finPaymentReqMapper;

    @Override
    public PageVO<FinPaymentReqVO> getFinPaymentReq(PurchaseListQuery condition) {
        //分页对象
        Page<FinPaymentReq> page = new Page<>(condition.getPageIndex(),condition.getPageSize());
        QueryWrapper<FinPaymentReq> wrapper = new QueryWrapper<>();
        wrapper.eq("payment_type",condition.getSelf_payment_type())
                .eq("is_closed",condition.getSelf_is_closed())
                .eq("supplier_id",condition.getSelf_supplier_id());
        //执行分页查询
        Page<FinPaymentReq> res = finPaymentReqMapper.selectPage(page, wrapper);
        return PageVO.create(res,FinPaymentReqVO.class);
    }


}