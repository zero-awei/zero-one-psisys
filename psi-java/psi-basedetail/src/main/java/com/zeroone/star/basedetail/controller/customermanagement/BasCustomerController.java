package com.zeroone.star.basedetail.controller.customermanagement;


import cn.hutool.core.date.DateTime;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.basedetail.entity.BasCustomer;
import com.zeroone.star.basedetail.entity.User;
import com.zeroone.star.basedetail.service.IBasCustomerService;
import com.zeroone.star.basedetail.service.impl.BasCustomerServiceImpl;
import com.zeroone.star.project.basedetail.customermanagement.CustomerApis;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.dto.basedetail.customermanagement.CustomerAddDTO;
import com.zeroone.star.project.query.basedetail.customermanagement.CustomerByAuxNameQuery;
import com.zeroone.star.project.query.basedetail.customermanagement.CustomerByAuxiliaryNameQuery;
import com.zeroone.star.project.query.basedetail.customermanagement.CustomerByCodeQuery;
import com.zeroone.star.project.query.basedetail.customermanagement.CustomerByNameQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.basedetail.customermanagement.CustomerBaseInfoVO;
import com.zeroone.star.project.vo.basedetail.customermanagement.CustomerExistVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.PostConstruct;
import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 客户信息管理
 * </p>
 *
 * @author ss
 * @since 2023-02-14
 */
@RestController
@RequestMapping("/basedetail/bas-customer")
@Api(tags = "客户操作")
public class BasCustomerController implements CustomerApis {
    @Autowired
    private IBasCustomerService basCustomerService;

    /**
     * 根据编码获取客户信息
     * @param customerByCodeQuery 包含客户的编码信息
     * @return 客户的编码、名称、助记名、辅助名称
     */
    @ApiOperation("根据编码获取客户信息")
    @PostMapping("query-Customer-By-Code")
    @Override
    public JsonVO<CustomerBaseInfoVO> queryCustomerByCode(CustomerByCodeQuery customerByCodeQuery) {
        CustomerBaseInfoVO customerBaseInfoVO = basCustomerService.queryCustomerByCode(customerByCodeQuery.getCode());
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
        QueryWrapper<BasCustomer> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("name", customerByNameQuery.getName());
        BasCustomer customer = basCustomerService.getOne(queryWrapper);
        CustomerExistVO customerExistVO = new CustomerExistVO();
        if(customer == null){
            customerExistVO.setIsExist(false);
        }else {
            customerExistVO.setIsExist(true);
        }
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
        QueryWrapper<BasCustomer> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("aux_name", customerByAuxNameQuery.getAuxName());
        BasCustomer customer = basCustomerService.getOne(queryWrapper);
        CustomerExistVO customerExistVO = new CustomerExistVO();
        if(customer == null){
            customerExistVO.setIsExist(false);
        }else {
            customerExistVO.setIsExist(true);
        }
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
        QueryWrapper<BasCustomer> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("aux_name", customerByAuxiliaryNameQuery.getAuxiliaryName());
        BasCustomer customer = basCustomerService.getOne(queryWrapper);
        CustomerExistVO customerExistVO = new CustomerExistVO();
        if(customer == null){
            customerExistVO.setIsExist(false);
        }else {
            customerExistVO.setIsExist(true);
        }
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
    public JsonVO<String> addCustomer(CustomerAddDTO customerAddDTO) {
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
    public JsonVO<String> updateCustomer(CustomerAddDTO customerAddDTO) {
        BasCustomer basCustomer = basCustomerService.insertIntoCustomerEntity(customerAddDTO);
        QueryWrapper<BasCustomer> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("code", customerAddDTO.getCode());
        basCustomerService.update(basCustomer, queryWrapper);
        return JsonVO.success("修改成功");
    }
}
