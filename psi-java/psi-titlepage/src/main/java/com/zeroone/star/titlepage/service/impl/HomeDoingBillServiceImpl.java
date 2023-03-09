package com.zeroone.star.titlepage.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.homepage.HomeDoingBillVO;
import com.zeroone.star.project.vo.homepage.SalOrderVO;
import com.zeroone.star.titlepage.entity.HomeDoingBill;
import com.zeroone.star.titlepage.entity.SalOrder;
import com.zeroone.star.titlepage.mapper.HomeDoingBillMapper;
import com.zeroone.star.titlepage.mapper.SalOrderMapper;
import com.zeroone.star.titlepage.service.IHomeDoingBillService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * VIEW 服务实现类
 * </p>
 *
 * @author ss
 * @since 2023-02-12
 */
@Service
public class HomeDoingBillServiceImpl extends ServiceImpl<HomeDoingBillMapper, HomeDoingBill> implements IHomeDoingBillService {

    @Autowired
    HomeDoingBillMapper mapper;
    @Override
    public List<HomeDoingBillVO> listHomeDoingBill() {
        //查询处理中单据，没有条件
        List<HomeDoingBill> list = mapper.selectList(null);
        List<HomeDoingBillVO> list1=new ArrayList<>();
        //遍历将list中的数据转化为list1中
        for (HomeDoingBill homeDoingBill : list) {
            HomeDoingBillVO homeDoingBillVO = new HomeDoingBillVO();
            BeanUtil.copyProperties(homeDoingBill,homeDoingBillVO);
            list1.add(homeDoingBillVO);
        }
        return list1;
    }
    public HomeDoingBillVO getByName(String name){
        HomeDoingBill homeDoingBill = baseMapper.selectbyName(name);
        HomeDoingBillVO homeDoingBillVO = new HomeDoingBillVO();
        BeanUtil.copyProperties(homeDoingBill,homeDoingBillVO);
        return homeDoingBillVO;
    }

}
