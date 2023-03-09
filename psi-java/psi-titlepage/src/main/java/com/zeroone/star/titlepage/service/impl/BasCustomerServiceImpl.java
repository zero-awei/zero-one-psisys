package com.zeroone.star.titlepage.service.impl;

import com.alibaba.excel.util.DateUtils;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.vo.homepage.CustomerInformationVO;
import com.zeroone.star.titlepage.entity.BasCustomer;
import com.zeroone.star.titlepage.mapper.BasCustomerMapper;
import com.zeroone.star.titlepage.service.IBasCustomerService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.HashMap;
import java.util.List;

/**
 * <p>
 * 客户 服务实现类
 * </p>
 *
 * @author yx
 * @since 2023-02-11
 */
@Service
public class BasCustomerServiceImpl extends ServiceImpl<BasCustomerMapper, BasCustomer> implements IBasCustomerService {

    @Autowired
    BasCustomerMapper mapper;

    /**
     * 查询今日的客户数量
     * @return 今日的客户数量视图对象
     */
    @Override
    public CustomerInformationVO countCustomerOnTheDay() {
        CustomerInformationVO customerInformationVO = new CustomerInformationVO();
        Integer customerOnTheDay = mapper.countCustomerOnTheDay();
        customerInformationVO.setLabel("今日客户");
        customerInformationVO.setValue(customerOnTheDay);
        return customerInformationVO;
    }

    /**
     * 查询本周的客户数量
     * @return 本周的客户数量视图对象
     */
    @Override
    public CustomerInformationVO countCustomerOfTheWeek() {
        CustomerInformationVO customerInformationVO = new CustomerInformationVO();
        Integer customerOfTheWeek = mapper.countCustomerOfTheWeek();
        customerInformationVO.setLabel("本周客户");
        customerInformationVO.setValue(customerOfTheWeek);
        return customerInformationVO;
    }

    /**
     * 查询本月的客户数量
     * @return 本月的客户数量视图对象
     */
    @Override
    public CustomerInformationVO countCustomerOnTheMonth() {
        CustomerInformationVO customerInformationVO = new CustomerInformationVO();
        Integer customerOnTheMonth = mapper.countCustomerOnTheMonth();
        customerInformationVO.setLabel("本月客户");
        customerInformationVO.setValue(customerOnTheMonth);
        return customerInformationVO;
    }

    /**
     * 查询总客户数量
     * @return 总客户数量视图对象
     */
    @Override
    public CustomerInformationVO countTotalCustomer() {
        CustomerInformationVO customerInformationVO = new CustomerInformationVO();
        Integer totalCustomer = mapper.countTotalCustomer();
        customerInformationVO.setLabel("客户总数");
        customerInformationVO.setValue(totalCustomer);
        return customerInformationVO;
    }
}
