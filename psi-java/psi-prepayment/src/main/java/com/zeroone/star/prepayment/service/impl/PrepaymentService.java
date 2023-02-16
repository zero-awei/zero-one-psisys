package com.zeroone.star.prepayment.service.impl;

import com.zeroone.star.prepayment.service.IPrepaymentService;
import com.zeroone.star.project.dto.prepayment.*;
import com.zeroone.star.project.query.prepayment.DocListQuery;
import com.zeroone.star.project.query.prepayment.PreDetQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.prepayment.*;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

/**
 * 付款单 服务类
 * author forever爱
 * since 2023-02-13
 */
@Service
public class PrepaymentService implements IPrepaymentService {
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

    @Override
    public JsonVO<DetHavVO> queryByBillHav(PreDetQuery condition) {
        return null;
    }

    @Override
    public JsonVO<DetNoVO> queryByBillNo(PreDetQuery condition) {
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
