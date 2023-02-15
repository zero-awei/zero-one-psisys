package com.zeroone.star.basedetail.controller.customermanagement;

import com.zeroone.star.project.dto.basedetail.customermanagement.CustomerDTO;
import com.zeroone.star.project.basedetail.customermanagement.CustomerApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import com.zeroone.star.project.query.basedetail.customermanagement.CustomerQuery;
import com.zeroone.star.project.query.basedetail.customermanagement.CustomerCdvancedQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.basedetail.customermanagement.CustomerVO;
import com.zeroone.star.project.vo.basedetail.customermanagement.CustomerCategoryVO;
import com.zeroone.star.project.vo.basedetail.customermanagement.CustomerLevelVO;
import org.springframework.web.bind.annotation.GetMapping;

import java.util.List;

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


    @GetMapping("query-condition")
    @ApiOperation(value = "普通条件分页查询")
    @Override
    public JsonVO<PageVO<CustomerVO>> listCustomerByPageAndCondition(CustomerQuery customerQuery) {
        return null;
    }

    @Override
    @GetMapping("query-advancedcondition")
    @ApiOperation(value = "高级条件分页查询")
    public JsonVO<PageVO<CustomerVO>> listCustomerByPageAndAdevanced(CustomerCdvancedQuery CustomerCdvancedQuery) {
        return null;
    }

    @Override
    @GetMapping("customercategory")
    @ApiOperation(value = "客户分类查询")
    public JsonVO<List<CustomerCategoryVO>> listCustomerCategory() {
        return null;
    }

    @Override
    @GetMapping("customerlevel")
    @ApiOperation(value = "客户等级查询")
    public JsonVO<List<CustomerLevelVO>> listCustomerLevel() {
        return null;
    }

    @Override
    @GetMapping("getcustomerbyid")
    @ApiOperation(value = "查询指定id客户")
    public JsonVO<CustomerVO> specifiedcustomer(String id) {
        return null;
    }

    @ApiOperation("添加客户返回值data值表示插入成功与否）")
    @PostMapping("/addCustomer")
    @Override
    public JsonVO<String> saveCustomer(CustomerDTO customerDTO) {
        return null;
    }

    @ApiOperation(value = "修改客户（返回值data值表示更新成功与否）")
    @PostMapping("updateCustomer")
    @Override
    public JsonVO<String> updateCustomer(CustomerDTO customerDTO) {
        return null;
    }

    @ApiOperation(value = "删除客户（返回值data值表示删除成功与否）")
    @DeleteMapping("/deleteCustomer")
    @Override
    public JsonVO<String> deleteCustomer(String customerId) {
        return null;
    }
}
