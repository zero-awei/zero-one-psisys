package com.zeroone.star.paymentmanagement.service.paymentmanagement.Impl;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.paymentmanagement.entity.FinPaymentReq;
import com.zeroone.star.paymentmanagement.mapper.FinPaymentReqMapper;
import com.zeroone.star.paymentmanagement.service.paymentmanagement.IQueryDocumentListService;
import com.zeroone.star.project.query.paymentmanagement.QueryDocumentListQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.paymentmanagement.QueryDocumentListVO;

import javax.annotation.Resource;

public class QueryDocumentListServiceImpl extends ServiceImpl<FinPaymentReqMapper, FinPaymentReq> implements IQueryDocumentListService {

    @Resource
    private FinPaymentReqMapper mapper;

    @Override
    public PageVO<QueryDocumentListVO> queryDocumentList(QueryDocumentListQuery query) {
        //构建分页对象
        Page<FinPaymentReq> addressBookPage = new Page<>(query.getPageIndex(), query.getPageSize());
        // 执行查询
        Page<FinPaymentReq> result = mapper.queryDocumentList(addressBookPage,query);
        return PageVO.create(result, QueryDocumentListVO.class);
    }
}
