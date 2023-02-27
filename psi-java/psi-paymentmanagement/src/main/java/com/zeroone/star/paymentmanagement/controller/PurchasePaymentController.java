package com.zeroone.star.paymentmanagement.controller;

import com.baomidou.mybatisplus.extension.plugins.pagination.PageDTO;
import com.zeroone.star.paymentmanagement.service.PurchasePaymentService;
import com.zeroone.star.project.dto.paymentmanagement.purchasepayment.PaymentCreateDTO;
import com.zeroone.star.project.dto.paymentmanagement.purchasepayment.PaymentDeleteDTO;
import com.zeroone.star.project.dto.paymentmanagement.purchasepayment.PaymentUpdateDTO;
import com.zeroone.star.project.paymentmanagement.purchasepayment.PurchasePaymentApis;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.paymentmanagement.QueryDocumentListVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

/**
 * @author Tomcat
 * @Date 2023/2/15 22:22
 * @Desicribe 都是对应表finPayment，区别是paymentType，采购付款（有申请）2021、采购付款（无申请）2020、采购预款（有申请）2011、采购预款（无申请）、采购退货退款(红付)203、
 *              所以增删改都是对同一张表的相同操作，只是查寻时的条件不一样
 */
@RestController
@RequestMapping("/purchase")
@Api(tags = "付款管理-采购付款")
@Validated
public class PurchasePaymentController implements PurchasePaymentApis {
    @Autowired
    PurchasePaymentService purchasePaymentService;

    /**
     * @author 业峰
     * @param paymentCreateDTO 增加采购付款的数据传输对象
     * @return
     */
    @PostMapping("save-app")
    @ApiOperation("采购付款（有申请）增加")
    @Override
    public JsonVO<String> saveApp(PaymentCreateDTO paymentCreateDTO) {
        int insert = purchasePaymentService.insert(paymentCreateDTO);
        if (insert > 0)
            return JsonVO.success(paymentCreateDTO.toString());
        else
            return JsonVO.fail(paymentCreateDTO.toString());
    }

    @DeleteMapping("/delete-app")
    @ApiOperation("采购付款（有申请）删除")
    @Override
    public JsonVO<String> deleteApp(PaymentDeleteDTO paymentDeleteDTO) {
        int delete = purchasePaymentService.delete(paymentDeleteDTO);
        if (delete > 0) return JsonVO.success(paymentDeleteDTO.getBillNo());
        else return JsonVO.fail(paymentDeleteDTO.getBillNo());
    }

    @PutMapping("update-app")
    @ApiOperation("采购付款（有申请）修改")
    @Override
    public JsonVO<String> updateApp(PaymentUpdateDTO paymentUpdateDTO) {
        int update = purchasePaymentService.update(paymentUpdateDTO);
        if (update > 0)return JsonVO.success(paymentUpdateDTO.toString());
        else return JsonVO.fail(paymentUpdateDTO.toString());
    }

    //采购无申请
    @PostMapping("save-unapp")
    @ApiOperation("采购付款（无申请）增加")
    @Override
    public JsonVO<String> saveUnApp(PaymentCreateDTO paymentCreateDTO) {
        int insert = purchasePaymentService.insert(paymentCreateDTO);
        if (insert > 0)
            return JsonVO.success(paymentCreateDTO.toString());
        else
            return JsonVO.fail(paymentCreateDTO.toString());
    }

    @DeleteMapping("/delete-unapp")
    @ApiOperation("采购付款（无申请）删除")
    @Override
    public JsonVO<String> deleteUnApp(PaymentDeleteDTO paymentDeleteDTO) {
        int delete = purchasePaymentService.delete(paymentDeleteDTO);
        if (delete > 0) return JsonVO.success(paymentDeleteDTO.getBillNo());
        else return JsonVO.fail(paymentDeleteDTO.getBillNo());
    }

    @PutMapping("update-unapp")
    @ApiOperation("采购付款（无申请）修改")
    @Override
    public JsonVO<String> updateUnApp(PaymentUpdateDTO paymentUpdateDTO) {
        int update = purchasePaymentService.update(paymentUpdateDTO);
        if (update > 0)return JsonVO.success(paymentUpdateDTO.toString());
        else return JsonVO.fail(paymentUpdateDTO.toString());
    }

    //采购退款退货
    @PostMapping("save-refund")
    @ApiOperation("采购退款退货增加")
    @Override
    public JsonVO<String> saveRefund(PaymentCreateDTO paymentCreateDTO) {
        int insert = purchasePaymentService.insert(paymentCreateDTO);
        if (insert > 0)
            return JsonVO.success(paymentCreateDTO.toString());
        else
            return JsonVO.fail(paymentCreateDTO.toString());
    }

    @DeleteMapping("/delete-refund")
    @ApiOperation("采购退款退货删除")
    @Override
    public JsonVO<String> deleteRefund(PaymentDeleteDTO paymentDeleteDTO) {
        int delete = purchasePaymentService.delete(paymentDeleteDTO);
        if (delete > 0) return JsonVO.success(paymentDeleteDTO.getBillNo());
        else return JsonVO.fail(paymentDeleteDTO.getBillNo());
    }

    @PutMapping("update-refund")
    @ApiOperation("采购退款退货修改")
    @Override
    public JsonVO<String> updateRefund(PaymentUpdateDTO paymentUpdateDTO) {
        int update = purchasePaymentService.update(paymentUpdateDTO);
        if (update > 0)return JsonVO.success(paymentUpdateDTO.toString());
        else return JsonVO.fail(paymentUpdateDTO.toString());
    }

    /**
     *@author 业峰
     * return 文件下载的路径
     */
    @PostMapping("/upload")
    @ApiOperation("附件上传")
    @Override
    public JsonVO<String> upload(MultipartFile flie){
        return null;
    }

    /**
     * @author 业峰
     * @param condition
     * @return
     */
    @GetMapping("/list-all")
    @ApiOperation("查询所有（有申请）")
    public JsonVO<PageVO<QueryDocumentListVO>> listAll(PageQuery condition){
        PageVO<QueryDocumentListVO> page = purchasePaymentService.listAll(condition);
        return JsonVO.create(page, ResultStatus.SUCCESS);
    }

    /**
     * @author 业峰
     * @param condition
     * @return
     */
    @GetMapping("/list-all-un")
    @ApiOperation("查询所有（无申请）")
    public JsonVO<PageVO<QueryDocumentListVO>> listAllUn(PageQuery condition){
        PageVO<QueryDocumentListVO> page = purchasePaymentService.listAllUn(condition);
        return JsonVO.create(page, ResultStatus.SUCCESS);
    }

    /**
     * @author 业峰
     * @param condition
     * @return
     */
    @GetMapping("/list-refund")
    @ApiOperation("查询所有（退货退款）")
    public JsonVO<PageVO<QueryDocumentListVO>> listRefund(PageQuery condition){
        PageVO<QueryDocumentListVO> page = purchasePaymentService.listRefund(condition);
        return JsonVO.create(page, ResultStatus.SUCCESS);
    }
}
