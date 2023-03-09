package com.zeroone.star.basedetail.service.customermanagement.impl;


import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.basedetail.entity.customermanagement.CusCategory;
import com.zeroone.star.basedetail.mapper.customermanagement.CusCategoryMapper;
import com.zeroone.star.basedetail.service.customermanagement.ICusCategoryService;
import com.zeroone.star.project.vo.basedetail.customermanagement.CustomerCategoryVO;


import cn.hutool.core.bean.BeanUtil;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.stream.Collectors;

/**
 * @Description
 * @auther j2-yizhiyang
 * @date 2023/2/12 21:36
 */
@Service

public  class CusCategoryServiceImpl extends ServiceImpl<CusCategoryMapper,CusCategory> implements ICusCategoryService {

    @Autowired
    private CusCategoryMapper cusCategoryMapper;
    @Override

    public List<CustomerCategoryVO> listAllCusCategory() {
        //觉得这个可以使用redis来改进一下
        List<CusCategory> customercategorys = cusCategoryMapper.selectList(null);
        if(customercategorys.size()==0){
            return null;
        }
        //转换成VO类型
        List<CustomerCategoryVO> CustomerCategoryVOS = customercategorys
                                                        .stream()
                                                        .map(cuscate-> BeanUtil.copyProperties(cuscate, CustomerCategoryVO.class))
                                                        .collect(Collectors.toList());

        return CustomerCategoryVOS;
    }


}
