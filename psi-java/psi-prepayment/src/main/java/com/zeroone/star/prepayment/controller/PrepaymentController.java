package com.zeroone.star.prepayment.controller;

import com.zeroone.star.prepayment.service.IFinPaymentReqService;
import com.zeroone.star.prepayment.service.IFinPaymentService;
import com.zeroone.star.prepayment.service.IPrepaymentService;
import com.zeroone.star.project.dto.prepayment.*;
import com.zeroone.star.project.prepayment.PrepaymentApis;
import com.zeroone.star.project.query.prepayment.FinPaymentReqQuery;
import com.zeroone.star.project.query.prepayment.PreDetQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.prepayment.*;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import com.zeroone.star.project.query.prepayment.DocListQuery;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.bind.annotation.GetMapping;
import java.util.List;

import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;


@RestController
@RequestMapping("prepayment")
@Api(tags = "预付模块")
public class PrepaymentController implements PrepaymentApis {

    @Resource
    IPrepaymentService service;

    @Resource
    IFinPaymentReqService paymentReqService;

    @Resource
    IFinPaymentService paymentService;

    /**
     * 修改采购预付单功能
     * author forever爱
     * since 2023-02-13
     */
    @PutMapping("edit")
    @ApiOperation(value = "修改采购预付单功能（返回值data值表示更新成功与否）")
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
    @ApiOperation(value = "审核采购预付单功能（返回值data值表示更新成功与否）")
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
    @ApiOperation(value = "查询采购预付单功能")
    public JsonVO<PageVO<DocListVO>> queryAll(DocListQuery condition) {
        return null;
    }

    /**
     * 根据单据编号查询信息
     * author hzp
     * since 2023-02-13
     */
    @GetMapping("query-one-hav")
    @ApiOperation(value = "查看单据详情信息（有申请）")
    @Override
    public JsonVO<DetHavVO> queryByBillHav(PreDetQuery condition) {
        return JsonVO.success(service.queryByBillHav(condition));
    }

    @GetMapping("query-one-no")
    @ApiOperation(value = "查看单据详情信息（无申请）")
    @Override
    public JsonVO<DetNoVO> queryByBillNo(PreDetQuery condition) {
        return JsonVO.success(service.queryByBillNo(condition));
    }

    /**
     * 导出功能实现
     * author 明破
     * since 2023-02-13
     */
    @GetMapping("export")
    @ApiOperation(value = "导出功能")
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
    @ApiOperation(value = "删除信息（返回值data值表示删除成功与否）")
    @Override
    public JsonVO<String> deleteById(DeleteDTO deleteDTO) {
        return JsonVO.success("删除成功");

    }

    /**
     * 添加
     * author 空
     * since 2023-02-13
     */
    @PostMapping("insert")
    @ApiOperation(value = "添加采购预付单功能（返回值data值表示创建成功与否）")
    @Override
    public JsonVO<String> prepaymentForPurchaseRequisitions(PrepaymentDTO prepaymentDTO) {
        return null;
    }

    @GetMapping("getSuppliers")
    @ApiOperation(value = "获取供应商列表")
    @Override
    public JsonVO<List<SupplierVO>> querySupplierList() {
        return null;
    }



//    @GetMapping("list-purhcaserequisitions")
//    @ApiOperation(value = "获取采购清单（有申请）")
//    @Override
//    public JsonVO<PageVO<FinPaymentReqVO>> queryForAppliedPurchaseRequisitions(PurchaseListQuery purchaseListQuery) {
//        return null;
//    }
//
//    @GetMapping("list-purhcaserequisitions")
//    @ApiOperation(value = "获取采购清单（无申请）")
//    @Override
//    public JsonVO<PageVO<PurOrderEntryVO>> queryForPurchaseRequisitions(PurchaseListQuery purchaseListQuery) {
//        return null;
//    }

    /**
     * 付款申请单分录明细列表查询
     * param supplierName 供应商名
     * return 分录明细列表
     * author 内鬼
     */
    @Override
    @GetMapping("query-all-paymentReq")
    @ResponseBody
    @ApiOperation("付款申请单分录列表查询")
    public JsonVO<PageVO<FinPaymentReqVO>> queryAllReq(FinPaymentReqQuery query) {
        PageVO<FinPaymentReqVO> paymentReqEntryPage = paymentReqService.listFinPaymentReq(query);
        return JsonVO.success(paymentReqEntryPage);
    }

    /**
     * Excel 表格导入
     * param file Excel 文件
     * return 处理结果
     * author 内鬼
     */
    @Override
    @PostMapping("import-payments-excel")
    @ResponseBody
    @ApiOperation("导入功能（返回值data值表示导入成功与否）")
    public JsonVO<String> excelImport(@RequestParam("file") MultipartFile file) {
        try {
            paymentService.importExcelOfPayment(file);
        } catch (Exception e) {
            e.printStackTrace();
            return JsonVO.fail("文件导入失败");
        }
        return JsonVO.success("文件导入成功！");
    }

    /**
     * 修改状态
     * author yu-hang
     */
    @Override
    @PutMapping("close")
    @ApiOperation(value = "关闭操作（返回值data值表示更新成功与否）")
    public JsonVO<String> closeById(StatusDTO statusDTO) {
        return null;
    }

    @PutMapping("unclose")
    @ApiOperation(value = "反关闭操作（返回值data值表示更新成功与否）")
    @Override
    public JsonVO<String> uncloseById(StatusDTO statusDTO) {
        return null;
    }

    @Override
    @PutMapping("void")
    @ApiOperation(value = "作废操作（返回值data值表示更新成功与否）")
    public JsonVO<String> voidById(StatusDTO statusDTO) {
        return null;
    }
}
