package com.zeroone.star.paymentmanagement.service.paymentmanagement;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.paymentmanagement.entity.FinPaymentReq;
import com.zeroone.star.project.query.paymentmanagement.QueryDocumentListQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.paymentmanagement.QueryDocumentListVO;

public interface IQueryDocumentListService extends IService<FinPaymentReq> {
    PageVO<QueryDocumentListVO>  queryDocumentList(QueryDocumentListQuery query);
}
