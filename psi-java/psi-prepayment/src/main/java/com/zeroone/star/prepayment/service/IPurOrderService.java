package com.zeroone.star.prepayment.service;

import com.zeroone.star.prepayment.entity.PurOrder;

import java.util.List;

/**
 * PurOrder 服务类
 * author 狂踹瘸子那条好腿
 * since 2023-02-20
 */
public interface IPurOrderService {

    /**
     * 根据源单ID查询对应单据列表
     * @param srcBillID 源单ID
     * @return 查询结果
     */
    List<PurOrder> listBySrcBillId(String srcBillID);
}
