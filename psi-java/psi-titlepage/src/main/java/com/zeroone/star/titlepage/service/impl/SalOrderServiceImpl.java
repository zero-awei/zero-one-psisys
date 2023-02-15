package com.zeroone.star.titlepage.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.vo.homepage.SalOrderVO;
import com.zeroone.star.titlepage.entity.SalOrder;
import com.zeroone.star.titlepage.mapper.SalOrderMapper;
import com.zeroone.star.titlepage.service.ISalOrderService;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
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
 * @author ss yx
 * @since 2023-02-12
 */
@Service
public class SalOrderServiceImpl extends ServiceImpl<SalOrderMapper, SalOrder> implements ISalOrderService {

    @Autowired
    SalOrderMapper mapper;

    /**
     * 查询毛利润
     * @return
     */

    @Override
    public List<SalOrderVO> listSalOrder() {
        //调用方法查询毛利润
        List<SalOrder> list = baseMapper.querySalOrder();
        List<SalOrderVO> list1=new ArrayList<>();
        //list里的元素转化为VO类型
        for (SalOrder salOrder : list) {
            SalOrderVO salOrderVO = new SalOrderVO();
            BeanUtil.copyProperties(salOrder,salOrderVO);
            list1.add(salOrderVO);
        }
        return list1;


    /**
     * 获取每月销售金额
     * @return 每月销售金额构成的list
     */
    @Override
    public List<SalesAmountInformationVO> listSalesAmount() {
        return mapper.listSalesAmount();
    }
}
