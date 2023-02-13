package com.zeroone.star.payment.controller;


import com.zeroone.star.project.payment.PurOrderApis;
import com.zeroone.star.project.query.payment.PurchaseListQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payment.PurOrderEntryVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * <p>
 * 采购订单 前端控制器
 * </p>
 *
 * @author zhd
 * @since 2023-02-11
 */
@RestController
@RequestMapping("/payment/pur-order")
@Api(tags = "采购清单（无申请）")
public class PurOrderController implements PurOrderApis {


}

