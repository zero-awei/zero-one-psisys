package com.zeroone.star.project.prepayment;

import com.zeroone.star.project.dto.prepayment.*;
import com.zeroone.star.project.query.prepayment.IdQuery;
import com.zeroone.star.project.vo.JsonVO;

import com.zeroone.star.project.query.prepayment.DocListQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.prepayment.DocListVO;


import com.zeroone.star.project.query.prepayment.PreDetQuery;
import com.zeroone.star.project.vo.prepayment.DetHavVO;
import com.zeroone.star.project.vo.prepayment.DetNoVO;

import org.springframework.http.ResponseEntity;

import com.zeroone.star.project.vo.prepayment.SupplierVO;

import java.util.List;

import com.zeroone.star.project.vo.prepayment.PaymentReqEntryVO;
import org.springframework.web.multipart.MultipartFile;

/**
 * <p>
 * 描述：API接口定义
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author forever爱
 * @version 1.0.0
 */
public interface PrepaymentApis {
    /**
     * 修改采购预付单功能
     * param modifyDTO 带明细表的收款单DTO
     * return 查询结果
     * author forever爱
     */
    JsonVO<String> modifyById(ModifyDTO modifyDTO);

    /**
     * 审核采购预付单功能
     * param auditDTO 审核DTO
     * return 查询结果
     * author forever爱
     */
    JsonVO<String> auditById(AuditDTO auditDTO);


    /**
     * 单据列表查询
     * param condition 查询条件
     * return 查询结果
     * author husj
     * version 1.0.0
     */
    JsonVO<PageVO<DocListVO>> queryAll(DocListQuery condition);

    /**
     * 通过单据编号查询数据-采购预付有申请
     * param condition 单据编号-查询条件
     * return 查询结果
     * author hzp
     */
    JsonVO<DetHavVO> queryByBillHav(PreDetQuery condition);

    /**
     *通过单据编号查询数据-采购预付无申请
     * param condition 单据编号-查询条件
     * return 查询结果
     * author hzp
     */
    JsonVO<DetNoVO> queryByBillNo (PreDetQuery condition);

    /**
     * 获取导出文件
     * return 返回响应对象
     * author 明破
     */
    ResponseEntity<byte[]> download();

    /**
     * 获取导出链接
     * return 返回下载路径
     * author 明破
     */
    JsonVO<String> downloadUrl();

    /**
     * 删除预付单功能
     * param deleteDTO 包含付款单id
     * return 删除结果
     * author 出运费
     */
    JsonVO<String> deleteById(DeleteDTO deleteDTO);

    //TODO 附件上传
    /**
     * 采购预付款操作
     * param prepaymentDTO
     * return
     * author 空
     */
    public JsonVO<String> prepaymentForPurchaseRequisitions(PrepaymentDTO prepaymentDTO);

    /**
     * 获取供应商列表
     * return 供应商列表
     * author 空
     */
    public JsonVO<List<SupplierVO>> querySupplierList();

    /**
     * 获取采购项目清单（无申请）
     * param purchaseListQuery
     * return 采购项目清单
     * author 空
     */
//    public JsonVO<PageVO<PurOrderEntryVO>> queryForPurchaseRequisitions(PurchaseListQuery purchaseListQuery);

    /**
     * 获取采购项目清单（有申请）
     * param purchaseListQuery
     * return 采购项目清单
     * author 空
     */
//    public JsonVO<PageVO<FinPaymentReqVO>> queryForAppliedPurchaseRequisitions(PurchaseListQuery purchaseListQuery);

    /**
     * 导入功能
     * author 内鬼
     */
    JsonVO<PageVO<PaymentReqEntryVO>> queryAllByBillNo(String billNo);
    JsonVO<String> excelImport(MultipartFile file);

    /**
     * 修改状态——关闭
     * author yu-hang
     */
    JsonVO<String> closeById(StatusDTO statusDTO);

    /**
     * 修改状态——反关闭
     * author yu-hang
     */
    JsonVO<String> uncloseById(StatusDTO statusDTO);

    /**
     * 修改状态——作废
     * author yu-hang
     */
    JsonVO<String> voidById(StatusDTO statusDTO);
}
