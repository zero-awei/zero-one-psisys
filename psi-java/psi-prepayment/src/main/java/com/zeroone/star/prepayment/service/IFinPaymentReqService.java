package com.zeroone.star.prepayment.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.prepayment.entity.FinPaymentReq;
import com.zeroone.star.project.query.prepayment.FinPaymentReqQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.prepayment.FinPaymentReqVO;

/**
 * FinPaymentReq 服务类
 * author 狂踹瘸子那条好腿
 * since 2023-02-18
 */
public interface IFinPaymentReqService extends IService<FinPaymentReq> {

    PageVO<FinPaymentReqVO> listFinPaymentReq(FinPaymentReqQuery query);
}
