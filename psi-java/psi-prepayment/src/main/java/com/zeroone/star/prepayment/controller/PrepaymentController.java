package com.zeroone.star.prepayment.controller;

import com.zeroone.star.prepayment.service.IPrepaymentService;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.prepayment.*;
import com.zeroone.star.project.prepayment.PrepaymentApis;
import com.zeroone.star.project.query.prepayment.FinPaymentQuery;
import com.zeroone.star.project.query.prepayment.PreDetQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.prepayment.DetHavVO;
import com.zeroone.star.project.vo.prepayment.DetNoVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import com.zeroone.star.project.query.prepayment.DocListQuery;
import com.zeroone.star.project.vo.prepayment.DocListVO;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import com.zeroone.star.project.vo.prepayment.SupplierVO;
import org.springframework.web.bind.annotation.GetMapping;
import java.util.List;
import com.zeroone.star.project.vo.prepayment.PaymentReqEntryVO;
import org.springframework.web.multipart.MultipartFile;
import javax.annotation.Resource;
import com.zeroone.star.prepayment.service.*;
import com.zeroone.star.project.query.prepayment.PurchaseListQuery;
import com.zeroone.star.project.vo.prepayment.*;

@RestController
@RequestMapping("prepayment")
@Api(tags = "预付模块")
public class PrepaymentController implements PrepaymentApis {
    @Resource
    IPrepaymentService prepaymentService;

    @Resource
    UserHolder userHolder;

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
     * 修改采购预付单功能
     * author forever爱
     * since 2023-02-13
     */
    @PutMapping("edit")
    @ApiOperation(value = "修改采购预付单功能（返回值data值表示更新成功与否）")
    @Override
    public JsonVO<String> modifyById(ModifyDTO modifyDTO) {
        //获取用户信息
        UserDTO currentUser;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), e.getMessage());
        }
        if (currentUser == null) {
            return JsonVO.fail(null);
        }
        return prepaymentService.modifyById(modifyDTO,currentUser);
    }

    /**
     * 审核采购预付单功能
     * author forever爱
     * since 2023-02-13
     */
    @PutMapping("audit")
    @ApiOperation(value = "审核采购预付单功能（返回值data值表示更新成功与否）")
    @Override
    public JsonVO<String> auditById(AuditDTO auditDTO) {
        UserDTO currentUser;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), e.getMessage());
        }
        if (currentUser == null) {
            return JsonVO.fail(null);
        }
        return prepaymentService.auditById(auditDTO,currentUser);
    }


    /**
     * 单据分页查询
     * 采购预付（有申请）：payment_type 2011
     * 采购预付（无申请）：payment_type 2010
     * author husj
     * since 2023-02-13
     */
    @Override
    @GetMapping("query-all")
    @ApiOperation(value = "查询采购预付单功能")
    public JsonVO<PageVO<FinPaymentVO>> queryAll(FinPaymentQuery condition) {
        return prepaymentService.queryAll(condition);
    }

    /**
     * 根据单据编号查询信息
     * author hzp
     * since 2023-02-13
     */
    @GetMapping("query-one-hav")
    @ApiOperation(value = "查看单据详情信息（有申请）")
    @Override
    public JsonVO<DetHavVO> queryByBillHav(PreDetQuery condition) {
        return prepaymentService.queryByBillHav(condition);
    }

    @GetMapping("query-one-no")
    @ApiOperation(value = "查看单据详情信息（无申请）")
    @Override
    public JsonVO<DetNoVO> queryByBillNo(PreDetQuery condition) {
        return prepaymentService.queryByBillNo(condition);
    }

    /**
     * 导出功能实现
     * author 明破
     * since 2023-02-13
     */
    @GetMapping("export")
    @ApiOperation(value = "导出功能")
    @Override
    public ResponseEntity<byte[]> download() {
        return null;
    }

    @ApiOperation(value = "获取导出链接")
    @Override
    public JsonVO<String> downloadUrl() {
        return null;
    }

    /**
     * 删除
     * author 出运费
     * since 2023-02-13
     */
    @DeleteMapping("delete")
    @ApiOperation(value = "删除功能（返回值data值保存删除成功与否）")
    @Override
    public JsonVO<String> deleteById(DeleteDTO deleteDTO) throws Exception {
        return prepaymentService.deleteById(deleteDTO);
    }

    /**
     * 添加
     * author 空
     * since 2023-02-13
     */
    @PostMapping("insert")
    @ApiOperation(value = "添加采购预付单功能（返回值data值表示创建成功与否）")
    @Override
    public JsonVO<String> prepaymentForPurchaseRequisitions(PrepaymentDTO prepaymentDTO) {
        //获取用户信息
        UserDTO currentUser;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), e.getMessage());
        }
        if (currentUser == null) {
            return JsonVO.fail(null);
        }
        return prepaymentService.prepay(prepaymentDTO,currentUser);
    }

    /**
     * 获取采购项目清单（无申请）
     * author 空
     * since 2023-02-13
     */
    @GetMapping("list-purhcaserequisitions")
    @ApiOperation(value = "获取采购清单（无申请）")
    @Override
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
    @Override
    public JsonVO<PageVO<FinPaymentReqVO>> queryForPurchaseRequisitions(PurchaseListQuery purchaseListQuery) {
        PageVO<FinPaymentReqVO> finPaymentReq = finPaymentReqService.getFinPaymentReq(purchaseListQuery);
        return JsonVO.success(finPaymentReq);
    }


    /**
     * 获取供应商列表
     * author 空
     * since 2023-02-13
     */
    @GetMapping("getSuppliers")
    @ApiOperation(value = "获取供应商列表")
    @Override
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
    @Override
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
    @Override
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
    @Override
    public JsonVO<List<BasBankAccountVO>> getBankAccount() {
        List<BasBankAccountVO> basBankAccountList = basBankAccountService.getBasBankAccountList();
        return JsonVO.success(basBankAccountList);
    }


    /**
     * 付款申请单分录明细列表查询
     * param billNo 分录单号
     * return 分录明细列表
     * author 内鬼
     */
    @GetMapping("query-all-by-billno")
    @Override
    @ApiOperation("付款申请单分录列表查询")
    public JsonVO<PageVO<PaymentReqEntryVO>> queryAllByBillNo(String billNo) {
        return null;
    }

    /**
     * Excel 表格导入
     * param file Excel 文件
     * return 处理结果
     * author 内鬼
     */
    @Override
    @PostMapping("import")
    @ResponseBody
    @ApiOperation("导入功能（返回值data值表示导入成功与否）")
    public JsonVO<String> excelImport(@RequestParam("file") MultipartFile file) {
        return JsonVO.success("文件上传成功！");
    }

    /**
     * 修改状态
     * author yu-hang
     */
    @Override
    @PutMapping("close")
    @ApiOperation(value = "关闭操作（返回值data值表示更新成功与否）")
    public JsonVO<String> closeById(String id) {
        //获取用户信息
        UserDTO currentUser;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), e.getMessage());
        }
        if (currentUser == null) {
            return JsonVO.fail(null);
        }
        return prepaymentService.closeById(id,currentUser);
    }

    @PutMapping("unclose")
    @ApiOperation(value = "反关闭操作（返回值data值表示更新成功与否）")
    @Override
    public JsonVO<String> uncloseById(String id) {
        //获取用户信息
        UserDTO currentUser;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), e.getMessage());
        }
        if (currentUser == null) {
            return JsonVO.fail(null);
        }
        return prepaymentService.uncloseById(id,currentUser);
    }

    @Override
    @PutMapping("void")
    @ApiOperation(value = "作废操作（返回值data值表示更新成功与否）")
    public JsonVO<String> voidById(String id) {
        //获取用户信息
        UserDTO currentUser;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            return JsonVO.create(null, ResultStatus.FAIL.getCode(), e.getMessage());
        }
        if (currentUser == null) {
            return JsonVO.fail(null);
        }
        return prepaymentService.voidById(id,currentUser);
    }
}
