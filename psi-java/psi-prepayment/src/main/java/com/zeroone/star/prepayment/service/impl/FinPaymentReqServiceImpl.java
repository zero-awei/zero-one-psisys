package com.zeroone.star.prepayment.service.impl;

import cn.hutool.core.util.StrUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.prepayment.entity.FinPaymentReq;
import com.zeroone.star.prepayment.mapper.FinPaymentReqMapper;
import com.zeroone.star.prepayment.service.IFinPaymentReqService;
import com.zeroone.star.project.query.prepayment.FinPaymentReqQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.prepayment.FinPaymentReqVO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.time.LocalDate;
import java.util.List;


/**
 * @ClassName FinPaymentReqServiceImpl
 * @Description IFinPaymentReqService服务类的实现
 * @Author HZP
 * @Date 2023/2/18 22:00
 * @Version 1.0
 **/
@Service
public class FinPaymentReqServiceImpl extends ServiceImpl<FinPaymentReqMapper, FinPaymentReq> implements IFinPaymentReqService {

    @Override
    public PageVO<FinPaymentReqVO> listFinPaymentReq(FinPaymentReqQuery query) {
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
        return PageVO.create(resPage, FinPaymentReqVO.class);
    }

    @Override
    public List<FinPaymentReq> listBySrcBillId(String id) {
        return null;
    }

}
