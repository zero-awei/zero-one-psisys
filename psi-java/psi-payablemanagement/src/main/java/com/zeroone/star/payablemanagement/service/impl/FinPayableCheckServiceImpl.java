package com.zeroone.star.payablemanagement.service.impl;

import com.alibaba.nacos.common.utils.StringUtils;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.payablemanagement.entity.FinPayable;
import com.zeroone.star.payablemanagement.entity.FinPayableCheck;
import com.zeroone.star.payablemanagement.mapper.FinPayableCheckMapper;
import com.zeroone.star.payablemanagement.service.IFinPayableCheckService;
import com.zeroone.star.project.query.payablemanagement.CheckPayableQuery;
import com.zeroone.star.project.query.payablemanagement.PayableBySupplierQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payablemanagement.CheckPayableVO;
import com.zeroone.star.project.vo.payablemanagement.PayableVO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

/**
 * <p>
 * 应付核销单 服务实现类
 * </p>
 *
 * @author j3
 * @since 2023-02-14
 */
@Service
public class FinPayableCheckServiceImpl extends ServiceImpl<FinPayableCheckMapper, FinPayableCheck> implements IFinPayableCheckService {

    @Resource
    FinPayableCheckMapper mapper;

    /**
     * 重构
     * @author spk
     * @param query 查询条件
     * @return 分页后VO
     */
    @Override
    public PageVO<CheckPayableVO> getAll(CheckPayableQuery query) {

        List<CheckPayableVO> list = mapper.getAllCheckPayable(query);
        if(list.isEmpty()) {
            return null;
        }
        return new PageVO<>(query.getPageIndex(), query.getPageSize(), (long) list.size(), (long) 100, list);
    }
}
