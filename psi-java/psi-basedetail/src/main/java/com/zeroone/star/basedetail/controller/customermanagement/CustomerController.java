package com.zeroone.star.basedetail.controller.customermanagement;


import com.zeroone.star.basedetail.entity.BasCustomer;
import com.zeroone.star.basedetail.service.customermanagement.IBasCustomerService;
import com.zeroone.star.basedetail.service.customermanagement.impl.CusCLevelServiceImpl;
import com.zeroone.star.basedetail.service.customermanagement.impl.CusCategoryServiceImpl;
import com.zeroone.star.basedetail.service.customermanagement.impl.CustomerServiceImpl;
import com.zeroone.star.project.basedetail.customermanagement.CustomerApis;
import com.zeroone.star.project.dto.basedetail.customermanagement.CustomerAddDTO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.query.basedetail.customermanagement.*;

import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;

import com.zeroone.star.project.vo.basedetail.customermanagement.*;

import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.validation.BindingResult;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.validation.Valid;
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

    @Autowired
    private IBasCustomerService basCustomerService;



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


    /**
     * 根据编码获取客户信息
     * @param customerByCodeQuery 包含客户的编码信息
     * @return 客户的编码、名称、助记名、辅助名称
     */
    @ApiOperation("根据编码获取客户信息")
    @PostMapping("query-Customer-By-Code")
    @Override
    public JsonVO<CustomerBaseInfoVO> queryCustomerByCode(CustomerByCodeQuery customerByCodeQuery) {
        CustomerBaseInfoVO customerBaseInfoVO =
                basCustomerService.queryCustomerByCode(customerByCodeQuery.getCode());
        return JsonVO.success(customerBaseInfoVO);
    }

    /**
     * 根据名称获取用户信息
     * @param customerByNameQuery 包含客户的名称信息
     * @return customer 客户是否存在信息
     */
    @ApiOperation("根据名称获取用户是否存在的信息")
    @GetMapping("query-Customer-Exist-By-Name")
    @Override
    public JsonVO<CustomerExistVO> queryCustomerByName(CustomerByNameQuery customerByNameQuery) {
        CustomerExistVO customerExistVO =
                basCustomerService.queryCustomerExistByName(customerByNameQuery.getName());
        return JsonVO.success(customerExistVO);
    }

    /**
     * 根据助记名获取获取用户是否存在的信息
     * @param customerByAuxNameQuery 包含客户的助记名信息
     * @return customer 客户是否存在信息
     */
    @ApiOperation("根据助记名获取获取用户是否存在的信息")
    @GetMapping("query-Customer-Exist-By-AuxName")
    @Override
    public JsonVO<CustomerExistVO> queryCustomerByAuxName(CustomerByAuxNameQuery customerByAuxNameQuery) {
        CustomerExistVO customerExistVO =
                basCustomerService.queryCustomerExistByAuxName(customerByAuxNameQuery.getAuxName());
        return JsonVO.success(customerExistVO);
    }

    /**
     * 根据辅助名称获取获取用户是否存在的信息
     * @param customerByAuxiliaryNameQuery 包含客户的辅助名称信息
     * @return customer 客户是否存在信息
     */
    @ApiOperation("根据辅助名称获取获取用户是否存在的信息")
    @GetMapping("query-Customer-Exist-By-AuxiliaryName")
    @Override
    public JsonVO<CustomerExistVO> queryCustomerByAuxiliaryName(CustomerByAuxiliaryNameQuery
                                                                        customerByAuxiliaryNameQuery) {
        CustomerExistVO customerExistVO = basCustomerService.
                queryCustomerExistByAuxiliaryName(customerByAuxiliaryNameQuery.getAuxiliaryName());
        return JsonVO.success(customerExistVO);
    }

    /**
     *添加客户
     * @param customerAddDTO 包含客户的全部信息
     * @return 是否添加成功
     */
    @ApiOperation("添加客户")
    @PostMapping("add-Customer")
    @Override
    public JsonVO<String> saveCustomer(CustomerAddDTO customerAddDTO, BindingResult bindingResult) {
        if(bindingResult.hasErrors()){
            return JsonVO.fail(bindingResult.getFieldError().getDefaultMessage());
        }
        BasCustomer basCustomer = basCustomerService.insertIntoCustomerEntity(customerAddDTO);
        basCustomerService.save(basCustomer);
        return JsonVO.success("添加成功");
    }

    /**
     *修改客户信息
     * @param customerAddDTO 包含客户的全部信息
     * @return 是否修改成功
     */

    @ApiOperation("修改客户信息")
    @PostMapping("update-Customer")
    @Override
    public JsonVO<String> updateCustomer(CustomerAddDTO customerAddDTO,BindingResult bindingResult) {
        if(bindingResult.hasErrors()){
            return JsonVO.fail(bindingResult.getFieldError().getDefaultMessage());
        }
        BasCustomer basCustomer = basCustomerService.insertIntoCustomerEntity(customerAddDTO);
        if(basCustomerService.updateCustomer(basCustomer)){
            return JsonVO.success("修改成功");
        }
        return JsonVO.fail("修改失败");
    }

    /**
     *删除客户信息
     * @param customerByCodeQuery 包含客户的code，根据这个删除客户
     * @return 是否添加成功
     */
    @ApiOperation("删除客户信息")
    @PostMapping("remove-Customer")
    @Override
    public JsonVO<String> deleteCustomer(CustomerByCodeQuery customerByCodeQuery,BindingResult bindingResult) {
        if(bindingResult.hasErrors()){
            return JsonVO.fail(bindingResult.getFieldError().getDefaultMessage());
        }
        if(basCustomerService.removeCustomer(customerByCodeQuery.getCode())){
            return JsonVO.success("删除成功");
        }
        return JsonVO.fail("删除失败");
    }


}
