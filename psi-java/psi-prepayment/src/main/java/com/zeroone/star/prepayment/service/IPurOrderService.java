package com.zeroone.star.prepayment.service;

import com.zeroone.star.prepayment.entity.PurOrder;


/**
 * PurOrder 服务类
 * author 狂踹瘸子那条好腿
 * since 2023-02-20
 */
public interface IPurOrderService {

    /**
     * 根据明细的源单id查询对应采购单
     * @param srcBillId 源单ID
     * @return 查询结果
     */
    PurOrder getBySrcBillId(String srcBillId);

}
