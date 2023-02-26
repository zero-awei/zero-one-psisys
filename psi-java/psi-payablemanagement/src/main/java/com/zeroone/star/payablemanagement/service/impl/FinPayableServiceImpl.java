package com.zeroone.star.payablemanagement.service.impl;

import cn.hutool.core.bean.BeanUtil;
import org.springframework.context.annotation.Bean;
import com.zeroone.star.project.query.payablemanagement.PayableBillNoQuery;
import com.alibaba.nacos.common.utils.StringUtils;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.payablemanagement.entity.FinPayable;
import com.zeroone.star.payablemanagement.mapper.FinPayableMapper;
import com.zeroone.star.payablemanagement.service.IFinPayableService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.query.payablemanagement.PayableQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payablemanagement.PayableVO;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 应付单 服务实现类
 * </p>
 *
 * @author chosen1, G.
 * @since 2023-02-14
 */
@Service
public class FinPayableServiceImpl extends ServiceImpl<FinPayableMapper, FinPayable> implements IFinPayableService {

    @Resource
    FinPayableMapper mapper;

    @Override
    public PageVO<PayableVO> getAll(PayableQuery query) {
        Page<FinPayable> payablePage = new Page<>(query.getPageIndex(), query.getPageSize());
        QueryWrapper<FinPayable> wrapper = new QueryWrapper<>();
        // TODO 编写wrapper、mapper
        Page<FinPayable> result = baseMapper.selectPage(payablePage, wrapper);
        return PageVO.create(result, PayableVO.class);
    }

    @Override
    public PayableVO getById(PayableBillNoQuery query) {
        QueryWrapper<FinPayable> wrapper = new QueryWrapper<>();
        wrapper.eq("bill_no", query.getBillNO());
        FinPayable finPayable = baseMapper.selectOne(wrapper);
        PayableVO payableVO = new PayableVO();
        // TODO 待完成 编写wrapper mapper
        BeanUtil.copyProperties(finPayable, payableVO);
        return payableVO;
    }


    public PageVO<PayableVO> queryAll(PayableQuery query) {
        List<PayableVO> list = mapper.queryPayable(query);
        if (list.isEmpty()) {
            return null;
        }
        return new PageVO<>(query.getPageIndex(), query.getPageSize(), (long) list.size(), (long) 100, list);
    }

    @Override
    public PayableVO getByBillNo(String billNo) {
        return mapper.getOneByBillNo(billNo);
    }
}
