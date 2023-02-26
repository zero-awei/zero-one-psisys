package com.zeroone.star.basedetail;

import com.zeroone.star.basedetail.controller.customermanagement.BasCustomerController;
import com.zeroone.star.project.dto.basedetail.customermanagement.CustomerAddDTO;
import com.zeroone.star.project.query.basedetail.customermanagement.CustomerByCodeQuery;
import com.zeroone.star.project.query.basedetail.customermanagement.CustomerByNameQuery;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

/**
 * @author YinXing
 * @date 2023年02月21日
 */
@SpringBootTest
public class MyTest {

    @Autowired
    BasCustomerController controller;

    @Test
    public void test01(){
        CustomerByCodeQuery customerByCodeQuery = new CustomerByCodeQuery();
        customerByCodeQuery.setCode("001");
        System.out.println(controller.queryCustomerByCode(customerByCodeQuery));
    }

    @Test
    public void test02(){
        CustomerByNameQuery customerByNameQuery = new CustomerByNameQuery();
        customerByNameQuery.setName("dsadsa");
        System.out.println(controller.queryCustomerByName(customerByNameQuery));
    }

    @Test
    public void test03(){
        CustomerAddDTO customerAddDTO = new CustomerAddDTO();
        customerAddDTO.setName("dsadsad");
        customerAddDTO.setCode("0056");
        customerAddDTO.setAuxName("dfsf");
        customerAddDTO.setIsEnabled(1);
//        System.out.println(controller.addCustomer(customerAddDTO));
    }

    @Test
    public void test04(){
        CustomerAddDTO customerAddDTO = new CustomerAddDTO();
        customerAddDTO.setName("dsadsad");
        customerAddDTO.setCode("0056");
        customerAddDTO.setAuxName("dfsf111");
        customerAddDTO.setIsEnabled(1);
//        System.out.println(controller.updateCustomer(customerAddDTO));
    }
}
