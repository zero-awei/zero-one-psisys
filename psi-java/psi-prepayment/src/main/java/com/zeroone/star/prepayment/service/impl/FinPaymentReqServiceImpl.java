package com.zeroone.star.prepayment.service.impl;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.prepayment.entity.FinPaymentReq;
import com.zeroone.star.prepayment.mapper.FinPaymentReqMapper;
import com.zeroone.star.prepayment.service.IFinPaymentReqService;
import com.zeroone.star.project.query.prepayment.PurchaseListQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.prepayment.FinPaymentReqVO;
import com.zeroone.star.project.vo.prepayment.ReqVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import com.zeroone.star.project.query.prepayment.FinPaymentReqQuery;
/**
 * Author: Kong
 */

@Service
public class FinPaymentReqServiceImpl extends ServiceImpl<FinPaymentReqMapper, FinPaymentReq> implements IFinPaymentReqService {

    @Autowired
    FinPaymentReqMapper finPaymentReqMapper;

    @Override
    public PageVO<FinPaymentReqVO> getFinPaymentReq(PurchaseListQuery condition) {
        //分页对象
        Page<FinPaymentReq> page = new Page<>(condition.getPageIndex(),condition.getPageSize());
        QueryWrapper<FinPaymentReq> wrapper = new QueryWrapper<>();
        wrapper.eq("supplier_id",condition.getSelf_supplier_id());
        if (condition.getSelf_payment_type()!=null){
            wrapper.eq("payment_type",condition.getSelf_payment_type());
        }
        if (condition.getSelf_is_closed()!=null){
            wrapper.eq("is_closed",condition.getSelf_payment_type());
        }
        //执行分页查询
        Page<FinPaymentReq> res = finPaymentReqMapper.selectPage(page, wrapper);
        return PageVO.create(res,FinPaymentReqVO.class);
    }

    @Override
    public FinPaymentReq getBySrcBillId(String srcBillId) {
        QueryWrapper<FinPaymentReq> FinReqQueryWrapper = new QueryWrapper<>();
        FinReqQueryWrapper.eq("id",srcBillId);
        FinPaymentReq finPaymentReq = baseMapper.selectOne(FinReqQueryWrapper);
        if(finPaymentReq!=null)
            return finPaymentReq;
        return null;
    }
    @Override
    public PageVO<ReqVO> listFinPaymentReq(FinPaymentReqQuery query) {
        // 构建分页对象
        Page<FinPaymentReq> paymentReqPage = new Page<>(query.getPageIndex(), query.getPageSize());
        // 构建查询条件
        QueryWrapper<FinPaymentReq> paymentReqQueryWrapper = new QueryWrapper<>();
        // 获取供应商id
        String supplierId = query.getSupplierId();
//        if (StrUtil.isNotBlank(supplierId)) {
//            paymentReqQueryWrapper.eq("supplier_id", supplierId);
//        }
        paymentReqQueryWrapper.eq("supplier_id", supplierId);
        // 约束单据日期
//        LocalDate stDate = query.getStartDate();
//        LocalDate edDate = query.getEndDate();
//        if (stDate != null && edDate != null && stDate.isBefore(edDate)) {
//            paymentReqQueryWrapper.between("billDate", stDate, edDate);
//        } else if (stDate != null && edDate == null) {
//            paymentReqQueryWrapper.gt("billDate", stDate);
//        } else if (stDate == null && edDate != null) {
//            paymentReqQueryWrapper.lt("billDate", edDate);
//        }
        // 执行分页查询
        Page<FinPaymentReq> resPage = baseMapper.selectPage(paymentReqPage, paymentReqQueryWrapper);
        return PageVO.create(resPage, ReqVO.class);
    }
}
