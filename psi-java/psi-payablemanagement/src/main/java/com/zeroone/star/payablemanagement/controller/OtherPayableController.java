package com.zeroone.star.payablemanagement.controller;

import com.zeroone.star.payablemanagement.service.IFinPayableService;
import com.zeroone.star.project.payablemanagement.OtherPayableApis;
import com.zeroone.star.project.query.payablemanagement.PayableQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payablemanagement.PayableVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

@RestController
@RequestMapping("/payablemanagement/otherPayable")
@Api(tags = "其他应付单CURD操作处理")
public class OtherPayableController implements OtherPayableApis {
    @Resource
    IFinPayableService service;

    @GetMapping("query-all")
    @ApiOperation(value = "根据条件分页查询")
    @Override
    public JsonVO<PageVO<PayableVO>> queryAll(PayableQuery condition) {
        return JsonVO.success(service.queryAll(condition));
    }


    @GetMapping("query-one")
    @ApiOperation(value = "示例单据编号查询")
    @Override
    public JsonVO<PayableVO> queryByBillNo(String bill_no) {
        return JsonVO.success(service.getByBillNo(bill_no));
    }
}
