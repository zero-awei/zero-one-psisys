package com.zeroone.star.prepayment.service.impl;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.prepayment.entity.FinPaymentReq;
import com.zeroone.star.prepayment.mapper.FinPaymentReqMapper;
import com.zeroone.star.prepayment.service.IFinPaymentReqService;
import com.zeroone.star.project.query.prepayment.PurchaseListQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.prepayment.FinPaymentReqVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

/**
 * @Author: Kong
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


}
