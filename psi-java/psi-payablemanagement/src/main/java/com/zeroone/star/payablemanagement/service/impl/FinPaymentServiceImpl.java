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
import com.zeroone.star.project.vo.payablemanagement.PayableVO;
import com.zeroone.star.project.vo.paymentmanagement.PaymentVO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;
import java.util.stream.Collectors;
@Service
public class FinPaymentServiceImpl extends ServiceImpl<FinPaymentMapper, FinPayment>
        implements IFinPaymentService {

    @Resource
    FinPaymentMapper mapper;

    @Override
    public PageVO<PaymentVO> queryBySupplierId(PaymentBySupplierQuery query) {
        List<PaymentVO> list = mapper.getBySupplierId(query);
        if (list.isEmpty()) {
            return null;
        }
        long pages = list.size() % query.getPageSize() == 0 ? list.size() / query.getPageSize() : list.size() / query.getPageSize() + 1;
        if (pages < query.getPageIndex() + 1) return null;
        return new PageVO<>(query.getPageIndex(),
                query.getPageSize(),
                (long) list.size(),
                pages,
                list.subList((int) query.getPageIndex() * (int) query.getPageSize(),
                        pages == query.getPageIndex() + 1 ? list.size() : (int) (query.getPageSize() * (query.getPageIndex() + 1))));
    }

}
