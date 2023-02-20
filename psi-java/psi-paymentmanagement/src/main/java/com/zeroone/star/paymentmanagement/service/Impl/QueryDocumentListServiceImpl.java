package com.zeroone.star.paymentmanagement.service.Impl;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.paymentmanagement.entity.QueryDocumentList;
import com.zeroone.star.paymentmanagement.mapper.QueryDocumentListMapper;
import com.zeroone.star.paymentmanagement.service.IQueryDocumentListService;
import com.zeroone.star.project.query.paymentmanagement.QueryDocumentListQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.paymentmanagement.QueryDocumentListVO;

import javax.annotation.Resource;

public class QueryDocumentListServiceImpl extends ServiceImpl<QueryDocumentListMapper, QueryDocumentList> implements IQueryDocumentListService {

    @Resource
    private QueryDocumentListMapper mapper;

    @Override
    public PageVO<QueryDocumentListVO> queryDocumentList(QueryDocumentListQuery query) {
        //构建分页对象
        Page<QueryDocumentList> addressBookPage = new Page<>(query.getPageIndex(), query.getPageSize());
        // 执行查询
        Page<QueryDocumentList> result = mapper.queryDocumentList(addressBookPage,query);
        return PageVO.create(result, QueryDocumentListVO.class);
    }
}
