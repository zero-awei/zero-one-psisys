package com.zeroone.star.paymentmanagement.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.plugins.pagination.PageDTO;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.paymentmanagement.entity.FinPayment;
import com.zeroone.star.paymentmanagement.mapper.PurchasePaymentMapper;
import com.zeroone.star.paymentmanagement.service.PurchasePaymentService;
import com.zeroone.star.project.dto.paymentmanagement.purchasepayment.FinPaymentReqEntryDTO;
import com.zeroone.star.project.dto.paymentmanagement.purchasepayment.PaymentCreateDTO;
import com.zeroone.star.project.dto.paymentmanagement.purchasepayment.PaymentDeleteDTO;
import com.zeroone.star.project.dto.paymentmanagement.purchasepayment.PaymentUpdateDTO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.paymentmanagement.QueryDocumentListVO;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.math.BigDecimal;
import java.time.LocalDateTime;


/**
 * @author Tomcat - 业峰实现
 * @Date 2023/2/15 22:36
 */
@Service
public class PurchasePaymentServiceImpl extends ServiceImpl<PurchasePaymentMapper,FinPayment> implements PurchasePaymentService {
    @Autowired
    PurchasePaymentMapper purchasePaymentMapper;

    /**
     * 新增单据
     * @param paymentCreateDTO
     * @return
     */
    //TODO:新增的文件名获取、创建者、创建部门
    @Override
    public int insert(PaymentCreateDTO paymentCreateDTO) {
        //将输入的dto转弯插入数据库的entry对象
        FinPayment finPayment = new FinPayment();
        BeanUtils.copyProperties(paymentCreateDTO,finPayment);
        //对属性经处理
        //创建时间
        finPayment.setCreateTime(LocalDateTime.now());
        //将前端传来的FinPaymentReqEntryDTO对象列表的amt统计为finPayment的amt
        for(FinPaymentReqEntryDTO finPaymentReqEntry : paymentCreateDTO.getFinPaymentEntryList()){
            finPayment.setAmt(finPayment.getAmt().add(finPaymentReqEntry.getAmt()));
        }
        return purchasePaymentMapper.insert(finPayment);
    }

    /**
     * 根据单据编号删除
     * @param paymentDeleteDTO
     * @return
     */
    //TODO：删除的逻辑是用用作废标记还是直接删除
    @Override
    public int delete(PaymentDeleteDTO paymentDeleteDTO) {
        QueryWrapper<FinPayment> wrapper = new QueryWrapper<>();
        wrapper.eq("bill_no",paymentDeleteDTO.getBillNo());
        return purchasePaymentMapper.delete(wrapper);
    }

    /**
     * 根据单据编号修改
     * @param paymentUpdateDTO
     * @return
     */
    //TODO:业务逻辑的的梳理，获取实现的操作者作为修改者以及部门等信息，
    @Override
    public int update(PaymentUpdateDTO paymentUpdateDTO) {
        FinPayment finPayment = new FinPayment();
        BeanUtils.copyProperties(paymentUpdateDTO,finPayment);
        //将更新时间自动更新为现在的时间进行封装
        finPayment.setUpdateTime(LocalDateTime.now());
        UpdateWrapper<FinPayment> wrapper = new UpdateWrapper<>();
        wrapper.eq("bill_no", paymentUpdateDTO.getBillNo());
        return purchasePaymentMapper.update(finPayment, wrapper);
    }

    @Override
    public PageVO<QueryDocumentListVO> listAll(PageQuery condition) {
        Page<FinPayment> page = new Page<>(condition.getPageIndex(), condition.getPageSize());
        QueryWrapper<FinPayment> wrapper = new QueryWrapper<>();
        wrapper.eq("payment_type","2021");
        Page<FinPayment> pages = purchasePaymentMapper.selectPage(page, wrapper);
        return PageVO.create(pages,QueryDocumentListVO.class);
    }

    @Override
    public PageVO<QueryDocumentListVO> listAllUn(PageQuery condition) {
        Page<FinPayment> page = new Page<>(condition.getPageIndex(), condition.getPageSize());
        QueryWrapper<FinPayment> wrapper = new QueryWrapper<>();
        wrapper.eq("payment_type","2020");
        Page<FinPayment> pages = purchasePaymentMapper.selectPage(page, wrapper);
        return PageVO.create(pages,QueryDocumentListVO.class);
    }

    @Override
    public PageVO<QueryDocumentListVO> listRefund(PageQuery condition) {
        Page<FinPayment> page = new Page<>(condition.getPageIndex(), condition.getPageSize());
        QueryWrapper<FinPayment> wrapper = new QueryWrapper<>();
        wrapper.eq("payment_type","203");
        Page<FinPayment> pages = purchasePaymentMapper.selectPage(page, wrapper);
        return PageVO.create(pages,QueryDocumentListVO.class);
    }
}
