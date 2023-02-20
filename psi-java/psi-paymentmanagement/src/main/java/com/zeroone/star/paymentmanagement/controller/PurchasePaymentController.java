package com.zeroone.star.paymentmanagement.controller;

import com.zeroone.star.project.dto.paymentmanagement.purchasepayment.PaymentCreateDTO;
import com.zeroone.star.project.dto.paymentmanagement.purchasepayment.PaymentDeleteDTO;
import com.zeroone.star.project.dto.paymentmanagement.purchasepayment.PaymentUpdateDTO;
import com.zeroone.star.project.paymentmanagement.purchasepayment.PurchasePaymentApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

/**
 * @author Tomcat
 * @Date 2023/2/15 22:22
 */
@RestController
@RequestMapping("/purchase")
@Api(tags = "付款管理-采购付款")
@Validated
public class PurchasePaymentController implements PurchasePaymentApis {
    @PostMapping("save")
    @ApiOperation("采购付款增加")
    @Override
    public JsonVO<String> save(PaymentCreateDTO create) {
        return null;
    }
    @DeleteMapping("/delete")
    @ApiOperation("采购付款删除")
    @Override
    public JsonVO<String> delete(PaymentDeleteDTO delete) {
        return null;
    }

    @PutMapping("update")
    @ApiOperation("采购付款修改")
    @Override
    public JsonVO<String> update(PaymentUpdateDTO update) {
        return null;
    }

    @PostMapping("/upload")
    @ApiOperation("附件上传")
    @Override
    public JsonVO<String> upload(MultipartFile flie){return null;}
}
