package com.zeroone.star.paymentmanagement.service.impl;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.paymentmanagement.entity.FinPaymentReqEntry;
import com.zeroone.star.paymentmanagement.entity.QueryDocumentList;
import com.zeroone.star.paymentmanagement.mapper.FinPaymentReqEntryMapper;
import com.zeroone.star.paymentmanagement.mapper.QueryDocumentListMapper;
import com.zeroone.star.paymentmanagement.service.IViewSpecifiedDocInfService;
import com.zeroone.star.project.query.paymentmanagement.QueryDocumentListQuery;
import com.zeroone.star.project.query.paymentmanagement.ViewSpecifiedDocInfQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.paymentmanagement.QueryDocumentListVO;
import com.zeroone.star.project.vo.paymentmanagement.ViewSpecifiedDocInfVO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
@Service
public class ViewSpecifiedDocInfServiceImpl extends ServiceImpl<FinPaymentReqEntryMapper, FinPaymentReqEntry> implements IViewSpecifiedDocInfService {

    @Resource
    private FinPaymentReqEntryMapper mapper;

    @Override
    public PageVO<ViewSpecifiedDocInfVO> viewSpecifiedDocInf(ViewSpecifiedDocInfQuery query) {
        //构建分页对象
        Page<FinPaymentReqEntry> viewSpecifiedDocInfPage = new Page<>(1, 10);
        // 执行查询
        Page<FinPaymentReqEntry> result = mapper.viewSpecifiedDocInf(viewSpecifiedDocInfPage,query.getBillNo());
        return PageVO.create(result, ViewSpecifiedDocInfVO.class);
    }

}
