package com.zeroone.star.paymentmanagement.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.paymentmanagement.entity.FinPaymentReqEntry;
import com.zeroone.star.project.query.paymentmanagement.QueryDocumentListQuery;
import com.zeroone.star.project.query.paymentmanagement.ViewSpecifiedDocInfQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.paymentmanagement.QueryDocumentListVO;
import com.zeroone.star.project.vo.paymentmanagement.ViewSpecifiedDocInfVO;

public interface IViewSpecifiedDocInfService extends IService<FinPaymentReqEntry> {

    PageVO<ViewSpecifiedDocInfVO> viewSpecifiedDocInf(ViewSpecifiedDocInfQuery query);
}
