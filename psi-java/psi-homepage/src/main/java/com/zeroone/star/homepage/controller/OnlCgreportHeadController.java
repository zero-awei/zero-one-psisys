package com.zeroone.star.homepage.controller;


import com.zeroone.star.project.homepage.InformationApis;
import com.zeroone.star.project.query.homepage.*;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.homepage.*;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.bind.annotation.RestController;

import java.util.List;

/**
 * <p>
 *  前端控制器
 * </p>
 *
 * @author yx
 * @since 2023-02-11
 */
@RestController
@RequestMapping("/homepage/onl-cgreport-head")
@Api(tags = "首页信息概况")
public class OnlCgreportHeadController implements InformationApis {

    @ApiOperation("查询系统收支概况")
    @GetMapping("/querySys")
    @Override
    public JsonVO<List<SystemRevenueAndExpenditureInformationVO>> querySystemInfoById(SystemRevenueAndExpenditureInformationQuery query) {
        return null;
    }

    @ApiOperation("查询销售概况")
    @GetMapping("/querySale")
    @Override
    public JsonVO<List<SaleInformationVO>> querySaleInfoById(SaleInformationQuery query) {
        return null;
    }

    @ApiOperation("查询采购概况")
    @GetMapping("/queryPurchase")
    @Override
    public JsonVO<List<PurchaseInformationVO>> queryPurchaseInfoById(PurchaseInformationQuery query) {
        return null;
    }

    @ApiOperation("查询客户概况")
    @GetMapping("/queryCustomer")
    @Override
    public JsonVO<List<CustomerInformationVO>> queryCustomerInfoById(CustomerInformationQuery query) {
        return null;
    }

    @ApiOperation("查询销售金额概况")
    @GetMapping("/querySalesAmount")
    @Override
    public JsonVO<List<SalesAmountInformationVO>> querySalesAmountInfoById(SalesAmountIformationQuery query) {
        return null;
    }
}

