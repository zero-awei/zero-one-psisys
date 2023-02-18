package com.zeroone.star.prepayment.service;

import com.zeroone.star.prepayment.entity.FinPaymentEntry;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.prepayment.ModifyDTO;
import com.zeroone.star.project.vo.JsonVO;

/**
 * <p>
 * 付款单明细 服务类
 * </p>
 *
 * @author zhd
 * @since 2023-02-18
 */
public interface IFinPaymentEntryService extends IService<FinPaymentEntry> {

    /**
     * 修改采购预付单
     * author forever爱
     */
    public JsonVO<String> modifyById(ModifyDTO modifyDTO);
}
