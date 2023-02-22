package com.zeroone.star.prepayment.service;

import com.zeroone.star.prepayment.PrepaymentApplication;
import com.zeroone.star.prepayment.entity.SysDepart;
import com.zeroone.star.project.query.prepayment.PurchaseListQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.prepayment.*;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.util.List;

/**
 * @Author: Kong
 * @License: (C) Copyright 2005-2019, xxx Corporation Limited.
 * @Contact: xxx@xxx.com
 * @Date: 2023-02-18 9:26
 * @Version: 1.0
 * @Description:
 */
@SpringBootTest(classes = PrepaymentApplication.class)
public class SysDepartServiceTest {

    @Autowired
    ISysDepartService departService;
    @Autowired
    IBasBankAccountService basBankAccountService;
    @Autowired
    IBasSupplierService supplierService;
    @Autowired
    ISysUserService userService;
    @Autowired
    IFinPaymentReqService finPaymentReqService;
    @Test
    void testGetDeparts(){
        List<SysDepartVO> departs = departService.getDeparts();
        System.out.println(departs);
    }

    @Test
    void testGetSupplierList(){
        List<SupplierVO> supplierList = supplierService.getSupplierList();
        System.out.println(supplierList);
    }

    @Test
    void testGetBasBankAccountList(){
        List<BasBankAccountVO> basBankAccountList = basBankAccountService.getBasBankAccountList();
        System.out.println(basBankAccountList);
    }

    @Test
    void testGetSysUserList(){
        List<SysUserVO> sysUserList = userService.getSysUserList();
        System.out.println(sysUserList);
    }

    @Test
    void testGetFinPaymentReq(){
        PurchaseListQuery query = new PurchaseListQuery("1","2011",1,"1584950950470164481");
        query.setPageIndex(1);
        query.setPageSize(10);
        PageVO<FinPaymentReqVO> finPaymentReq = finPaymentReqService.getFinPaymentReq(query);
        System.out.println(finPaymentReq);
    }
}