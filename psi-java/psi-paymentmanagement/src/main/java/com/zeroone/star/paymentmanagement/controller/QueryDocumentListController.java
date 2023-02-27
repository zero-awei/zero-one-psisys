package com.zeroone.star.paymentmanagement.controller;


import com.zeroone.star.paymentmanagement.service.IQueryDocumentListService;
import com.zeroone.star.project.paymentmanagement.PaymentManagementApis;
import com.zeroone.star.project.query.paymentmanagement.QueryDocumentListQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.paymentmanagement.QueryDocumentListVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

/**
 * @author achuan
 * @Date 2023/2/18 22:22
 */
@RestController
@RequestMapping("/payment-management")
@Api(tags = "付款管理-采购付款")
@ApiModel("单据表单查询接口")
public class QueryDocumentListController implements PaymentManagementApis {

    @Resource
    private IQueryDocumentListService service;

    @GetMapping("query-documentList")
    //@PostMapping("/queryDocumentList")
    @ApiOperation(value="查询单据列表数据(有申请)")
    @Override
    //业峰：这里是分页查询，查询条件只有page，有申请的筛选条件是payType=2021，在service中进行直接筛选
    //根据查询的条件查询单据列表结果，传入条件为：单据编号，单据日期，单据主题，供应商，单据阶段，已生效，已关闭，已作废。
    public JsonVO<PageVO<QueryDocumentListVO>> queryDocumentList(QueryDocumentListQuery condition) {
        //System.out.println("页面"+ condition.getPageIndex());
        return JsonVO.create(service.queryDocumentList(condition), ResultStatus.SUCCESS);
//        return null;
    }





}
