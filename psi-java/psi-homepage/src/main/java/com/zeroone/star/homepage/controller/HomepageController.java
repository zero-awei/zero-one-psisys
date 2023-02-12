package com.zeroone.star.homepage.controller;

import com.zeroone.star.project.homepage.HomepageApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.homepage.*;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

/**
 * @author Third uncle
 * @date 2023/2/12 - 19:11
 */
@RestController
@RequestMapping("/homepage")
@Api(tags = "首页数据查询")
public class HomepageController implements HomepageApis {
    @ApiOperation("查询毛利润")
    @GetMapping("/querySalOrdel")
    @Override
    public JsonVO<List<SalOrderVO>> querySalOrder() {
        return null;
    }
    @ApiOperation("查询采购金额")
    @GetMapping("/queryPurOrder")
    @Override
    public JsonVO<List<PurOrderVO>> queryPurOrder() {
        return null;
    }
    @ApiOperation("查询库存结存金额")
    @GetMapping("/queryStkIoSum")
    @Override
    public JsonVO<List<StkIoSumVO>> queryStkIoSum() {
        return null;
    }
    @ApiOperation("查询供应商")
    @GetMapping("/queryBasSupplier")
    @Override
    public JsonVO<List<BasSupplierVO>> queryBasSupplier() {
        return null;
    }
    @ApiOperation("查询处理中主要单据")
    @GetMapping("/queryHomeDoingBill")
    @Override
    public JsonVO<List<HomeDoingBillVO>> queryHomeDoingBill() {
        return null;
    }
}
