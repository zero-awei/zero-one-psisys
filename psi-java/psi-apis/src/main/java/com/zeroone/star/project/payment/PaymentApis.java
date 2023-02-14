package com.zeroone.star.project.payment;

import com.zeroone.star.project.dto.payment.ModifyDTO;
import com.zeroone.star.project.vo.JsonVO;

/**
 * 描述：测试API接口
 */
public interface PaymentApis {
    /**
     * 修改采购预付单功能
     * param modifyDTO 带明细表的收款单DTO
     * return 查询结果
     * author forever爱
     */
    JsonVO<String> modifyById(ModifyDTO modifyDTO);

}
