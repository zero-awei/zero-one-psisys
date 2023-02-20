package com.zeroone.star.prepayment.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.prepayment.entity.FinPayment;
import com.zeroone.star.prepayment.entity.FinPaymentEntry;
import com.zeroone.star.prepayment.entity.FinPaymentReq;
import com.zeroone.star.prepayment.entity.PurOrder;
import com.zeroone.star.prepayment.mapper.FinPaymentMapper;
import com.zeroone.star.prepayment.service.*;
import com.zeroone.star.project.dto.prepayment.*;
import com.zeroone.star.project.query.prepayment.DocListQuery;
import com.zeroone.star.project.query.prepayment.PreDetQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.prepayment.*;
import org.apache.poi.ss.formula.functions.T;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;

/**
 * 付款单 服务类
 * author forever爱
 * since 2023-02-13
 */
@Service
public class PrepaymentService extends ServiceImpl<FinPaymentMapper,FinPayment> implements IPrepaymentService {
    /**
     *
     * @param modifyDTO
     * @return
     * author forever爱
     */
    @Override
    public JsonVO<String> modifyById(ModifyDTO modifyDTO) {
        return null;
    }

    @Override
    public JsonVO<String> auditById(AuditDTO auditDTO) {
        return null;
    }

    @Override
    public JsonVO<PageVO<DocListVO>> queryAll(DocListQuery condition) {
        return null;
    }

    @Resource
    IFinPaymentService finPaymentService;
    @Resource
    IFinPaymentReqService finPaymentReqService;
    @Resource
    IFinPaymentEntryService finPaymentEntryService;
    @Override
    public DetHavVO queryByBillHav(PreDetQuery condition) {
        //根据查询条件里的单据编号去fin_payment查询对应付款单据
        FinPayment finPayment = finPaymentService.getByBillNo(condition.getBillNo());
        //根据对应付款单据查询所属付款申请单
        List<FinPaymentReq> finPaymentReqs = finPaymentReqService.listBySrcBillId(finPayment.getId());
        //创建返回参数中的对应申请单列表和明细列表
        List<FinPaymentReqVO> finPaymentReqVOList = new ArrayList<>();
        List<FinPaymentEntryVO> finPaymentEntryVOList = new ArrayList<>();
        //遍历每一个所属申请单去查询申请单对应明细
        for (FinPaymentReq finPaymentReq : finPaymentReqs) {
            List<FinPaymentEntry> finPaymentEntryList = finPaymentEntryService.listBySrcBillId(finPaymentReq.getId());
            //创建VO对象并将对应属性值拷贝
            FinPaymentReqVO finPaymentReqVO = new FinPaymentReqVO();
            BeanUtil.copyProperties(finPaymentReq,finPaymentReqVO);
            finPaymentReqVOList.add(finPaymentReqVO);
            for (FinPaymentEntry finPaymentEntry : finPaymentEntryList) {
                FinPaymentEntryVO finPaymentEntryVO = new FinPaymentEntryVO();
                BeanUtil.copyProperties(finPaymentEntry,finPaymentEntryVO);
                finPaymentEntryVO.setSrcBillNo(finPaymentReq.getBillNo());
                finPaymentEntryVOList.add(finPaymentEntryVO);
            }
        }
        DetHavVO detHavVO = new DetHavVO();
        BeanUtil.copyProperties(finPayment,detHavVO);
        detHavVO.setListReq(finPaymentReqVOList);
        detHavVO.setListDetail(finPaymentEntryVOList);
        return detHavVO;
    }

    @Resource
    IPurOrderService purOrderService;
    @Override
    public DetNoVO queryByBillNo(PreDetQuery condition) {
        //根据查询条件里的单据编号去fin_payment查询对应付款单据
        FinPayment finPayment = finPaymentService.getByBillNo(condition.getBillNo());
        //根据对应付款单据查询所属采购订单
        List<PurOrder> purOrders = purOrderService.listBySrcBillId(finPayment.getId());
        //创建返回参数中的对应采购订单列表和明细列表
        List<PurOrderVO> purOrderVOList = new ArrayList<>();
        List<FinPaymentEntryVO> finPaymentEntryVOList = new ArrayList<>();
        //遍历每一个所属采购订单去查询订单对应明细
        for (PurOrder purOrder : purOrders) {
            List<FinPaymentEntry> finPaymentEntryList = finPaymentEntryService.listBySrcBillId(purOrder.getId());
            //创建VO对象并将对应属性值拷贝
            PurOrderVO purOrderVO = new PurOrderVO();
            BeanUtil.copyProperties(purOrder,purOrderVO);
            purOrderVOList.add(purOrderVO);
            for (FinPaymentEntry finPaymentEntry : finPaymentEntryList) {
                FinPaymentEntryVO finPaymentEntryVO = new FinPaymentEntryVO();
                BeanUtil.copyProperties(finPaymentEntry,finPaymentEntryVO);
                finPaymentEntryVO.setSrcBillNo(purOrder.getBillNo());
                finPaymentEntryVOList.add(finPaymentEntryVO);
            }
        }
        DetNoVO detNoVO = new DetNoVO();
        BeanUtil.copyProperties(finPayment,detNoVO);
        detNoVO.setListPurOrder(purOrderVOList);
        detNoVO.setListDetail(finPaymentEntryVOList);
        return detNoVO;
    }

    @Override
    public ResponseEntity<byte[]> download() {
        return null;
    }

    @Override
    public JsonVO<String> downloadUrl() {
        return null;
    }

    @Override
    public JsonVO<String> deleteById(DeleteDTO deleteDTO) {
        return null;
    }

    @Override
    public JsonVO<String> prepaymentForPurchaseRequisitions(PrepaymentDTO prepaymentDTO) {
        return null;
    }

    @Override
    public JsonVO<List<SupplierVO>> querySupplierList() {
        return null;
    }

    @Override
    public JsonVO<PageVO<PaymentReqEntryVO>> queryAllByBillNo(String billNo) {
        return null;
    }

    @Override
    public JsonVO<String> excelImport(MultipartFile file) {
        return null;
    }

    @Override
    public JsonVO<String> closeById(StatusDTO statusDTO) {
        return null;
    }

    @Override
    public JsonVO<String> uncloseById(StatusDTO statusDTO) {
        return null;
    }

    @Override
    public JsonVO<String> voidById(StatusDTO statusDTO) {
        return null;
    }
}
