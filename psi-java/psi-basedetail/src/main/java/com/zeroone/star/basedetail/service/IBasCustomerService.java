package com.zeroone.star.basedetail.service;

import com.zeroone.star.basedetail.entity.BasCustomer;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.basedetail.customermanagement.CustomerAddDTO;
import com.zeroone.star.project.query.basedetail.customermanagement.CustomerByCodeQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.basedetail.customermanagement.CustomerBaseInfoVO;

/**
 * <p>
 * 客户 服务类
 * </p>
 *
 * @author yx
 * @since 2023-02-20
 */
public interface IBasCustomerService extends IService<BasCustomer> {

    /**
     * 根据客户编码查询信息
     * @param code 客户编码
     * @return 客户基础信息
     */
    public CustomerBaseInfoVO queryCustomerByCode(String code);

    /**
     * 填入客户信息
     * @param customerAddDTO 传入客户数据
     * @return 客户实体类
     */
    public BasCustomer insertIntoCustomerEntity(CustomerAddDTO customerAddDTO);
}
