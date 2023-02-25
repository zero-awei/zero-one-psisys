package com.zeroone.star.paymentmanagement.controller;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.paymentmanagement.service.StkIoService;
import com.zeroone.star.project.paymentmanagement.StkIoApis;
import com.zeroone.star.project.query.paymentmanagement.StkIoQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.paymentmanagement.StkIoVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiImplicitParams;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * @author 白也
 * @title
 * @date 2023/2/24 6:01 下午
 */

@Api(value = "/paymentmanagement/stklo", tags = {"应付与付款-付款管理"})
@RestController
@RequestMapping("/paymentmanagement/stklo")
public class StkIoController implements StkIoApis {
    @Autowired
    private StkIoService stkIoService;
    /**
     * 入库单查询
     * @param stkIoQuery 入库单条件
     * @return 列表
     */
    @ApiOperation(value = "入库单查询", notes = "入库单查询", httpMethod = "GET")
    @Override
    @GetMapping
    public JsonVO<Page<StkIoVO>> queryStorage(StkIoQuery stkIoQuery) {
        return JsonVO.success(stkIoService.queryAll(stkIoQuery));
    }

    /**
     * 采购退货出库单
     *
     * @param stkIoQuery 条件
     * @return list
     */
    @ApiOperation(value = "采购退货出库单", notes = "采购退货出库单", httpMethod = "GET")
    @Override
    @GetMapping("/deliveryOrder")
    public JsonVO<Page<StkIoVO>> deliveryOrder(StkIoQuery stkIoQuery) {
        return JsonVO.success(stkIoService.deliveryOrder(stkIoQuery));
    }


}
