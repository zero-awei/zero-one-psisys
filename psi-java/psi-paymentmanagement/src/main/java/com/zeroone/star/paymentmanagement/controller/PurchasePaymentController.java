package com.zeroone.star.paymentmanagement.controller;

import com.zeroone.star.paymentmanagement.service.PurchasePaymentService;
import com.zeroone.star.project.dto.paymentmanagement.purchasepayment.PaymentCreateDTO;
import com.zeroone.star.project.dto.paymentmanagement.purchasepayment.PaymentDeleteDTO;
import com.zeroone.star.project.dto.paymentmanagement.purchasepayment.PaymentUpdateDTO;
import com.zeroone.star.project.paymentmanagement.purchasepayment.PurchasePaymentApis;
import com.zeroone.star.project.vo.JsonVO;
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

    @DeleteMapping("/delete")
    @ApiOperation("采购付款删除")
    @Override
    public JsonVO<String> delete(PaymentDeleteDTO paymentDeleteDTO) {
        int delete = purchasePaymentService.delete(paymentDeleteDTO);
        if (delete > 0) return JsonVO.success(paymentDeleteDTO.getBillNo());
        else return JsonVO.fail(paymentDeleteDTO.getBillNo());
    }

    @PutMapping("update")
    @ApiOperation("采购付款修改")
    @Override
    public JsonVO<String> update(PaymentUpdateDTO paymentUpdateDTO) {
        int update = purchasePaymentService.update(paymentUpdateDTO);
        if (update > 0)return JsonVO.success(paymentUpdateDTO.toString());
        else return JsonVO.fail(paymentUpdateDTO.toString());
    }

    @PostMapping("/upload")
    @ApiOperation("附件上传")
    @Override
    //TODO：技术没懂，暂时放着
    public JsonVO<String> upload(MultipartFile flie){return null;}


}
