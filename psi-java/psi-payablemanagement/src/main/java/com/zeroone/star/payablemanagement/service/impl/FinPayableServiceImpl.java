package com.zeroone.star.payablemanagement.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.zeroone.star.project.query.payablemanagement.PayableBySupplierQuery;
import org.springframework.context.annotation.Bean;
import com.zeroone.star.project.query.payablemanagement.PayableBillNoQuery;
import com.alibaba.nacos.common.utils.StringUtils;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.payablemanagement.entity.FinPayable;
import com.zeroone.star.payablemanagement.mapper.FinPayableMapper;
import com.zeroone.star.payablemanagement.service.IFinPayableService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.query.payablemanagement.PayableQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payablemanagement.PayableVO;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.stream.Collectors;

/**
 * <p>
 * 应付单 服务实现类
 * </p>
 *
 * @author chosen1, G.
 * @since 2023-02-14
 */
@Service
public class FinPayableServiceImpl extends ServiceImpl<FinPayableMapper, FinPayable> implements IFinPayableService {

    @Override
    public PageVO<PayableVO> getAll(PayableQuery query) {
        Page<FinPayable> payablePage = new Page<>(query.getPageIndex(), query.getPageSize());
        QueryWrapper<FinPayable> wrapper = new QueryWrapper<>();
        // TODO 编写wrapper、mapper
        Page<FinPayable> result = baseMapper.selectPage(payablePage, wrapper);
        return PageVO.create(result, PayableVO.class);
    }

    @Override
    public PayableVO getByBillNO(PayableBillNoQuery query) {
        QueryWrapper<FinPayable> wrapper = new QueryWrapper<>();
        wrapper.eq("bill_no", query.getBillNO());
        FinPayable finPayable = baseMapper.selectOne(wrapper);
        PayableVO payableVO = new PayableVO();
        // TODO 待完成 编写wrapper mapper
        BeanUtil.copyProperties(finPayable, payableVO);
        return payableVO;
    }


    public PageVO<PayableVO> queryAll(PayableQuery query) {
        // 构建分页对象
        Page<FinPayable> finPayablePage = new Page<>(query.getPageIndex(), query.getPageSize());
        // 构建查询条件
        QueryWrapper<FinPayable> finPayableQueryWrapper = new QueryWrapper<>();
        // 1.单据编号查询
        finPayableQueryWrapper.eq(StringUtils.hasText(query.getBillNo()), "bill_no", query.getBillNo());
        // 2.单据日期查询
        if(query.getBillDateBegin() != null){
            // 条件为空时，报空指针异常，换为if判断
            //finPayableQueryWrapper.ge(StringUtils.hasText(query.getBillDate_begin().toString()),"bill_date", query.getBillDate_begin());
            //finPayableQueryWrapper.le(StringUtils.hasText(query.getBillDate_end().toString()),"bill_date", query.getBillDate_end());
            finPayableQueryWrapper.ge("bill_date", query.getBillDateBegin());
        }
        if(query.getBillDateEnd() != null){
            finPayableQueryWrapper.le("bill_date", query.getBillDateEnd());
        }
        // 3.单据主题查询
        finPayableQueryWrapper.eq(StringUtils.hasText(query.getSubject()), "subject", query.getSubject());
        // 4.供应商查询
        finPayableQueryWrapper.eq(StringUtils.hasText(query.getSupplierId()), "supplier_id", query.getSupplierId());
        // 5.单据阶段查询
        finPayableQueryWrapper.eq(StringUtils.hasText(query.getBillStage()), "bill_stage", query.getBillStage());
        // 6.已生效(与日期查询问题一样，换为if判断)
        if(query.getIsEffective() != null){
            finPayableQueryWrapper.eq("is_effective", query.getIsEffective());
        }
        // 7.已关闭
        if(query.getIsClosed() != null){
            finPayableQueryWrapper.eq("is_closed", query.getIsClosed());
        }
        // 8.已作废
        if(query.getIsVoided() != null){
            finPayableQueryWrapper.eq("is_voided", query.getIsVoided());
        }
        // 执行分页查询
        Page<FinPayable> result = baseMapper.selectPage(finPayablePage, finPayableQueryWrapper);
        return PageVO.create(result,PayableVO.class);
    }

    @Override
    public PayableVO getByBillNo(String billNo) {
        // 构建查询条件
        QueryWrapper<FinPayable> wrapper = new QueryWrapper<>();
        wrapper.eq("bill_no", billNo);
        // 执行查询
        FinPayable f = baseMapper.selectOne(wrapper);
        // 返回结果
        if(f == null){
            return null;
        }
        PayableVO payableVO = new PayableVO();
        BeanUtil.copyProperties(f, payableVO);
        return payableVO;
    }

    @Override
    public PageVO<PayableVO> queryPayableBySupplierId(PayableBySupplierQuery query) {
        // 构建分页对象
        Page<FinPayable> page = new Page<>(query.getPageIndex(), query.getPageSize());
        // 构建查询条件
        QueryWrapper<FinPayable> wrapper = new QueryWrapper<>();
        // 供应商Id
        wrapper.eq("supplier_id", query.getSupplierId());
        //执行分页查询
        Page<FinPayable> result = baseMapper.selectPage(page, wrapper);
        return createPageVO(result);

    }

    private static PageVO<PayableVO> createPageVO(Page<FinPayable> page) {
        PageVO<PayableVO> pageResult = new PageVO<>();
        pageResult.setTotal(page.getTotal());
        pageResult.setPageIndex(page.getCurrent());
        pageResult.setPageSize(page.getSize());
        pageResult.setPages(page.getPages());
        //转换数据
        List<FinPayable> records = page.getRecords();
        if (records != null && !records.isEmpty()) {
            List<PayableVO> rows = page.getRecords().stream().map(finPayable -> {
                PayableVO payableVO = new PayableVO();
                payableVO = payableEntityToVO(finPayable);
                return payableVO;
            }).collect(Collectors.toList());
            pageResult.setRows(rows);
        }
        return pageResult;
    }

    private static PayableVO payableEntityToVO(FinPayable entity) {
        PayableVO vo = new PayableVO();

        vo.setAmt(entity.getAmt());
        vo.setApprovalRemark(entity.getApprovalRemark());
        String approvalResultTypeDictText = entity.getApprovalResultType();
        if (approvalResultTypeDictText != null && !approvalResultTypeDictText.isEmpty()) {
            switch (approvalResultTypeDictText) {
                case "1": approvalResultTypeDictText = "通过"; break;
                case "2": approvalResultTypeDictText = "拒绝"; break;
            }
        }
        vo.setApprovalResultTypeDictText(approvalResultTypeDictText);
        // TODO 估计是用户表
        vo.setApproverDictText(entity.getApprover());
        vo.setAttachment(entity.getAttachment());
        vo.setBillDate(entity.getBillDate());
        vo.setBillNo(entity.getBillNo());
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

        vo.setCheckedAmt(entity.getCheckedAmt());
        //TODO 用户表
        vo.setCreateByDictText(entity.getCreateBy());
        vo.setCreateTime(entity.getCreateTime());
        vo.setEffectiveTime(entity.getEffectiveTime());
        vo.setIsAutoDictText(entity.getIsAuto() == 1 ? "是": "否");
        vo.setIsClosedDictText(entity.getIsClosed() == 1 ? "是" : "否");
        vo.setIsEffectiveDictText(entity.getIsEffective() == 1 ? "是" : "否");
        vo.setIsRubricDictText(entity.getIsRubric() == 1? "是" : "否");
        vo.setIsVoidedDictText(entity.getIsVoided() == 1? "是" : "否");
        // TODO 估计得查别的表
        vo.setOpDeptDictText(entity.getOpDept());
        //TODO 估计是用户表
        vo.setOperatorDictText(entity.getOperator());
        vo.setRemark(entity.getRemark());
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
        //TODO 需要查表
        vo.setSupplierIdDictText(entity.getSupplierId());
        vo.setSysOrgCodeDictText(entity.getSysOrgCode());
        vo.setUpdateByDictText(entity.getUpdateBy());
        vo.setUpdateTime(entity.getUpdateTime());

        return vo;
    }



}
