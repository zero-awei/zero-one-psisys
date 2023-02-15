package com.zeroone.star.systemmanagement.controller.customermanagement;

import com.zeroone.star.project.dto.systemmanagement.customermanagement.CustomerDTO;
import com.zeroone.star.project.systemmanagement.customermanagement.CustomerApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * @Description
 * @Author mumu
 * @Data 2023-02-13 11:47
 */
@RestController
@RequestMapping("/systemmanagement/sys-customer")
@Api(tags = "客户信息管理")
@Validated
public class CustomerController implements CustomerApis {

    @ApiOperation("添加客户")
    @PostMapping("/addCustomer")
    @Override
    public JsonVO<String> saveCustomer(CustomerDTO customerDTO) {
        return null;
    }

    @ApiOperation(value = "修改客户")
    @PostMapping("updateCustomer")
    @Override
    public JsonVO<String> updateCustomer(CustomerDTO customerDTO) {
        return null;
    }

    @ApiOperation(value = "删除客户")
    @DeleteMapping("/deleteCustomer")
    @Override
    public JsonVO<String> deleteCustomer(String customerId) {
        return null;
    }
}
