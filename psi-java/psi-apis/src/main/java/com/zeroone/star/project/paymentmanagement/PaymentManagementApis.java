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
    //根据筛选信息查询单据列表。
    //传入筛选条件，返还结果page
    JsonVO<PageVO<QueryDocumentListVO>> queryDocumentList_true(QueryDocumentListQuery condition);
    JsonVO<PageVO<QueryDocumentListVO>> queryDocumentList_false(QueryDocumentListQuery condition);
    JsonVO<PageVO<QueryDocumentListVO>> queryDocumentList_red(QueryDocumentListQuery condition);
}
