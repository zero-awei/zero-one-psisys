package com.zeroone.star.paymentmanagement.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.paymentmanagement.entity.FinPayment;
import com.zeroone.star.paymentmanagement.entity.QueryDocumentList;
import com.zeroone.star.paymentmanagement.mapper.QueryDocumentListMapper;
import com.zeroone.star.paymentmanagement.service.IQueryDocumentListService;
import com.zeroone.star.project.query.paymentmanagement.QueryDocumentListQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.paymentmanagement.QueryDocumentListVO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

@Service
public class QueryDocumentListServiceImpl extends ServiceImpl<QueryDocumentListMapper, FinPayment> implements IQueryDocumentListService {
//public class QueryDocumentListServiceImpl extends ServiceImpl<QueryDocumentListMapper, QueryDocumentList> implements IQueryDocumentListService {

    @Resource
    private QueryDocumentListMapper mapper;

    @Override
    public PageVO<QueryDocumentListVO> queryDocumentList(QueryDocumentListQuery query) {
        //构建分页对象
        Page<FinPayment> addressBookPage = new Page<>(query.getPageIndex(), query.getPageSize());
        // 执行查询
        //创建查询条件
        QueryWrapper<FinPayment> wrapper = new QueryWrapper<>();
        //这里是有申请的查询所有，故筛选条件是支付方式为2021
        wrapper.eq("payment_type","2021");
        Page<FinPayment> pages = mapper.selectPage(addressBookPage, wrapper);
        return PageVO.create(pages,QueryDocumentListVO.class);  //将pages转为返回类型QueryDocumentListVO.class进行返回。

                /*
        Page<QueryDocumentList> result = mapper.queryDocumentList(addressBookPage,query.getBillNo(),query.getSubject());
        return PageVO.create(result, QueryDocumentListVO.class);
                 */
    }
}
