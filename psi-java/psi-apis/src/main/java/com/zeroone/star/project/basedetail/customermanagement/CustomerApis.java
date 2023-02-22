package com.zeroone.star.project.basedetail.customermanagement;

import com.zeroone.star.project.dto.basedetail.customermanagement.CustomerAddDTO;
import com.zeroone.star.project.query.basedetail.customermanagement.CustomerByAuxNameQuery;
import com.zeroone.star.project.query.basedetail.customermanagement.CustomerByAuxiliaryNameQuery;
import com.zeroone.star.project.query.basedetail.customermanagement.CustomerByCodeQuery;
import com.zeroone.star.project.query.basedetail.customermanagement.CustomerByNameQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.basedetail.customermanagement.CustomerBaseInfoVO;
import com.zeroone.star.project.vo.basedetail.customermanagement.CustomerExistVO;
import org.springframework.validation.BindingResult;

import java.util.List;

/**
 * @Description
 * @Author yinxing
 * @Data 2023-02-20 11:42
 */
public interface CustomerApis {

    /**
     *客户条件查询
     * 根据编码获取客户信息
     * @param customerByCodeQuery 包含客户的编码信息
     * @return 客户的编码、名称、助记名、辅助名称
     */
    JsonVO<CustomerBaseInfoVO> queryCustomerByCode(CustomerByCodeQuery customerByCodeQuery);

    /**
     *客户条件查询
     * 根据名称获取用户信息
     * @param customerByNameQuery 包含客户的名称信息
     * @return customer 客户是否存在信息
     */
    JsonVO<CustomerExistVO> queryCustomerByName(CustomerByNameQuery customerByNameQuery);

    /**
     *客户条件查询
     * 根据助记名获取用户信息
     * @param customerByAuxNameQuery 包含客户的助记名信息
     * @return customer 客户是否存在信息
     */
    JsonVO<CustomerExistVO> queryCustomerByAuxName(CustomerByAuxNameQuery customerByAuxNameQuery);

    /**
     *客户条件查询
     * 根据辅助名称获取客户信息
     * @param customerByAuxiliaryNameQuery 包含客户的辅助名称信息
     * @return customer 客户是否存在信息
     */
    JsonVO<CustomerExistVO> queryCustomerByAuxiliaryName(CustomerByAuxiliaryNameQuery customerByAuxiliaryNameQuery);

    /**
     *添加客户
     * @param customerAddDTO 包含客户的全部信息
     * @return 是否添加成功
     */
    JsonVO<String> addCustomer(CustomerAddDTO customerAddDTO, BindingResult bindingResult);

    /**
     *修改客户信息
     * @param customerAddDTO 包含客户的全部信息
     * @return 是否添加成功
     */
    JsonVO<String> updateCustomer(CustomerAddDTO customerAddDTO, BindingResult bindingResult);
}
