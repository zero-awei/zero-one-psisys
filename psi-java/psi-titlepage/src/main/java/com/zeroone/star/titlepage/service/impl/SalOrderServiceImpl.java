package com.zeroone.star.titlepage.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.vo.homepage.SalesAmountInformationVO;
import com.zeroone.star.titlepage.entity.SalOrder;
import com.zeroone.star.titlepage.mapper.SalOrderMapper;
import com.zeroone.star.titlepage.service.ISalOrderService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * <p>
 * 销售订单 服务实现类
 * </p>
 *
 * @author yx
 * @since 2023-02-11
 */
@Service
public class SalOrderServiceImpl extends ServiceImpl<SalOrderMapper, SalOrder> implements ISalOrderService {

    @Autowired
    SalOrderMapper mapper;

    /**
     * 获取每月销售金额
     * @return 每月销售金额构成的list
     */
    @Override
    public List<SalesAmountInformationVO> listSalesAmount() {
        return mapper.listSalesAmount();
    }
}
