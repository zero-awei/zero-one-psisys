package com.zeroone.star.prepayment.service;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.query.prepayment.FinPaymentReqQuery;
import com.zeroone.star.project.query.prepayment.PurchaseListQuery;
import com.zeroone.star.prepayment.entity.FinPaymentReq;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.prepayment.FinPaymentReqVO;
import com.zeroone.star.project.vo.prepayment.ReqVO;
import org.springframework.stereotype.Component;

import java.util.List;

/**
 * <p>
 * 付款申请单 服务类
 * </p>
 *
 * @author zhd
 * @since 2023-02-18
 */
@Component
public interface IFinPaymentReqService extends IService<FinPaymentReq> {

    /**
     * 获取有申请采购单（分页）
     * param purchaseListQuery
     * return
     */
    PageVO<FinPaymentReqVO> getFinPaymentReq(PurchaseListQuery purchaseListQuery);

    /**
     * 根据明细的源单id查询对应申请单
     * @param srcBillId 源单id
     * @return 查询结果
     */
    FinPaymentReq getBySrcBillId(String srcBillId);


    /**
     * FinPaymentReq 服务类
     * TODO FinPaymentReqVO需要更换，新建ReqVO
     * author neigui
     * since 2023-02-18
     */
    PageVO<ReqVO> listFinPaymentReq(FinPaymentReqQuery query);

}
