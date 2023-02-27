package com.zeroone.star.payablemanagement.service.impl;

import com.alibaba.nacos.common.utils.StringUtils;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.payablemanagement.entity.FinPayable;
import com.zeroone.star.payablemanagement.entity.FinPayableCheck;
import com.zeroone.star.payablemanagement.mapper.FinPayableCheckMapper;
import com.zeroone.star.payablemanagement.service.IFinPayableCheckService;
import com.zeroone.star.project.query.payablemanagement.CheckPayableQuery;
import com.zeroone.star.project.query.payablemanagement.PayableBySupplierQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payablemanagement.CheckPayableVO;
import com.zeroone.star.project.vo.payablemanagement.PayableVO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

/**
 * <p>
 * 应付核销单 服务实现类
 * </p>
 *
 * @author j3
 * @since 2023-02-14
 */
@Service
public class FinPayableCheckServiceImpl extends ServiceImpl<FinPayableCheckMapper, FinPayableCheck> implements IFinPayableCheckService {

    @Resource
    FinPayableCheckMapper mapper;

    /**
     * 重构
     * @author spk
     * @param query 查询条件
     * @return 分页后VO
     */
    @Override
    public PageVO<CheckPayableVO> getAll(CheckPayableQuery query) {

        List<CheckPayableVO> list = mapper.getAllCheckPayable(query);
        if(list.isEmpty()) {
            return null;
        }
        return new PageVO<>(query.getPageIndex(), query.getPageSize(), (long) list.size(), (long) 100, list);
    }

    //将查询得到的单条数据逐个转换为VO
//    private static CheckPayableVO checkPayableEntityToVO(FinPayableCheck entity) {
//        CheckPayableVO vo = new CheckPayableVO();
//        vo.setId(entity.getId());
//        vo.setAmt(entity.getAmt());
//        vo.setApprovalRemark(entity.getApprovalRemark());
//
//        //批准类型 1 通过 2拒绝
//        //NPE是真的烦
//        String approvalResultTypeDictText = entity.getApprovalResultType();
//        if (approvalResultTypeDictText != null && !approvalResultTypeDictText.isEmpty()) {
//            switch (approvalResultTypeDictText) {
//                case "1": approvalResultTypeDictText = "通过"; break;
//                case "2": approvalResultTypeDictText = "拒绝"; break;
//            }
//        }
//        vo.setApprovalResultTypeDictText(approvalResultTypeDictText);
//
//        // TODO 需要去用户表里面查
//        vo.setApproverDictText(entity.getApprover());
//
//
//        vo.setAttachment(entity.getAttachment());
//        vo.setBillDate(entity.getBillDate());
//        vo.setBillNo(entity.getBillNo());
//
//        // 单据阶段 核批完 24 编制完 14 执行完 34 编制中 12 核批中 22 执行中 32 核批撤销 23 执行止 33
//        String billStageDictText = entity.getBillStage();
//        if (billStageDictText != null && !billStageDictText.isEmpty()) {
//            switch (billStageDictText) {
//                case "24": billStageDictText = "核批完"; break;
//                case "14": billStageDictText = "编制完"; break;
//                case "34": billStageDictText = "执行完"; break;
//                case "12": billStageDictText = "编制中"; break;
//                case "22": billStageDictText = "核批中"; break;
//                case "32": billStageDictText = "执行中"; break;
//                case "23": billStageDictText = "核批撤销"; break;
//                case "33": billStageDictText = "执行止"; break;
//            }
//        }
//        vo.setBillStageDictText(billStageDictText);
//
//        // TODO vo.setBillType  不知道怎么处理
//        // TODO 需要去用户表里面找
//        vo.setCreateByDictText(entity.getCreateBy());
//        vo.setCreateTime(entity.getCreateTime());
//        vo.setEffectiveTime(entity.getEffectiveTime());
//        vo.setIsAutoDictText(entity.getIsAuto() == 1 ? "是" : "否");
//        vo.setIsClosedDictText(entity.getIsClosed() == 1 ? "是" : "否");
//        //Boolean转换为Integer，再转换为String，>=是为了避免报错
//        vo.setIsEffectiveDictText(entity.getIsEffective().compareTo(false) >= 1 ? "是" : "否");
//        vo.setIsRubricDictText(entity.getIsRubric() == 1? "是" : "否");
//        vo.setIsVoidedDictText(entity.getIsVoided().compareTo(false) >= 1? "是" : "否");
//
//        // 应付核销类型 应该只有一个
//        String payableCheckTypeDictText = entity.getPayableCheckType();
//        if(payableCheckTypeDictText != null && payableCheckTypeDictText.equals("2")) {
//            payableCheckTypeDictText = "应付核销";
//        }
//        vo.setPayableCheckTypeDictText(payableCheckTypeDictText);
//
//        vo.setRemark(entity.getRemark());
//
//        // 源单类型 这个可就多了，拿脚本跑了一下，按理来说应该查表...
//        String srcBillTypeDictText = entity.getSrcBillType();
//        if(srcBillTypeDictText != null && !srcBillTypeDictText.isEmpty()) {
//            switch (srcBillTypeDictText) {
//                case "FinPayment:2021": srcBillTypeDictText = "采购付款(有申请)"; break;
//                case "FinPayment:2011": srcBillTypeDictText = "采购预付(有申请)"; break;
//                case "StkIo:101": srcBillTypeDictText = "采购入库"; break;
//                case "StkIo:201": srcBillTypeDictText = "销售出库"; break;
//                case "PurReq": srcBillTypeDictText = "采购申请"; break;
//                case "PurInquiry": srcBillTypeDictText = "采购询价"; break;
//                case "PurCompare": srcBillTypeDictText = "采购比价"; break;
//                case "PurQuot": srcBillTypeDictText = "供应报价"; break;
//                case "PurOrder": srcBillTypeDictText = "采购订单"; break;
//                case "StkCheck": srcBillTypeDictText = "库存盘点"; break;
//                case "SalOrder": srcBillTypeDictText = "销售订单"; break;
//                case "SalQuot": srcBillTypeDictText = "销售报价"; break;
//                case "FinSalInvoice:200": srcBillTypeDictText = "销售发票登记"; break;
//                case "FinPurInvoice:100": srcBillTypeDictText = "采购发票登记"; break;
//                case "FinReceivable:101": srcBillTypeDictText = "销售应收"; break;
//                case "FinReceivable:199": srcBillTypeDictText = "其他应收"; break;
//                case "FinReceipt:101": srcBillTypeDictText = "销售预收"; break;
//                case "FinReceipt:102": srcBillTypeDictText = "销售收款"; break;
//                case "FinReceipt:191": srcBillTypeDictText = "其他预收"; break;
//                case "FinReceipt:192": srcBillTypeDictText = "其他收款"; break;
//                case "FinPaymentReq:2011": srcBillTypeDictText = "采购预付申请"; break;
//                case "FinPaymentReq:2021": srcBillTypeDictText = "采购付款申请"; break;
//                case "StkIo:1011": srcBillTypeDictText = "采购退货出库"; break;
//                case "StkIo:102": srcBillTypeDictText = "盘盈入库"; break;
//                case "StkIo:191": srcBillTypeDictText = "涨吨入库"; break;
//                case "StkIo:199": srcBillTypeDictText = "其他入库"; break;
//                case "StkIo:2011": srcBillTypeDictText = "销售退货入库"; break;
//                case "StkIo:202": srcBillTypeDictText = "盘亏出库"; break;
//                case "StkIo:299": srcBillTypeDictText = "其他出库"; break;
//                case "StkIo:301": srcBillTypeDictText = "库存调拨"; break;
//                case "StkIo:801": srcBillTypeDictText = "成本调整"; break;
//                case "FinReceivableCheck:1": srcBillTypeDictText = "应收核销"; break;
//                case "FinReceiptReq:1031": srcBillTypeDictText = "销售退货退款申请"; break;
//                case "FinReceipt:1031": srcBillTypeDictText = "销售退货退款(有申请)"; break;
//                case "FinReceipt:1030": srcBillTypeDictText = "销售退货退款(无申请)"; break;
//                case "FinPayable:201": srcBillTypeDictText = "采购应付"; break;
//                case "FinPayable:299": srcBillTypeDictText = "其他应付"; break;
//                case "FinPayableCheck:2": srcBillTypeDictText = "应付核销"; break;
//                case "FinPayment:2010": srcBillTypeDictText = "采购预付(无申请)"; break;
//                case "FinPaymentReq:2911": srcBillTypeDictText = "其他预付申请"; break;
//                case "FinPayment:2911": srcBillTypeDictText = "其他预付(有申请)"; break;
//                case "FinPayment:2910": srcBillTypeDictText = "其他预付(无申请)"; break;
//                case "FinPayment:2020": srcBillTypeDictText = "采购付款(无申请)"; break;
//                case "FinPayment:203": srcBillTypeDictText = "采购退货退款"; break;
//                case "FinPaymentReq:2921": srcBillTypeDictText = "其他付款申请"; break;
//                case "FinPayment:2920": srcBillTypeDictText = "其他付款(无申请）"; break;
//                case "FinPayment:2921": srcBillTypeDictText = "其他付款(有申请)"; break;
//                case "FinSalInvoice:210": srcBillTypeDictText = "销售发票(红冲)登记"; break;
//                case "FinSalInvoice:211": srcBillTypeDictText = "销售发票(退货)登记"; break;
//                case "FinPurInvoice:110": srcBillTypeDictText = "采购发票(红冲)登记"; break;
//                case "FinPurInvoice:111": srcBillTypeDictText = "采购发票(退货)登记"; break;
//            }
//        }
//        vo.setSrcBillTypeDictText(srcBillTypeDictText);
//
//        vo.setSrcNo(entity.getSrcNo());
//        vo.setSubject(entity.getSubject());
//        // TODO 需要去供应商表里面查
//        vo.setSupplierIdDictText(entity.getSupplierId());
//        // TODO 需要去部门表里面找
//        vo.setSysOrgCodeDictText(entity.getSysOrgCode());
//        // TODO 需要去用户表里面找
//        vo.setUpdateByDictText(entity.getUpdateBy());
//        vo.setUpdateTime(entity.getUpdateTime());
//
//        return vo;
//    }
//
//    private static PageVO<CheckPayableVO> createPageVO(Page<FinPayableCheck> page) {
//        PageVO<CheckPayableVO> pageResult = new PageVO<>();
//        pageResult.setTotal(page.getTotal());
//        pageResult.setPageIndex(page.getCurrent());
//        pageResult.setPageSize(page.getSize());
//        pageResult.setPages(page.getPages());
//        //转换数据
//        List<FinPayableCheck> records = page.getRecords();
//        if (records != null && !records.isEmpty()) {
//            List<CheckPayableVO> rows = page.getRecords().stream().map(finPayableCheck -> {
//                CheckPayableVO checkPayableVO = new CheckPayableVO();
//                checkPayableVO = checkPayableEntityToVO(finPayableCheck);
//                return checkPayableVO;
//            }).collect(Collectors.toList());
//            pageResult.setRows(rows);
//        }
//        return pageResult;
//    }
}
