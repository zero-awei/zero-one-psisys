package com.zeroone.star.paymentmanagement.service.yf;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.paymentmanagement.entity.FinPayment;
import com.zeroone.star.project.dto.paymentmanagement.AddPurchasePaymentDto;
import com.zeroone.star.project.dto.paymentmanagement.UpdatePurchasePaymentDto;

/**
 * @Description 采购付款增删改表现层
 * @Author 业峰
 * @Date 2023/2/20
 */
public interface PurchasePaymentYfService extends IService<FinPayment> {

    /**
     * 新增
     * @param addPurchasePaymentDto
     * @return
     */
    int insert(AddPurchasePaymentDto addPurchasePaymentDto);

    /**
     * 根据单据编号删除单据
     * @param billNo
     * @return
     */
    int delete(String billNo);

    /**
     * 根据单据编号修改
     * @param updatePurchasePaymentDto
     * @return
     */
    int update(UpdatePurchasePaymentDto updatePurchasePaymentDto);
}
