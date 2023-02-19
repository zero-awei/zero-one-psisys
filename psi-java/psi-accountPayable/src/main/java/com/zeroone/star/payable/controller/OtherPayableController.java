package com.zeroone.star.payable.controller;

import com.zeroone.star.payable.service.IFinPayableService;
import com.zeroone.star.project.accountPayable.otherPayableAPI.OtherPayableApis;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.query.payable.FinPayableQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.accountPayable.otherPayable.OtherPayableVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

@RestController
@RequestMapping("/payment/other")
@Api(tags = "其他应付单CURD操作处理")
public class OtherPayableController implements OtherPayableApis {
    @Resource
    IFinPayableService service;

    @GetMapping("query-all")
    @ApiOperation(value = "根据条件分页查询")
    @Override
    public JsonVO<PageVO<OtherPayableVO>> queryAll(FinPayableQuery condition) {
        return JsonVO.success(service.queryAll(condition));
    }


    @GetMapping("query-one")
    @ApiOperation(value = "示例单据编号查询")
    @Override
    public JsonVO<OtherPayableVO> queryByBillNo(String bill_no) {
        return JsonVO.success(service.getByBillNo(bill_no));
    }
}
