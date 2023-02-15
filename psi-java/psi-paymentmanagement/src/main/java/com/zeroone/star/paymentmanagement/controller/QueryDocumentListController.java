package com.zeroone.star.paymentmanagement.controller;


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
@RequestMapping("/paymentmanagement/")
@ApiModel("单据表单查询接口")
public class QueryDocumentListController implements PaymentManagementApis {
    @GetMapping("/querydocumentlist")
    @Override
    public JsonVO<PageVO<QueryDocumentListVO>> queryAll(QueryDocumentListQuery condition) {
        return null;
    }
}
