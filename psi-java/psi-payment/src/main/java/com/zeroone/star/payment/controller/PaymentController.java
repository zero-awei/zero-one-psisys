package com.zeroone.star.payment.controller;

import com.zeroone.star.project.dto.payment.PrepaymentDTO;
import com.zeroone.star.project.payment.PaymentApis;
import com.zeroone.star.project.query.payment.PurchaseListQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payment.*;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

@RestController
@RequestMapping("/payment")
@Api(tags = "预付款")
public class PaymentController implements PaymentApis {

    @PutMapping("insert-prepayment")
    @ApiOperation(value = "预付款操作")
    @Override
    public JsonVO<String> prepaymentForPurchaseRequisitions(PrepaymentDTO prepaymentDTO) {
        return null;
    }

    @GetMapping("getSuppliers")
    @ApiOperation(value = "获取供应商")
    @Override
    public JsonVO<List<SupplierVO>> querySupplierList() {
        return null;
    }



    @GetMapping("list-appliedpurhcaserequisitions")
    @ApiOperation(value = "获取采购清单（有申请）")
    @Override
    public JsonVO<PageVO<FinPaymentReqVO>> queryForAppliedPurchaseRequisitions(PurchaseListQuery purchaseListQuery) {
        return null;
    }

    @GetMapping("sys_user,realname,username")
    @ApiOperation(value = "获取用户字典")
    @Override
    public JsonVO<List<SysUserVO>> getSysUsersName() {
        return null;
    }

    @GetMapping("sys_depart,depart_name,org_code")
    @ApiOperation(value = "获取部门字典")
    @Override
    public JsonVO<List<SysDepartVO>> getSysDepart() {
        return null;
    }

    @GetMapping("bas_bank_account,account_no,id")
    @ApiOperation(value = "获取银行账户列表")
    @Override
    public JsonVO<List<BasBankAccountVO>> getBankAccount() {
        return null;
    }

    @GetMapping("list-purhcaserequisitions")
    @ApiOperation(value = "获取采购清单（无申请）")
    @Override
    public JsonVO<PageVO<PurOrderEntryVO>> queryForPurchaseRequisitions(PurchaseListQuery purchaseListQuery) {
        return null;
    }

}
