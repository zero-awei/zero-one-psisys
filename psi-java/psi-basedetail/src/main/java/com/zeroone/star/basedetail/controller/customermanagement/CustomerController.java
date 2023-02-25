package com.zeroone.star.basedetail.controller.customermanagement;


import com.zeroone.star.basedetail.service.customermanagement.impl.CusCLevelServiceImpl;
import com.zeroone.star.basedetail.service.customermanagement.impl.CusCategoryServiceImpl;
import com.zeroone.star.basedetail.service.customermanagement.impl.CustomerServiceImpl;
import com.zeroone.star.project.basedetail.customermanagement.CustomerApis;
import com.zeroone.star.project.dto.basedetail.customermanagement.CustomerDTO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.query.basedetail.customermanagement.CustomerQuery;
import com.zeroone.star.project.query.basedetail.customermanagement.CustomerCdvancedQuery;

import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;

import com.zeroone.star.project.vo.basedetail.customermanagement.CustomerCategoryVO;
import com.zeroone.star.project.vo.basedetail.customermanagement.CustomerLevelVO;

import com.zeroone.star.project.vo.basedetail.customermanagement.CustomerShowVO;
import com.zeroone.star.project.vo.basedetail.customermanagement.CustomerVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

/**
 * @Description
 * @auther j2-yizhiyang
 * @date 2023/2/11 22:31
 */
@RestController
@RequestMapping("customer-management")
@Api(tags = "客户接口")
@Validated
public class CustomerController implements CustomerApis {
    @Autowired
    private CusCategoryServiceImpl cusCategoryServiceImpl;
    @Autowired
    private CusCLevelServiceImpl cusCLevelService;
    @Autowired
    private CustomerServiceImpl customerService;

    @GetMapping("query-condition")
    @ApiOperation(value = "普通条件分页查询")
    @Override
    public JsonVO<PageVO<CustomerShowVO>> listCustomerByPageAndCondition(CustomerQuery customerQuery) {
        return JsonVO.success(customerService.getByCondition(customerQuery));
    }

    @Override
    @GetMapping("query-advancedcondition")
    @ApiOperation(value = "高级条件分页查询")
    public JsonVO<PageVO<CustomerShowVO>> listCustomerByPageAndAdevanced(CustomerCdvancedQuery CustomerCdvancedQuery,PageQuery pageQuery) {
        return null;
    }

    @Override
    @GetMapping("customercategory")
    @ApiOperation(value = "客户分类查询")
    public JsonVO<List<CustomerCategoryVO>> listCustomerCategory() {
        List<CustomerCategoryVO> CustomerCategoryVOS = cusCategoryServiceImpl.listAllCusCategory();
        return JsonVO.success(CustomerCategoryVOS);
    }

    @Override
    @GetMapping("customerlevel")
    @ApiOperation(value = "客户等级查询")
    public JsonVO<List<CustomerLevelVO>> listCustomerLevel() {
        List<CustomerLevelVO> CustomerLevelVOS = cusCLevelService.listAllCusLevel();
        return JsonVO.success(CustomerLevelVOS);
    }

    @Override
    @GetMapping("getcustomerbyid")
    @ApiOperation(value = "查询指定id客户")
    public JsonVO<CustomerShowVO> specifiedcustomer(String id) {
        CustomerShowVO customervo = customerService.getById(id);
        if(customervo!=null){
            return JsonVO.success(customervo);
        }

        return  JsonVO.fail(customervo);


    }

    @Override
    public JsonVO<String> saveCustomer(CustomerDTO customerDTO) {
        return null;
    }

    @Override
    public JsonVO<String> updateCustomer(CustomerDTO customerDTO) {
        return null;
    }

    @Override
    public JsonVO<String> deleteCustomer(String customerId) {
        return null;
    }

}
