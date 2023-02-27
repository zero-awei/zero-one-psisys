package com.zeroone.star.basedetail.service.customermanagement.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.basedetail.entity.BasCustomer;
import com.zeroone.star.basedetail.mapper.BasCustomerMapper;
import com.zeroone.star.basedetail.service.customermanagement.IBasCustomerService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.basedetail.customermanagement.CustomerAddDTO;
import com.zeroone.star.project.vo.basedetail.customermanagement.CustomerBaseInfoVO;
import com.zeroone.star.project.vo.basedetail.customermanagement.CustomerExistVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * <p>
 * 客户 服务实现类
 * </p>
 *
 * @author ss
 * @since 2023-02-15
 */
@Service
public class BasCustomerServiceImpl extends ServiceImpl<BasCustomerMapper, BasCustomer> implements IBasCustomerService {
    @Autowired
    private BasCustomerMapper basCustomerMapper;

    @Override
    public List<BasCustomer> listBasCustomer() {
        List<BasCustomer> list = baseMapper.selectList(null);
        return list;
    }

    @Override
    public void insertOne(BasCustomer basCustomer) {
        baseMapper.insert(basCustomer);
    }


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
        customerBaseInfoVO.setIsEnabled(basCustomer.getIsEnabled().equals("1")?1:0);
        return customerBaseInfoVO;
    }

    /**
     * 根据客户名称查询客户是否存在的信息
     * @param name 客户名称
     * @return 客户是否存在的信息
     */
    @Override
    public CustomerExistVO queryCustomerExistByName(String name) {
        QueryWrapper<BasCustomer> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("name", name);
        BasCustomer basCustomer = basCustomerMapper.selectOne(queryWrapper);
        CustomerExistVO customerExistVO = new CustomerExistVO();
        if(basCustomer == null){
            customerExistVO.setIsExist(false);
        }else {
            customerExistVO.setIsExist(true);
        }
        return customerExistVO;
    }

    /**
     * 根据助记名获取获取用户是否存在的信息
     * @param auxName 客户助记名
     * @return 客户是否存在的信息
     */
    @Override
    public CustomerExistVO queryCustomerExistByAuxName(String auxName) {
        QueryWrapper<BasCustomer> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("aux_name", auxName);
        BasCustomer basCustomer = basCustomerMapper.selectOne(queryWrapper);
        CustomerExistVO customerExistVO = new CustomerExistVO();
        if(basCustomer == null){
            customerExistVO.setIsExist(false);
        }else {
            customerExistVO.setIsExist(true);
        }
        return customerExistVO;
    }

    /**
     * 根据辅助名称获取获取用户是否存在的信息
     * @param auxiliaryName 客户辅助名称
     * @return 客户是否存在的信息
     */
    @Override
    public CustomerExistVO queryCustomerExistByAuxiliaryName(String auxiliaryName) {
        QueryWrapper<BasCustomer> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("aux_name", auxiliaryName);
        BasCustomer basCustomer = basCustomerMapper.selectOne(queryWrapper);
        CustomerExistVO customerExistVO = new CustomerExistVO();
        if(basCustomer == null){
            customerExistVO.setIsExist(false);
        }else {
            customerExistVO.setIsExist(true);
        }
        return customerExistVO;
    }

    /**
     * 填入客户信息
     * @param customerAddDTO 传入客户数据
     * @return 客户实体类
     */
    @Override
    public BasCustomer insertIntoCustomerEntity(CustomerAddDTO customerAddDTO) {
        BasCustomer basCustomer = new BasCustomer();
        BeanUtil.copyProperties(basCustomer,customerAddDTO);
        UserHolder userHolder = new UserHolder();
        try {
            basCustomer.setCreateBy(null);
            basCustomer.setUpdateBy(userHolder.getCurrentUser().getUsername());
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        return basCustomer;
    }

    /**
     * 更新客户信息
     * @param basCustomer 客户实体类
     * @return 是否成功
     */
    @Override
    public Boolean updateCustomer(BasCustomer basCustomer) {
        QueryWrapper<BasCustomer> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("code", basCustomer.getCode());
        basCustomerMapper.update(basCustomer, queryWrapper);
        return true;
    }

    /**
     *删除客户信息
     * @param code 客户的code，根据这个删除客户
     * @return 是否添加成功
     */
    @Override
    public Boolean removeCustomer(String code) {
        QueryWrapper<BasCustomer> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("code", code);
        basCustomerMapper.delete(queryWrapper);
        return true;
    }


}
