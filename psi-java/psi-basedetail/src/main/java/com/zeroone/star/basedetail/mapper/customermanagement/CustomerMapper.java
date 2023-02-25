package com.zeroone.star.basedetail.mapper.customermanagement;


import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.core.metadata.IPage;
import com.zeroone.star.basedetail.entity.customermanagement.Customer;
import com.zeroone.star.project.query.basedetail.customermanagement.CustomerQuery;
import org.apache.ibatis.annotations.Mapper;

import java.io.Serializable;

/**
 * <p>
 * 客户 Mapper 接口
 * </p>
 *
 * @author yizhiyang
 * @since 2023-02-13
 */
@Mapper
public interface CustomerMapper extends BaseMapper<Customer> {
        /**
         * 根据id查询对象
         * */
        Customer getCustomerById(Serializable id);
        /**
         * 根据条件查询客户对象
         * */
        Customer getByCondition(CustomerQuery customerQuery);
        IPage<Customer> selectByPage(IPage<Customer> customerIPage, QueryWrapper<Customer> queryWrapper);
}
