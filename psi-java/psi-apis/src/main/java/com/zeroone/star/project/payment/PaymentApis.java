package com.zeroone.star.project.payment;

import com.zeroone.star.project.dto.payment.PrepaymentDTO;
import com.zeroone.star.project.query.payment.PurchaseListQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payment.FinPaymentReqVO;
import com.zeroone.star.project.vo.payment.PurOrderEntryVO;
import com.zeroone.star.project.vo.payment.SupplierVO;

import java.util.List;

/**
 * <p>
 * 描述：预付款操作
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author forever爱
 * @version 1.0.0
 */

public interface PaymentApis {

    //TODO 附件上传
    /**
     * 采购预付款操作
     * @param prepaymentDTO
     * @return
     */
    public JsonVO<String> prepaymentForPurchaseRequisitions(PrepaymentDTO prepaymentDTO);

    /**
     * 获取供应商列表
     * @return 供应商列表
     */
    public JsonVO<List<SupplierVO>> querySupplierList();

    /**
     * 获取采购项目清单（无申请）
     * @param purchaseListQuery
     * @return 采购项目清单
     */
    public JsonVO<PageVO<PurOrderEntryVO>> queryForPurchaseRequisitions(PurchaseListQuery purchaseListQuery);

    /**
     * 获取采购项目清单（有申请）
     * @param purchaseListQuery
     * @return 采购项目清单
     */
    public JsonVO<PageVO<FinPaymentReqVO>> queryForAppliedPurchaseRequisitions(PurchaseListQuery purchaseListQuery);
}
