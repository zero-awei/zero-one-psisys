package com.zeroone.star.prepayment.controller;

import com.zeroone.star.prepayment.service.IPrepaymentService;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.prepayment.*;
import com.zeroone.star.project.prepayment.PrepaymentApis;
import com.zeroone.star.project.query.prepayment.*;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.prepayment.DetHavVO;
import com.zeroone.star.project.vo.prepayment.DetNoVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.bind.annotation.GetMapping;
import javax.annotation.Resource;
import com.zeroone.star.prepayment.service.*;
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
    IFinPaymentReqService paymentReqService;

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
     * author husj、hzp
     * since 2023-02-13
     */
    @Override
    @GetMapping("query-all-hav")
    @ApiOperation(value = "查询采购预付单功能（有申请）")
    @ResponseBody
    public JsonVO<PageVO<DocListVO>> queryAllHav(DocListQuery condition) {
        condition.setPaymentType("2011");
        return JsonVO.success(prepaymentService.queryAll(condition));
    }

    @Override
    @GetMapping("query-all-no")
    @ApiOperation(value = "查询采购预付单功能（无申请）")
    @ResponseBody
    public JsonVO<PageVO<DocListVO>> queryAllNo(DocListQuery condition) {
        condition.setPaymentType("2010");
        return JsonVO.success(prepaymentService.queryAll(condition));
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
     * 采购预付申请单分录列表
     * param supplierName 供应商名
     * return 分录明细列表
     * author 内鬼
     */
    @Override
    @GetMapping("query-all-paymentReq")
    @ResponseBody
    @ApiOperation("付款申请单分录列表查询")
    public JsonVO<PageVO<ReqVO>> queryAllReq(FinPaymentReqQuery query) {
        PageVO<ReqVO> paymentReqEntryPage = paymentReqService.listFinPaymentReq(query);
        return JsonVO.success(paymentReqEntryPage);
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
