package com.zeroone.star.payable.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.payable.entity.FinPayable;
import com.zeroone.star.payable.mapper.FinPayableMapper;
import com.zeroone.star.payable.service.IFinPayableService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.query.payable.FinPayableQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.accountPayable.otherPayable.OtherPayableVO;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 应付单 服务实现类
 * </p>
 *
 * @author j3
 * @since 2023-02-14
 */
@Service
public class FinPayableServiceImpl extends ServiceImpl<FinPayableMapper, FinPayable> implements IFinPayableService {

    @Override
    public PageVO<OtherPayableVO> queryAll(FinPayableQuery query) {
        // 构建分页对象
        Page<FinPayable> finPayablePage = new Page<>(query.getPageIndex(), query.getPageSize());
        // 构建查询条件
        QueryWrapper<FinPayable> finPayableQueryWrapper = new QueryWrapper<>();
        finPayableQueryWrapper.like("bill_no",query.getBill_no());
        // 执行分页查询
        Page<FinPayable> result = baseMapper.selectPage(finPayablePage, finPayableQueryWrapper);
        return PageVO.create(result,OtherPayableVO.class);
    }

    @Override
    public PageVO<OtherPayableVO> listAll(PageQuery query) {
        // 构建分页对象
        Page<FinPayable> finPayablePage = new Page<>(query.getPageIndex(), query.getPageSize());
        // 构建查询条件
        QueryWrapper<FinPayable> finPayableQueryWrapper = new QueryWrapper<>();
        finPayableQueryWrapper.select();
        // 执行分页查询
        Page<FinPayable> result = baseMapper.selectPage(finPayablePage, finPayableQueryWrapper);
        return PageVO.create(result,OtherPayableVO.class);
    }

    @Override
    public OtherPayableVO getByBillNo(String billNo) {
        FinPayable finPayable = baseMapper.selectById(billNo);
        if(finPayable != null){
            OtherPayableVO finPayableVO = new OtherPayableVO();
            BeanUtil.copyProperties(finPayable, finPayableVO);
            return finPayableVO;
        }
        return null;
    }
}
