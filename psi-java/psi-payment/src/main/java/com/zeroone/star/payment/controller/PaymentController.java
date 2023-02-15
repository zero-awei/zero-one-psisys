package com.zeroone.star.payment.controller;

import com.zeroone.star.project.dto.payment.AuditDTO;
import com.zeroone.star.project.dto.payment.ModifyDTO;
import com.zeroone.star.project.payment.PaymentApis;
import com.zeroone.star.project.query.payment.PreDetQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payment.DetHavVO;
import com.zeroone.star.project.vo.payment.DetNoVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import com.zeroone.star.project.query.payment.DocListQuery;
import com.zeroone.star.project.vo.payment.DocListVO;
import com.zeroone.star.project.dto.payment.DeleteDTO;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import com.zeroone.star.project.dto.payment.PrepaymentDTO;
import com.zeroone.star.project.payment.PaymentApis;
import com.zeroone.star.project.query.payment.PurchaseListQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payment.FinPaymentReqVO;
import com.zeroone.star.project.vo.payment.PurOrderEntryVO;
import com.zeroone.star.project.vo.payment.SupplierVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("payment")
@Api(tags = "预付模块")
public class PaymentController implements PaymentApis {
    /**
     * 修改采购预付单功能
     * author forever爱
     * since 2023-02-13
     */
    @PutMapping("edit")
    @ApiOperation(value = "修改采购预付单功能")
    @Override
    public JsonVO<String> modifyById(ModifyDTO modifyDTO) {
        return JsonVO.success("1111");
    }

    /**
     * 审核采购预付单功能
     * author forever爱
     * since 2023-02-13
     */
    @PutMapping("audit")
    @ApiOperation(value = "审核采购预付单功能")
    @Override
    public JsonVO<String> auditById(AuditDTO auditDTO) {
        return JsonVO.success("1111");
    }

    /**
     * 单据查询 前端控制器
     * author husj
     * since 2023-02-13
     */
    @Override
    @GetMapping("query-all")
    @ApiOperation(value = "按照条件实现单据查询")
    public JsonVO<PageVO<DocListVO>> queryAll(DocListQuery condition) {
        return null;
    }

    /**
     * 根据单据编号查询信息
     * author hzp
     * since 2023-02-13
     */
    @GetMapping("/detHav")
    @ApiOperation(value = "有申请详情信息")
    @Override
    public JsonVO<DetHavVO> queryByBillHav(PreDetQuery condition) {
        return JsonVO.success(new DetHavVO());
    }

    @GetMapping("/detNo")
    @ApiOperation(value = "无申请详情信息")
    @Override
    public JsonVO<DetNoVO> queryByBillNo(PreDetQuery condition) {
        return JsonVO.success(new DetNoVO());
    }

    /**
     * 导出功能实现
     * author 明破
     * since 2023-02-13
     */
    @GetMapping("export")
    @ApiOperation(value = "获取导出文件")
    @Override
    public ResponseEntity<byte[]> download() {
        return null;
    }

    @ApiOperation(value = "获取导出链接")
    @Override
    public JsonVO<String> downloadUrl() {
        return null;
    }

    /**
     * 删除
     * author 出运费
     * since 2023-02-13
     */
    @DeleteMapping("delete")
    @ApiOperation(value = "删除信息")
    @Override
    public JsonVO<String> deleteById(DeleteDTO deleteDTO) {
        return JsonVO.success("删除成功");

    }

    /**
     * 添加
     * author 空
     * since 2023-02-13
     */
    @PutMapping("insert-prepayment")
    @ApiOperation(value = "预付款操作")
    @Override
    public JsonVO<String> prepaymentForPurchaseRequisitions(PrepaymentDTO prepaymentDTO) {
        return null;
    }

    @PutMapping("getSuppliers")
    @ApiOperation(value = "获取供应商")
    @Override
    public JsonVO<List<SupplierVO>> querySupplierList() {
        return null;
    }



    @GetMapping("list-purhcaserequisitions")
    @ApiOperation(value = "获取采购清单（有申请）")
    @Override
    public JsonVO<PageVO<FinPaymentReqVO>> queryForAppliedPurchaseRequisitions(PurchaseListQuery purchaseListQuery) {
        return null;
    }

    @GetMapping("list-purhcaserequisitions")
    @ApiOperation(value = "获取采购清单（无申请）")
    @Override
    public JsonVO<PageVO<PurOrderEntryVO>> queryForPurchaseRequisitions(PurchaseListQuery purchaseListQuery) {
        return null;
    }
}
