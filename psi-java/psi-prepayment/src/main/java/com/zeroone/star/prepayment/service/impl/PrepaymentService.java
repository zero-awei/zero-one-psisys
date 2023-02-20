package com.zeroone.star.prepayment.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.prepayment.entity.FinPayment;
import com.zeroone.star.prepayment.entity.FinPaymentEntry;
import com.zeroone.star.prepayment.mapper.FinPaymentEntryMapper;
import com.zeroone.star.prepayment.mapper.FinPaymentMapper;
import com.zeroone.star.prepayment.service.IFinPaymentEntryService;
import com.zeroone.star.prepayment.service.IFinPaymentReqService;
import com.zeroone.star.prepayment.service.IFinPaymentService;
import com.zeroone.star.prepayment.service.IPrepaymentService;
import com.zeroone.star.project.dto.prepayment.*;
import com.zeroone.star.project.query.prepayment.DocListQuery;
import com.zeroone.star.project.query.prepayment.IdQuery;
import com.zeroone.star.project.query.prepayment.PreDetQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.prepayment.*;
import org.springframework.beans.BeanUtils;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.util.List;
import java.util.stream.Collectors;

/**
 * 付款单 服务类
 * author forever爱
 * since 2023-02-13
 */
@Service
public class PrepaymentService extends ServiceImpl<FinPaymentEntryMapper, FinPaymentEntry> implements IPrepaymentService {

    @Resource
    IFinPaymentService finPaymentService;
    @Resource
    IFinPaymentReqService finPaymentReqService;
    @Resource
    IFinPaymentEntryService finPaymentEntryService;
    /**
     * 修改采购预付单
     * 步骤：
     *  1、finPayment表   数据修改
     *  2、finPaymentEntry表 数据修改
     *  3、判断是
     *  3、finPaymentEntry表 插入数据列表
     *  4、判断是否成功，如果成功
     *  5、如果失败
     * param modifyDTO 修改DTO
     * return
     * author forever爱
     */
    @Override
    @Transactional
    public JsonVO<String> modifyById(ModifyDTO modifyDTO) {
        //1、finPayment表中数据修改
        finPaymentService.updateById(modifyDTO);
        //2、finPaymentEntry表中数据修改
        boolean flag = finPaymentEntryService.updateById(modifyDTO);
        //3、判断成功还是失败
        if (flag){
            return JsonVO.success("修改成功");
        }
        return JsonVO.fail("修改失败");
    }

    /**
     * 审核采购预付单功能
     * author forever爱
     * since 2023-02-13
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
