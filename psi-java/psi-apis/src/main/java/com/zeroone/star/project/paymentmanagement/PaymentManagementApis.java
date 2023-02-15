package com.zeroone.star.project.paymentmanagement;

import com.zeroone.star.project.query.paymentmanagement.QueryDocumentListQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.paymentmanagement.QueryDocumentListVO;

/*
   achuan
   api接口自定义模块
 */
public interface PaymentManagementApis {
    JsonVO<PageVO<QueryDocumentListVO>> queryAll(QueryDocumentListQuery condition);
}
