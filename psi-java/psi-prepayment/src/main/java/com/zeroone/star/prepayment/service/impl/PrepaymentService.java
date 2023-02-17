package com.zeroone.star.prepayment.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.zeroone.star.prepayment.entity.FinPayment;
import com.zeroone.star.prepayment.mapper.FinPaymentEntryMapper;
import com.zeroone.star.prepayment.mapper.FinPaymentMapper;
import com.zeroone.star.prepayment.service.IPrepaymentService;
import com.zeroone.star.project.dto.prepayment.*;
import com.zeroone.star.project.query.prepayment.DocListQuery;
import com.zeroone.star.project.query.prepayment.IdQuery;
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
public class PrepaymentService implements IPrepaymentService {

    @Resource
    private FinPaymentMapper finPaymentMapper;
    @Resource
    private FinPaymentEntryMapper finPaymentEntryMapper;

    /**
     * 修改采购预付单
     * param modifyDTO 修改DTO
     * return
     * author forever爱
     */
    @Override
    public JsonVO<String> modifyById(ModifyDTO modifyDTO) {
        //1、finPayment表中数据修改
        FinPayment finPayment = new FinPayment();
        BeanUtil.copyProperties(modifyDTO, finPayment);
        int i = finPaymentMapper.updateById(finPayment);
        //2、finPaymentEntry表中数据修改
        //3、判断如果成功，返回“成功”
        if (i > 0){
            return JsonVO.success("修改成功");
        }
        //4、判断如果失败，返回“失败”
        return JsonVO.fail("修改失败");
    }

    /**
     * 审核采购预付单
     * param auditDTO 审核DTO
     * return
     * author forever爱
     */
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
