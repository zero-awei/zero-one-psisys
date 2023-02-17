package com.zeroone.star.paymentmanagement.mapper;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.paymentmanagement.entity.QueryDocumentList;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.query.paymentmanagement.QueryDocumentListQuery;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 * 付款申请单 Mapper 接口
 * </p>
 *
 * @author achuan
 * @since 2023-02-13
 */
@Mapper
public interface QueryDocumentListMapper extends BaseMapper<QueryDocumentList> {
    public Page<QueryDocumentList> queryDocumentList(Page page, QueryDocumentListQuery condition);
}
