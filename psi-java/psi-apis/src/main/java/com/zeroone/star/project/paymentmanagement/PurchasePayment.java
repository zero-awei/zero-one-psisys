package com.zeroone.star.project.paymentmanagement;

import com.zeroone.star.project.dto.paymentmanagement.AddPurchasePaymentDto;
import com.zeroone.star.project.dto.paymentmanagement.UpdatePurchasePaymentDto;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.web.multipart.MultipartFile;

/**
 * @Description 采购付款增删改接口
 * @Author 业峰
 * @Date 2023/2/15
 */
public interface PurchasePayment {
    /**
     *  添加新的采购付款单据
     * @param addPurchasePaymentDto
     * @return
     */
    JsonVO<String> addPurchasePayment(AddPurchasePaymentDto addPurchasePaymentDto);

    /**
     *  修改采购付款单据
     * @param updatePurchasePaymentDto
     * @return
     */
    JsonVO<String> updatePurchasePayment(UpdatePurchasePaymentDto updatePurchasePaymentDto);

    /**
     * 删除单据
     * @param dillId
     * @return
     */
    JsonVO<String> deletePurchasePayment(String dillId);

    /**
     * 上传文件
     * @param multipartFile
     * @return
     */
    JsonVO<String> upload(MultipartFile multipartFile);
}
