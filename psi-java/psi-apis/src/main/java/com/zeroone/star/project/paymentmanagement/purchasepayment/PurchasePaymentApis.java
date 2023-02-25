package com.zeroone.star.project.paymentmanagement.purchasepayment;

import com.zeroone.star.project.dto.paymentmanagement.purchasepayment.PaymentCreateDTO;
import com.zeroone.star.project.dto.paymentmanagement.purchasepayment.PaymentDeleteDTO;
import com.zeroone.star.project.dto.paymentmanagement.purchasepayment.PaymentUpdateDTO;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.web.multipart.MultipartFile;

/**
 * @author Tomcat
 * @Date 2023/2/15 22:17
 */
public interface PurchasePaymentApis {
    /**
     * 增加接口
     *
     * @param create 增加采购付款的数据传输对象
     * @return {@link JsonVO}<{@link String}>
     */
    JsonVO<String> saveApp(PaymentCreateDTO create);


    /**
     * 删除接口
     *
     * @param delete 删除采购付款的数据传输对象
     * @return {@link JsonVO}<{@link String}>
     */
    JsonVO<String> deleteApp(PaymentDeleteDTO delete);

    /**
     * 更新接口
     *
     * @param update 修改采购付款的数据传输对象
     * @return {@link JsonVO}<{@link String}>
     */
    JsonVO<String> updateApp(PaymentUpdateDTO update);

    /**
     * 上传文件
     *
     * @param file 文件
     * @return {@link JsonVO}<{@link String}>
     */
    JsonVO<String> upload(MultipartFile file);

    //采购无申请
    JsonVO<String> saveUnApp(PaymentCreateDTO create);

    JsonVO<String> deleteUnApp(PaymentDeleteDTO delete);

    JsonVO<String> updateUnApp(PaymentUpdateDTO update);

    //采购退款退货
    JsonVO<String> saveRefund(PaymentCreateDTO create);

    JsonVO<String> deleteRefund(PaymentDeleteDTO delete);

    JsonVO<String> updateRefund(PaymentUpdateDTO update);

}
