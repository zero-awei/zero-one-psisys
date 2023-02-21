package com.zeroone.star.project.basedetail.customermanagement;

import com.zeroone.star.project.dto.basedetail.customermanagement.CustomerDTO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.query.basedetail.customermanagement.CustomerCdvancedQuery;
import com.zeroone.star.project.query.basedetail.customermanagement.CustomerQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.basedetail.customermanagement.CustomerCategoryVO;
import com.zeroone.star.project.vo.basedetail.customermanagement.CustomerLevelVO;
import com.zeroone.star.project.vo.basedetail.customermanagement.CustomerShowVO;
import com.zeroone.star.project.vo.basedetail.customermanagement.CustomerVO;

import java.util.List;

/**
 * @Description
 * @Author mumu
 * @Data 2023-02-13 11:42
 */
public interface CustomerApis {

    /**
     *客户条件查询
     * 根据查询条件和页数，获取客户信息
     * @param customerQuery 包含分页信息和查询客户的5个查询条件
     * @return customer message
     */
    JsonVO<PageVO<CustomerShowVO>> listCustomerByPageAndCondition(CustomerQuery customerQuery);
    /**
     * 客户高级查询
     * @param CustomerCdvancedQuery 包含分页信息和客户高级查询条件
     * @return customer message
     */
    JsonVO<PageVO<CustomerShowVO>> listCustomerByPageAndAdevanced(CustomerCdvancedQuery CustomerCdvancedQuery);
    /**
     * 客户分类查询
     * @return customer_category message
     */
    JsonVO<List<CustomerCategoryVO>> listCustomerCategory();
    /**
     * 客户等级查询
     * @return customer_level message
     */
    JsonVO<List<CustomerLevelVO>> listCustomerLevel();
    /**
     * 查询指定客户查询信息
     * @param id 要查询的客户id
     * @return customer message
     */
    JsonVO<CustomerShowVO> specifiedcustomer(String id);

    /**
     * 添加客户信息
     * @param customerDTO 根据DTO添加职务
     * @return 结果的字符串
     */
    JsonVO<String> saveCustomer(CustomerDTO customerDTO);

    /**
     * 修改客户信息
     * @param customerDTO 根据DTO修改职务
     * @return 结果的字符串
     */
    JsonVO<String> updateCustomer(CustomerDTO customerDTO);

    /**
     * 删除指定客户信息
     * @param customerId 根据DTO删除职务
     * @return 结果的字符串
     */
    JsonVO<String> deleteCustomer(String customerId);




}
