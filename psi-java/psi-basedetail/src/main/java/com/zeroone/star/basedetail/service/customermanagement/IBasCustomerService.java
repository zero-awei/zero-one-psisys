package com.zeroone.star.basedetail.service.customermanagement;

import com.zeroone.star.basedetail.entity.BasCustomer;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.basedetail.customermanagement.CustomerAddDTO;
import com.zeroone.star.project.vo.basedetail.customermanagement.CustomerBaseInfoVO;
import com.zeroone.star.project.vo.basedetail.customermanagement.CustomerExistVO;

import java.util.List;

/**
 * <p>
 * 客户 服务类
 * </p>
 *
 * @author ss
 * @since 2023-02-15
 */
public interface IBasCustomerService extends IService<BasCustomer> {

    List<BasCustomer> listBasCustomer();

    void insertOne(BasCustomer basCustomer);

    /**
     * 根据客户编码查询信息
     * @param code 客户编码
     * @return 客户基础信息
     */
    public CustomerBaseInfoVO queryCustomerByCode(String code);

    /**
     * 根据客户名称查询客户是否存在的信息
     * @param name 客户名称
     * @return 客户是否存在的信息
     */
    public CustomerExistVO queryCustomerExistByName(String name);

    /**
     * 根据助记名获取获取用户是否存在的信息
     * @param auxName 客户助记名
     * @return 客户是否存在的信息
     */
    public CustomerExistVO queryCustomerExistByAuxName(String auxName);

    /**
     * 根据辅助名称获取获取用户是否存在的信息
     * @param auxiliaryName 客户辅助名称
     * @return 客户是否存在的信息
     */
    public CustomerExistVO queryCustomerExistByAuxiliaryName(String auxiliaryName);

    /**
     * 填入客户信息
     * @param customerAddDTO 传入客户数据
     * @return 客户实体类
     */
    public BasCustomer insertIntoCustomerEntity(CustomerAddDTO customerAddDTO);

    /**
     * 更新客户信息
     * @param basCustomer 客户实体类
     * @return 是否成功
     */
    public Boolean updateCustomer(BasCustomer basCustomer);

    /**
     *删除客户信息
     * @param code 客户的code，根据这个删除客户
     * @return 是否添加成功
     */
    public Boolean removeCustomer(String code);



}
