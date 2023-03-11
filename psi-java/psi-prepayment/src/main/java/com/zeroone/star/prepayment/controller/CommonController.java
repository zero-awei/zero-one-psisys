package com.zeroone.star.prepayment.controller;

import com.zeroone.star.prepayment.service.*;
import com.zeroone.star.project.query.prepayment.PurchaseListQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.prepayment.*;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.util.List;

@RestController
@RequestMapping("common")
@Api(tags = "公共接口")
public class CommonController {
    @Resource
    ISysDepartService departService;
    @Resource
    IBasBankAccountService basBankAccountService;
    @Resource
    ISysUserService userService;
    @Resource
    IBasSupplierService supplierService;
    @Resource
    IFinPaymentReqService finPaymentReqService;
    @Resource
    IPurOrderService purOrderService;
    /**
     * 获取供应商列表
     * author 空
     * since 2023-02-13
     */
    @GetMapping("getSuppliers")
    @ApiOperation(value = "获取供应商列表")
    public JsonVO<List<SupplierVO>> querySupplierList() {
        List<SupplierVO> supplierList = supplierService.getSupplierList();
        return JsonVO.success(supplierList);
    }

    /**
     * 获取系统用户列表
     * author 空
     * since 2023-02-13
     */
    @GetMapping("sys_user,realname,username")
    @ApiOperation(value = "获取用户字典")
    public JsonVO<List<SysUserVO>> getSysUsersName() {
        List<SysUserVO> sysUserList = userService.getSysUserList();
        return JsonVO.success(sysUserList);
    }

    /**
     * 获取组织机构表
     * author 空
     * since 2023-02-13
     */
    @GetMapping("sys_depart,depart_name,org_code")
    @ApiOperation(value = "获取部门字典")
    public JsonVO<List<SysDepartVO>> getSysDepart() {
        List<SysDepartVO> departs = departService.getDeparts();
        return JsonVO.success(departs);
    }

    /**
     * 获取银行账户列表
     * author 空
     * since 2023-02-13
     */
    @GetMapping("bas_bank_account,account_no,id")
    @ApiOperation(value = "获取银行账户列表")
    public JsonVO<List<BasBankAccountVO>> getBankAccount() {
        List<BasBankAccountVO> basBankAccountList = basBankAccountService.getBasBankAccountList();
        return JsonVO.success(basBankAccountList);
    }

    /**
     * 获取采购项目清单（无申请）
     * author 空
     * since 2023-02-13
     */
    @GetMapping("list-purhcaserequisitions")
    @ApiOperation(value = "获取采购清单（无申请）")
    public JsonVO<PageVO<PurOrderVO>> queryForAppliedPurchaseRequisitions(PurchaseListQuery purchaseListQuery) {
        PageVO<PurOrderVO> purOrder = purOrderService.getPurOrder(purchaseListQuery);
        return JsonVO.success(purOrder);
    }

    /**
     * 获取采购项目清单（有申请）
     * author 空
     * since 2023-02-13
     */
    @GetMapping("list-appliedpurhcaserequisitions")
    @ApiOperation(value = "获取采购清单（有申请）")
    public JsonVO<PageVO<FinPaymentReqVO>> queryForPurchaseRequisitions(PurchaseListQuery purchaseListQuery) {
        PageVO<FinPaymentReqVO> finPaymentReq = finPaymentReqService.getFinPaymentReq(purchaseListQuery);
        return JsonVO.success(finPaymentReq);
    }
}
