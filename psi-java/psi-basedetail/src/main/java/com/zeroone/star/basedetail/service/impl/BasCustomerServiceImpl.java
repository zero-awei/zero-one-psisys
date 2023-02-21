package com.zeroone.star.basedetail.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.basedetail.entity.BasCustomer;
import com.zeroone.star.basedetail.mapper.BasCustomerMapper;
import com.zeroone.star.basedetail.service.IBasCustomerService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.basedetail.customermanagement.CustomerAddDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.basedetail.customermanagement.CustomerBaseInfoVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 客户 服务实现类
 * </p>
 *
 * @author yx
 * @since 2023-02-20
 */
@Service
public class BasCustomerServiceImpl extends ServiceImpl<BasCustomerMapper, BasCustomer> implements IBasCustomerService {

    @Autowired
    private BasCustomerMapper basCustomerMapper;

    /**
     * 根据客户编码查询信息
     * @param code 客户编码
     * @return 客户基础信息
     */
    @Override
    public CustomerBaseInfoVO queryCustomerByCode(String code) {
        QueryWrapper<BasCustomer> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("code", code);
        queryWrapper.select("code", "name", "aux_name", "is_enabled");
        BasCustomer basCustomer = basCustomerMapper.selectOne(queryWrapper);
        CustomerBaseInfoVO customerBaseInfoVO = new CustomerBaseInfoVO();
        customerBaseInfoVO.setCode(basCustomer.getCode());
        customerBaseInfoVO.setName(basCustomer.getName());
        customerBaseInfoVO.setAuxName(basCustomer.getAuxName());
        customerBaseInfoVO.setAuxiliaryName(basCustomer.getAuxName());
        customerBaseInfoVO.setIsEnabled(basCustomer.getIsEnabled());
        return customerBaseInfoVO;
    }

    /**
     * 填入客户信息
     * @param customerAddDTO 传入客户数据
     * @return 客户实体类
     */
    @Override
    public BasCustomer insertIntoCustomerEntity(CustomerAddDTO customerAddDTO) {
        BasCustomer basCustomer = new BasCustomer();
        basCustomer.setAddress(customerAddDTO.getAddress());
        basCustomer.setArea(customerAddDTO.getArea());
        basCustomer.setAttachment(customerAddDTO.getAttachment());
        basCustomer.setAuxName(customerAddDTO.getAuxName());
        basCustomer.setBizArea(customerAddDTO.getBizArea());
        basCustomer.setCode(customerAddDTO.getCode());
//        basCustomer.setCreateBy(customerAddDTO.getCreateBy());
//        basCustomer.setCreateTime(customerAddDTO.getCreateTime());
        basCustomer.setCreditQuota(customerAddDTO.getCreditQuota());
        basCustomer.setCustomerCategory(customerAddDTO.getCustomerCategory());
        basCustomer.setCustomerLevel(customerAddDTO.getCustomerLevel());
        basCustomer.setFinancialContacts(customerAddDTO.getFinancialContacts());
        basCustomer.setFinancialPhone(customerAddDTO.getFinancialPhone());
        basCustomer.setHeadquarters(customerAddDTO.getHeadquarters());
//        basCustomer.setId(customerAddDTO.); //设置ID，id主键自动通过雪花算法生成
        basCustomer.setInvoiceAccount(customerAddDTO.getInvoiceAccount());
        basCustomer.setInvoiceAddress(customerAddDTO.getInvoiceAddress());
        basCustomer.setInvoiceBankCode(customerAddDTO.getInvoiceBankCode());
        basCustomer.setInvoiceBankName(customerAddDTO.getInvoiceBankName());
        basCustomer.setInvoiceCompany(customerAddDTO.getInvoiceCompany());
        basCustomer.setInvoicePhone(customerAddDTO.getInvoicePhone());
        basCustomer.setInvoiceTaxCode(customerAddDTO.getInvoiceTaxCode());
        basCustomer.setIsEnabled(customerAddDTO.getIsEnabled());
        basCustomer.setLegalPerson(customerAddDTO.getLegalPerson());
        basCustomer.setLegalPersonPhone(customerAddDTO.getLegalPersonPhone());
        basCustomer.setName(customerAddDTO.getName());
        basCustomer.setPaymentAccount(customerAddDTO.getPaymentAccount());
        basCustomer.setPaymentBankCode(customerAddDTO.getPaymentBankCode());
        basCustomer.setPaymentBankName(customerAddDTO.getPaymentBankName());
        basCustomer.setPaymentCompany(customerAddDTO.getPaymentCompany());
        basCustomer.setRecvAddress(customerAddDTO.getRecvAddress());
        basCustomer.setRecvEmail(customerAddDTO.getRecvEmail());
        basCustomer.setRecvFax(customerAddDTO.getRecvFax());
        basCustomer.setRecvName(customerAddDTO.getRecvName());
        basCustomer.setRecvPhone(customerAddDTO.getRecvPhone());
        basCustomer.setRecvPostcode(customerAddDTO.getRecvPostcode());
        basCustomer.setRemark(customerAddDTO.getRemark());
        basCustomer.setShortName(customerAddDTO.getShortName());
        basCustomer.setTaxScale(customerAddDTO.getTaxScale());
//        basCustomer.setUpdateBy(customerAddDTO.getUpdateBy());
//        basCustomer.setUpdateTime(customerAddDTO.getUpdateTime());
//        basCustomer.setVersion();   //版本
        basCustomer.setWebsite(customerAddDTO.getWebsite());
        return basCustomer;
    }
}
