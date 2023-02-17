package com.zeroone.star.paymentmanagement.controller;


import com.zeroone.star.paymentmanagement.service.paymentmanagement.IQueryDocumentListService;
import com.zeroone.star.project.paymentmanagement.PaymentManagementApis;
import com.zeroone.star.project.query.paymentmanagement.QueryDocumentListQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.paymentmanagement.QueryDocumentListVO;
import io.swagger.annotations.ApiModel;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/paymentmanagement/querydocumentlist")
@ApiModel("单据表单查询接口")
public class QueryDocumentListController implements PaymentManagementApis {
    private IQueryDocumentListService service;

    @GetMapping("/queryDocumentList")
    @Override
    //根据查询的条件查询单据列表结果，传入条件为：单据编号，单据日期，单据主题，供应商，单据阶段，已生效，已关闭，已作废。
    public JsonVO<PageVO<QueryDocumentListVO>> queryDocumentList(QueryDocumentListQuery condition) {

        return JsonVO.success(service.queryDocumentList(condition));
    }


}
