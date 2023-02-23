package com.zeroone.star.prepayment.service;

import com.zeroone.star.prepayment.entity.FinPayment;
import org.springframework.web.multipart.MultipartFile;

/**
 * FinPayment 服务类
 * author 狂踹瘸子那条好腿
 * since 2023-02-18
 */
public interface IFinPaymentService {
    /**
     * 根据单据编号查询指定付款单
     * @param billNo 单据编号
     * @return 查询结果
     */
    FinPayment getByBillNo(String billNo);

    void importExcelOfPayment(MultipartFile file) throws Exception;
}
