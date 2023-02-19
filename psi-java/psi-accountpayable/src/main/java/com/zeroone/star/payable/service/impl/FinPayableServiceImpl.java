package com.zeroone.star.payable.service.impl;


import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.payable.entity.FinPayable;
import com.zeroone.star.payable.mapper.FinPayableMapper;
import com.zeroone.star.payable.service.IFinPayableService;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.query.patable.purchase.MultiConditionPayableQuery;
import com.zeroone.star.project.query.patable.purchase.PayableQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payable.purchase.FinPayableVO;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * <p>
 * 应付单 服务实现类
 * </p>
 *
 * @author chosen1
 * @since 2023-02-14
 */
@Service
public class FinPayableServiceImpl extends ServiceImpl<FinPayableMapper, FinPayable> implements IFinPayableService {

    @Override
    public PageVO<FinPayableVO> getAll(MultiConditionPayableQuery query) {
        Page<FinPayable> payablePage = new Page<>(query.getPageIndex(), query.getPageSize());
        QueryWrapper<FinPayable> wrapper = new QueryWrapper<>();
        // TODO 编写wrapper、mapper
        Page<FinPayable> result = baseMapper.selectPage(payablePage, wrapper);
        return PageVO.create(result, FinPayableVO.class);
    }

    @Override
    public FinPayableVO getById(PayableQuery query) {
        QueryWrapper<FinPayable> wrapper = new QueryWrapper<>();
        wrapper.eq("bill_no", query.getBillNO());
        FinPayable finPayable = baseMapper.selectOne(wrapper);
        FinPayableVO finPayableVO = new FinPayableVO();
        // TODO 待完成 编写wrapper mapper
        BeanUtil.copyProperties(finPayable, finPayableVO);
        return finPayableVO;
    }
}
