package com.zeroone.star.project.systemmanagement.customermanagement;

import com.zeroone.star.project.dto.systemmanagement.customermanagement.CustomerDTO;
import com.zeroone.star.project.dto.systemmanagement.positionmanagement.PositionDTO;
import com.zeroone.star.project.vo.JsonVO;

/**
 * @Description
 * @Author mumu
 * @Data 2023-02-13 11:42
 */
public interface CustomerApis {

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
