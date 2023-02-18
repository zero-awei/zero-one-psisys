package com.zeroone.star.prepayment.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.prepayment.entity.FinPayment;
import com.zeroone.star.prepayment.entity.FinPaymentEntry;
import com.zeroone.star.prepayment.mapper.FinPaymentEntryMapper;
import com.zeroone.star.prepayment.mapper.FinPaymentMapper;
import com.zeroone.star.prepayment.service.IPrepaymentService;
import com.zeroone.star.project.dto.prepayment.*;
import com.zeroone.star.project.query.prepayment.DocListQuery;
import com.zeroone.star.project.query.prepayment.PreDetQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.prepayment.*;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
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
    FinPaymentMapper finPaymentMapper;

    @Resource
    FinPaymentEntryMapper finPaymentEntryMapper;

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
    @Transactional(rollbackFor = Exception.class)
    public JsonVO<String> deleteById(DeleteDTO deleteDTO) throws Exception {

//        //(不清楚具体数字代表什么处理状态 所以这一步先省略)
//        //获取处理状态
//        String billStage = finPaymentMapper.selectById(deleteDTO.getId()).getBillStage();
//        if (billStage != "编制中"){
//            return JsonVO.fail("单据不能做该操作，可能被其他用户改变了状态！");
//        }
        int i = finPaymentMapper.deleteById(deleteDTO.getId());
        int mid = finPaymentEntryMapper.delete(new QueryWrapper<FinPaymentEntry>().eq("mid", deleteDTO.getId().toString()));
        if (i > 0&&mid > 0){
            return JsonVO.success("删除成功！");
        }else {
            throw new Exception("删除失败！");
        }
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
