package com.zeroone.star.payable.controller.purchase;

import com.zeroone.star.payable.service.IFinPayableService;
import com.zeroone.star.project.payable.purchasePayableAPI.PurchasePayableApis;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.query.patable.purchase.MultiConditionPayableQuery;
import com.zeroone.star.project.query.patable.purchase.PayableQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payable.purchase.FinPayableVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.bind.annotation.RestController;

/**
 * <p>
 * 应付单 前端控制器
 * </p>
 *
 * @author chosen1
 * @since 2023-02-14
 */
@RestController
@RequestMapping("/jeecg-boot/finance/finPayable/")
@Api(tags = "采购预付")
@Validated
public class PurchasePayableController implements PurchasePayableApis {

    @Autowired
    private IFinPayableService service;

    @ApiOperation("分页查询所有单据")
    @GetMapping("list/all")
    @Override
    public JsonVO<PageVO<FinPayableVO>> listAll(PageQuery query) {
        return JsonVO.success(service.listAll(query));
    }

    @ApiOperation("分页查询所有单据")
    @GetMapping("list/multi")
    @Override
    public JsonVO<PageVO<FinPayableVO>> multiConditionSearch(MultiConditionPayableQuery query) {
        return JsonVO.success(service.multiConditionSearch(query));
    }

    @ApiOperation("查询单据详情")
    @GetMapping("query")
    @Override
    public JsonVO<FinPayableVO> getById(@Validated PayableQuery query) {
        return JsonVO.success(service.getById(query));
    }
}
