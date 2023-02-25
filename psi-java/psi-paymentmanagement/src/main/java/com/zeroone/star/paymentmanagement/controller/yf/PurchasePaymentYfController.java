package com.zeroone.star.paymentmanagement.controller.yf;

import com.zeroone.star.paymentmanagement.service.yf.PurchasePaymentYfService;
import com.zeroone.star.project.dto.paymentmanagement.AddPurchasePaymentDto;
import com.zeroone.star.project.dto.paymentmanagement.UpdatePurchasePaymentDto;
import com.zeroone.star.project.dto.paymentmanagement.yf.PurchasePaymentDeleteYfDto;
import com.zeroone.star.project.paymentmanagement.PurchasePayment;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

/**
 * @Description 采购付款增删改表现层
 * @Author 业峰
 * @Date 2023/2/20
 */

@RestController
@RequestMapping("/purchase-payment")
@Api(tags = "应付与付款-付款管理")
@Validated
public class PurchasePaymentYfController implements PurchasePayment {

    @Autowired
    PurchasePaymentYfService purchasePaymentService;

    /**
     * 增加单据
     * @param addPurchasePaymentDto
     * @return
     */
    @Override
    @PostMapping("/save")
    @ApiOperation("增加单据")
    public JsonVO<String> addPurchasePayment(AddPurchasePaymentDto addPurchasePaymentDto) {
        int insert = purchasePaymentService.insert(addPurchasePaymentDto);
        if (insert > 0)
            return JsonVO.success(addPurchasePaymentDto.toString());
        else
            return JsonVO.fail(addPurchasePaymentDto.toString());
    }

    /**
     * 修改单据
     * @param updatePurchasePaymentDto
     * @return
     */
    @Override
    @PostMapping("update")
    @ApiOperation("修改单据")
    public JsonVO<String> updatePurchasePayment(UpdatePurchasePaymentDto updatePurchasePaymentDto) {
        int update = purchasePaymentService.update(updatePurchasePaymentDto);
        if (update > 0)return JsonVO.success(updatePurchasePaymentDto.toString());
        else return JsonVO.fail(updatePurchasePaymentDto.toString());

    }

    /**
     * 删除单据
     * @param purchasePaymentDeleteYfDto 根据单据billNo删除对应的单据，此处还没考虑连表删除
     * @return
     */
    @Override
    @DeleteMapping("delete")
    @ApiOperation("删除单据")
    public JsonVO<String> deletePurchasePayment(PurchasePaymentDeleteYfDto purchasePaymentDeleteYfDto) {
        int delete = purchasePaymentService.delete(purchasePaymentDeleteYfDto.getBillNo());
        if (delete > 0) return JsonVO.success(purchasePaymentDeleteYfDto.getBillNo());
        else return JsonVO.fail(purchasePaymentDeleteYfDto.getBillNo());
    }

    @Override
    public JsonVO<String> upload(MultipartFile multipartFile) {
        return null;
    }
}
