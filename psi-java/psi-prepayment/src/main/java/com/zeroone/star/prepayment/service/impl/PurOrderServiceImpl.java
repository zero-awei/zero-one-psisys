package com.zeroone.star.prepayment.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.prepayment.entity.PurOrder;
import com.zeroone.star.prepayment.mapper.PurOrderMapper;
import com.zeroone.star.prepayment.service.IPurOrderService;
import com.zeroone.star.project.query.prepayment.PurchaseListQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.prepayment.PurOrderVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

/**
 * @Author: Kong
 * @License: (C) Copyright 2005-2019, xxx Corporation Limited.
 * @Contact: xxx@xxx.com
 * @Date: 2023-02-20 19:36
 * @Version: 1.0
 * @Description: 无申请采购单表
 */
@Service
public class PurOrderServiceImpl implements IPurOrderService {

    @Autowired
    PurOrderMapper purOrderMapper;

    @Override
    public PageVO<PurOrderVO> getPurOrder(PurchaseListQuery condition) {
        Page<PurOrder> purOrderPage = new Page<>(condition.getPageIndex(), condition.getPageSize());
        QueryWrapper<PurOrder> wrapper = new QueryWrapper<>();
        wrapper.eq("supplier_id",condition.getSelf_supplier_id());
//        if (condition.getSelf_payment_type()!=null){
//            wrapper.eq("payment_type",condition.getSelf_payment_type());
//        }
        if (condition.getSelf_is_closed()!=null){
            wrapper.eq("is_closed",condition.getSelf_is_closed());
        }
        Page<PurOrder> purOrder= purOrderMapper.selectPage(purOrderPage, wrapper);
        return PageVO.create(purOrder,PurOrderVO.class);
    }
}