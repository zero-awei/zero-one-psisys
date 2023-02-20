package com.zeroone.star.prepayment.service;

import com.zeroone.star.project.query.prepayment.PurchaseListQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.prepayment.PurOrderVO;

/**
 * @Author: xxx
 * @License: (C) Copyright 2005-2019, xxx Corporation Limited.
 * @Contact: xxx@xxx.com
 * @Date: 2023-02-20 19:36
 * @Version: 1.0
 * @Description:
 */

public interface IPurOrderService {
    /**
     * 获取无申请采购单（分页）
     * @param condition 查询条件
     * @return 无申请采购单
     */
    public PageVO<PurOrderVO> getPurOrder(PurchaseListQuery condition);
}