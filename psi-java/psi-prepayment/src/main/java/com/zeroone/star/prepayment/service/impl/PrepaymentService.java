package com.zeroone.star.prepayment.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.prepayment.entity.FinPayment;
import com.zeroone.star.prepayment.entity.FinPaymentEntry;
import com.zeroone.star.prepayment.entity.FinPaymentReq;
import com.zeroone.star.prepayment.entity.PurOrder;
import com.zeroone.star.prepayment.mapper.FinPaymentMapper;
import com.zeroone.star.prepayment.service.*;
import com.zeroone.star.project.dto.prepayment.*;
import com.zeroone.star.project.query.prepayment.DocListQuery;
import com.zeroone.star.project.query.prepayment.PreDetQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.prepayment.*;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.util.List;

/**
 * 付款单 服务类
 * author forever爱
 * since 2023-02-13
 */
@Service
public class PrepaymentService extends ServiceImpl<FinPaymentMapper,FinPayment> implements IPrepaymentService {
    /**
     *
     * @param modifyDTO
     * @return
     * author forever爱
     */
    @Override
    public JsonVO<String> modifyById(ModifyDTO modifyDTO) {
        return null;
    }

    @Override
    public JsonVO<String> auditById(AuditDTO auditDTO) {
        return null;
    }

    @Override
    public JsonVO<PageVO<DocListVO>> queryAll(DocListQuery condition) {
        return null;
    }

    @Resource
    IFinPaymentService finPaymentService;
    @Resource
    IFinPaymentReqService finPaymentReqService;
    @Resource
    IFinPaymentEntryService finPaymentEntryService;
    @Override
    public DetHavVO queryByBillHav(PreDetQuery condition) {
        //根据查询条件里的单据编号去fin_payment查询对应付款单据
        FinPayment finPayment = finPaymentService.getByBillNo(condition.getBillNo());
        //根据fin_payment_entry表mid对应fin_payment中id查询对应明细,且对应fin_payment_req表
        FinPaymentEntry finPaymentEntry = finPaymentEntryService.getByMid(finPayment.getId(),"FinPaymentReq");
        //判空
        if(finPaymentEntry==null){
            DetHavVO detHavVO = new DetHavVO();
            BeanUtil.copyProperties(finPayment,detHavVO);
            return detHavVO;
        }
        //明细单中的src_bill_id对应申请单中的id查询对应申请单
        FinPaymentReq finPaymentReq = finPaymentReqService.getBySrcBillId(finPaymentEntry.getSrcBillId());
        FinPaymentReqVO finPaymentReqVO;
        FinPaymentEntryVO finPaymentEntryVO;
        //判空
        if(finPaymentReq==null){
            //将明细单传入VO
            finPaymentEntryVO = new FinPaymentEntryVO();
            BeanUtil.copyProperties(finPaymentEntry,finPaymentEntryVO);
            finPaymentReqVO=null;
        }else{
            //将对应参数拷贝到VO中
            finPaymentReqVO = new FinPaymentReqVO();
            BeanUtil.copyProperties(finPaymentReq,finPaymentReqVO);
            finPaymentEntryVO = new FinPaymentEntryVO();
            BeanUtil.copyProperties(finPaymentEntry,finPaymentEntryVO);
            finPaymentEntryVO.setSrcBillNo(finPaymentReq.getBillNo());
        }
        DetHavVO detHavVO = new DetHavVO();
        BeanUtil.copyProperties(finPayment,detHavVO);
        detHavVO.setReq(finPaymentReqVO);
        detHavVO.setDetail(finPaymentEntryVO);
        return detHavVO;
    }

    @Resource
    IPurOrderService purOrderService;
    @Override
    public DetNoVO queryByBillNo(PreDetQuery condition) {
        //根据查询条件里的单据编号去fin_payment查询对应付款单据
        FinPayment finPayment = finPaymentService.getByBillNo(condition.getBillNo());
        //根据fin_payment_entry表mid对应fin_payment中id查询对应明细，且对应Pur_Order
        FinPaymentEntry finPaymentEntry = finPaymentEntryService.getByMid(finPayment.getId(),"PurOrder");
        //判空
        if(finPaymentEntry==null){
            DetNoVO detNoVO = new DetNoVO();
            BeanUtil.copyProperties(finPayment,detNoVO);
            return detNoVO;
        }
        //明细单中的src_bill_id对应申请单中的id查询对应采购单
        PurOrder purOrder = purOrderService.getBySrcBillId(finPaymentEntry.getSrcBillId());
        PurOrderVO purOrderVO;
        FinPaymentEntryVO finPaymentEntryVO;
        //判空
        if(purOrder==null){
            //将明细单传入VO
            finPaymentEntryVO = new FinPaymentEntryVO();
            BeanUtil.copyProperties(finPaymentEntry,finPaymentEntryVO);
            purOrderVO=null;
        }else {
            //将对应参数拷贝到VO中
            purOrderVO = new PurOrderVO();
            BeanUtil.copyProperties(purOrder,purOrderVO);
            finPaymentEntryVO = new FinPaymentEntryVO();
            BeanUtil.copyProperties(finPaymentEntry,finPaymentEntryVO);
            finPaymentEntryVO.setSrcBillNo(purOrder.getBillNo());
        }
        DetNoVO detNoVO = new DetNoVO();
        BeanUtil.copyProperties(finPayment,detNoVO);
        detNoVO.setDetail(finPaymentEntryVO);
        detNoVO.setPurOrder(purOrderVO);
        return detNoVO;
    }

    @Override
    public ResponseEntity<byte[]> download() {
        return null;
    }

    @Override
    public JsonVO<String> downloadUrl() {
        return null;
    }

    @Override
    public JsonVO<String> deleteById(DeleteDTO deleteDTO) {
        return null;
    }

    @Override
    public JsonVO<String> prepaymentForPurchaseRequisitions(PrepaymentDTO prepaymentDTO) {
        return null;
    }

    @Override
    public JsonVO<List<SupplierVO>> querySupplierList() {
        return null;
    }

    @Override
    public JsonVO<PageVO<PaymentReqEntryVO>> queryAllByBillNo(String billNo) {
        return null;
    }

    @Override
    public JsonVO<String> excelImport(MultipartFile file) {
        return null;
    }

    @Override
    public JsonVO<String> closeById(StatusDTO statusDTO) {
        return null;
    }

    @Override
    public JsonVO<String> uncloseById(StatusDTO statusDTO) {
        return null;
    }

    @Override
    public JsonVO<String> voidById(StatusDTO statusDTO) {
        return null;
    }
}
