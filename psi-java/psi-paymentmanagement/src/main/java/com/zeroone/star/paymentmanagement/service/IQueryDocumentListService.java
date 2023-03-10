package com.zeroone.star.paymentmanagement.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.paymentmanagement.entity.FinPayment;
import com.zeroone.star.paymentmanagement.entity.QueryDocumentList;
import com.zeroone.star.project.query.paymentmanagement.QueryDocumentListQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.paymentmanagement.QueryDocumentListVO;

public interface IQueryDocumentListService extends IService<FinPayment> {
//public interface IQueryDocumentListService extends IService<QueryDocumentList> {
    PageVO<QueryDocumentListVO>  queryDocumentList(QueryDocumentListQuery query);
}
