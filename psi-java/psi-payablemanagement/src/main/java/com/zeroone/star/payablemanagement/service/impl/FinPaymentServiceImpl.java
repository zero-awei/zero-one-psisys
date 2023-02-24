package com.zeroone.star.payablemanagement.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.payablemanagement.entity.FinPayment;
import com.zeroone.star.payablemanagement.mapper.FinPaymentMapper;
import com.zeroone.star.payablemanagement.service.IFinPaymentService;
import com.zeroone.star.project.query.payablemanagement.PaymentBySupplierQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payablemanagement.CheckPayableVO;
import com.zeroone.star.project.vo.paymentmanagement.PaymentVO;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.stream.Collectors;
@Service
public class FinPaymentServiceImpl extends ServiceImpl<FinPaymentMapper, FinPayment>
        implements IFinPaymentService {

    @Override
    public PageVO<PaymentVO> queryBySupplierId(PaymentBySupplierQuery query) {
        //构建分页对象
        Page<FinPayment> page = new Page<>(query.getPageIndex(), query.getPageSize());
        //构建查询条件
        QueryWrapper<FinPayment> wrapper = new QueryWrapper<>();
        //1. 供应商ID
        wrapper.eq("supplier_id", query.getSupplierId());
        //执行分页查询
        Page<FinPayment> result = baseMapper.selectPage(page, wrapper);

        return createPageVO(result);
    }

    private static PaymentVO paymentEntityToVO(FinPayment entity) {
        PaymentVO vo = new PaymentVO();

        vo.setBillNo(entity.getBillNo());
        vo.setBillDate(entity.getBillDate().atStartOfDay());

        // 源单类型 这个可就多了，拿脚本跑了一下，按理来说应该查表...
        String srcBillTypeDictText = entity.getSrcBillType();
        if(srcBillTypeDictText != null && !srcBillTypeDictText.isEmpty()) {
            switch (srcBillTypeDictText) {
                case "FinPayment:2021": srcBillTypeDictText = "采购付款(有申请)"; break;
                case "FinPayment:2011": srcBillTypeDictText = "采购预付(有申请)"; break;
                case "StkIo:101": srcBillTypeDictText = "采购入库"; break;
                case "StkIo:201": srcBillTypeDictText = "销售出库"; break;
                case "PurReq": srcBillTypeDictText = "采购申请"; break;
                case "PurInquiry": srcBillTypeDictText = "采购询价"; break;
                case "PurCompare": srcBillTypeDictText = "采购比价"; break;
                case "PurQuot": srcBillTypeDictText = "供应报价"; break;
                case "PurOrder": srcBillTypeDictText = "采购订单"; break;
                case "StkCheck": srcBillTypeDictText = "库存盘点"; break;
                case "SalOrder": srcBillTypeDictText = "销售订单"; break;
                case "SalQuot": srcBillTypeDictText = "销售报价"; break;
                case "FinSalInvoice:200": srcBillTypeDictText = "销售发票登记"; break;
                case "FinPurInvoice:100": srcBillTypeDictText = "采购发票登记"; break;
                case "FinReceivable:101": srcBillTypeDictText = "销售应收"; break;
                case "FinReceivable:199": srcBillTypeDictText = "其他应收"; break;
                case "FinReceipt:101": srcBillTypeDictText = "销售预收"; break;
                case "FinReceipt:102": srcBillTypeDictText = "销售收款"; break;
                case "FinReceipt:191": srcBillTypeDictText = "其他预收"; break;
                case "FinReceipt:192": srcBillTypeDictText = "其他收款"; break;
                case "FinPaymentReq:2011": srcBillTypeDictText = "采购预付申请"; break;
                case "FinPaymentReq:2021": srcBillTypeDictText = "采购付款申请"; break;
                case "StkIo:1011": srcBillTypeDictText = "采购退货出库"; break;
                case "StkIo:102": srcBillTypeDictText = "盘盈入库"; break;
                case "StkIo:191": srcBillTypeDictText = "涨吨入库"; break;
                case "StkIo:199": srcBillTypeDictText = "其他入库"; break;
                case "StkIo:2011": srcBillTypeDictText = "销售退货入库"; break;
                case "StkIo:202": srcBillTypeDictText = "盘亏出库"; break;
                case "StkIo:299": srcBillTypeDictText = "其他出库"; break;
                case "StkIo:301": srcBillTypeDictText = "库存调拨"; break;
                case "StkIo:801": srcBillTypeDictText = "成本调整"; break;
                case "FinReceivableCheck:1": srcBillTypeDictText = "应收核销"; break;
                case "FinReceiptReq:1031": srcBillTypeDictText = "销售退货退款申请"; break;
                case "FinReceipt:1031": srcBillTypeDictText = "销售退货退款(有申请)"; break;
                case "FinReceipt:1030": srcBillTypeDictText = "销售退货退款(无申请)"; break;
                case "FinPayable:201": srcBillTypeDictText = "采购应付"; break;
                case "FinPayable:299": srcBillTypeDictText = "其他应付"; break;
                case "FinPayableCheck:2": srcBillTypeDictText = "应付核销"; break;
                case "FinPayment:2010": srcBillTypeDictText = "采购预付(无申请)"; break;
                case "FinPaymentReq:2911": srcBillTypeDictText = "其他预付申请"; break;
                case "FinPayment:2911": srcBillTypeDictText = "其他预付(有申请)"; break;
                case "FinPayment:2910": srcBillTypeDictText = "其他预付(无申请)"; break;
                case "FinPayment:2020": srcBillTypeDictText = "采购付款(无申请)"; break;
                case "FinPayment:203": srcBillTypeDictText = "采购退货退款"; break;
                case "FinPaymentReq:2921": srcBillTypeDictText = "其他付款申请"; break;
                case "FinPayment:2920": srcBillTypeDictText = "其他付款(无申请）"; break;
                case "FinPayment:2921": srcBillTypeDictText = "其他付款(有申请)"; break;
                case "FinSalInvoice:210": srcBillTypeDictText = "销售发票(红冲)登记"; break;
                case "FinSalInvoice:211": srcBillTypeDictText = "销售发票(退货)登记"; break;
                case "FinPurInvoice:110": srcBillTypeDictText = "采购发票(红冲)登记"; break;
                case "FinPurInvoice:111": srcBillTypeDictText = "采购发票(退货)登记"; break;
            }
        }
        vo.setSrcBillTypeDictText(srcBillTypeDictText);

        vo.setSrcNo(entity.getSrcNo());
        vo.setSubject(entity.getSubject());
        vo.setIsRubricDictText(entity.getIsRubric() == 1? "是" : "否");

        // 付款类型
        String paymentTypeDictText = entity.getPaymentType();
        if(paymentTypeDictText != null && !paymentTypeDictText.isEmpty()) {
            switch (paymentTypeDictText) {
                case "2010": paymentTypeDictText = "采购预付(无申请)"; break;
                case "2021": paymentTypeDictText = "采购付款(有申请)"; break;
                case "2920": paymentTypeDictText = "其他付款(无申请)"; break;
                case "2011": paymentTypeDictText = "采购预付(有申请)"; break;
                case "2020": paymentTypeDictText = "采购付款(无申请)"; break;
                case "2921": paymentTypeDictText = "其他付款(有申请)"; break;
                case "2911": paymentTypeDictText = "其他预付(有申请)"; break;
                case "2910": paymentTypeDictText = "其他预付(无申请)"; break;
            }
        }
        vo.setPaymentTypeDictText(paymentTypeDictText);
        //TODO 需要去供应商表里面找
        vo.setSupplierIdDicText(entity.getSupplierId());
        vo.setAmt(entity.getAmt());
        vo.setCheckedAmt(entity.getCheckedAmt());
//        vo.setUncheckedAmt()
        vo.setAttachment(entity.getAttachment());
        vo.setRemark(entity.getRemark());
        vo.setIsAutoDictText(entity.getIsAuto() == 1 ? "是" : "否");

        // 单据阶段
        String billStageDictText = entity.getBillStage();
        if (billStageDictText != null && !billStageDictText.isEmpty()) {
            switch (billStageDictText) {
                case "24": billStageDictText = "核批完"; break;
                case "14": billStageDictText = "编制完"; break;
                case "34": billStageDictText = "执行完"; break;
                case "12": billStageDictText = "编制中"; break;
                case "22": billStageDictText = "核批中"; break;
                case "32": billStageDictText = "执行中"; break;
                case "23": billStageDictText = "核批撤销"; break;
                case "33": billStageDictText = "执行止"; break;
            }
        }
        vo.setBillStageDictText(billStageDictText);


        //TODO 需要去用户表里面找
        vo.setApproverDictText(entity.getApprover());

        //核批类型
        String approvalResultTypeDictText = entity.getApprovalResultType();
        if (approvalResultTypeDictText != null && !approvalResultTypeDictText.isEmpty()) {
            switch (approvalResultTypeDictText) {
                case "1": approvalResultTypeDictText = "通过"; break;
                case "2": approvalResultTypeDictText = "拒绝"; break;
            }
        }
        vo.setApprovalResultTypeDictText(approvalResultTypeDictText);

        vo.setApprovalRemark(entity.getApprovalRemark());
        vo.setIsEffectiveDictText(entity.getIsEffective() == 1? "是" : "否");
        vo.setEffectiveTime(entity.getEffectiveTime());
        vo.setIsClosedDictText(entity.getIsClosed() == 1? "是" : "否");
        vo.setIsVoidedDictText(entity.getIsVoided().compareTo(false) >= 1? "是": "否");
        //TODO 需要查表
        vo.setSysOrgCodeDictText(entity.getSysOrgCode());
        //TODO 需要查表
        vo.setCreateByDictText(entity.getCreateBy());
        vo.setCreateTime(entity.getCreateTime());
        //TODO 需要查表
        vo.setUpdateByDictText(entity.getUpdateBy());
        vo.setUpdateTime(entity.getUpdateTime());

        return vo;
    }

    private static PageVO<PaymentVO> createPageVO(Page<FinPayment> page) {
        PageVO<PaymentVO> pageResult = new PageVO<>();
        pageResult.setTotal(page.getTotal());
        pageResult.setPageIndex(page.getCurrent());
        pageResult.setPageSize(page.getSize());
        pageResult.setPages(page.getPages());
        //转换数据
        List<FinPayment> records = page.getRecords();
        if (records != null && !records.isEmpty()) {
            List<PaymentVO> rows = page.getRecords().stream().map(finPayment -> {
                PaymentVO paymentVO = new PaymentVO();
                paymentVO = paymentEntityToVO(finPayment);
                return paymentVO;
            }).collect(Collectors.toList());
            pageResult.setRows(rows);
        }
        return pageResult;
    }

}
