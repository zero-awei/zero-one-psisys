package com.zeroone.star.prepayment.service;
import com.zeroone.star.prepayment.entity.PurOrder;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.query.prepayment.PurchaseListQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.prepayment.PurOrderVO;

import com.zeroone.star.project.query.prepayment.PurchaseListQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.prepayment.PurOrderVO;
import org.springframework.stereotype.Component;

/**
 * <p>
 * 采购订单 服务类
 * </p>
 *
 * @author zhd
 * @since 2023-02-18
 */
@Component
public interface IPurOrderService extends IService<PurOrder> {

    /**
     * 获取无申请采购单（分页）
     * param condition 查询条件
     * return 无申请采购单
     * author KONG
     */
    public PageVO<PurOrderVO> getPurOrder(PurchaseListQuery condition);

    /**
     * 根据明细的源单id查询对应采购单
     * param srcBillId 源单ID
     * return 查询结果
     * author hzp
     */
    PurOrder getBySrcBillId(String srcBillId);

}
