package com.zeroone.star.prepayment.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.prepayment.entity.FinPayment;
import com.zeroone.star.prepayment.entity.FinPaymentEntry;
import com.zeroone.star.prepayment.entity.FinPaymentReq;
import com.zeroone.star.prepayment.mapper.FinPaymentMapper;
import com.zeroone.star.prepayment.service.IFinPaymentEntryService;
import com.zeroone.star.prepayment.service.IFinPaymentReqService;
import com.zeroone.star.prepayment.service.IFinPaymentService;
import com.zeroone.star.prepayment.service.IPrepaymentService;
import com.zeroone.star.project.dto.prepayment.*;
import com.zeroone.star.project.query.prepayment.DocListQuery;
import com.zeroone.star.project.query.prepayment.PreDetQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.prepayment.*;
import org.apache.poi.ss.formula.functions.T;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.util.ArrayList;
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
        FinPayment finPayment = finPaymentService.selectByBillNo(condition.getBillNo());
        List<FinPaymentReq> finPaymentReqs = finPaymentReqService.listBySrcBillId(finPayment.getId());
        List<FinPaymentReqVO> finPaymentReqVOList = new ArrayList<>();
        List<FinPaymentEntryVO> finPaymentEntryVOList = new ArrayList<>();
        for (FinPaymentReq finPaymentReq : finPaymentReqs) {
            FinPaymentEntry finPaymentEntry = finPaymentEntryService.selectByBillNo(finPaymentReq.getBillNo());
            FinPaymentReqVO finPaymentReqVO = new FinPaymentReqVO();
            BeanUtil.copyProperties(finPaymentReq,finPaymentReqVO);
            finPaymentReqVOList.add(finPaymentReqVO);
            FinPaymentEntryVO finPaymentEntryVO = new FinPaymentEntryVO();
            BeanUtil.copyProperties(finPaymentEntry,finPaymentEntryVO);
            finPaymentEntryVOList.add(finPaymentEntryVO);
        }
        DetHavVO detHavVO = new DetHavVO();
        BeanUtil.copyProperties(finPayment,detHavVO);
        detHavVO.setListReq(finPaymentReqVOList);
        detHavVO.setListDetail(finPaymentEntryVOList);
        return detHavVO;
    }

    @Override
    public DetNoVO queryByBillNo(PreDetQuery condition) {
        return null;
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
