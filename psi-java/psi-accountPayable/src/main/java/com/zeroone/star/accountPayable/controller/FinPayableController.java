package com.zeroone.star.accountPayable.controller;


import com.zeroone.star.accountPayable.service.IFinPayableService;
import com.zeroone.star.project.accountPayable.otherPayableAPI.OtherPayableApis;
import com.zeroone.star.project.query.payable.FinPayableQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.accountPayable.otherPayable.OtherPayableVO;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

/**
 * <p>
 * 应付单 前端控制器
 * </p>
 *
 * @author j3
 * @since 2023-02-14
 */
@RestController
@RequestMapping("/payable/fin-payable")
public class FinPayableController implements OtherPayableApis {

    @Resource
    IFinPayableService service;

    @GetMapping("query-all")
    @ApiOperation(value = "示例分页查询")
    @Override
    public JsonVO<PageVO<OtherPayableVO>> queryAll(FinPayableQuery condition) {
        return JsonVO.success(service.listAll(condition));
    }

    @GetMapping("query-one")
    @ApiOperation(value = "示例单据编号查询")
    @Override
    public JsonVO<OtherPayableVO> queryByBillNo(String bill_no) {
        return JsonVO.success(service.getByBillNo(bill_no));
    }
}

