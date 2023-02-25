package com.zeroone.star.basedetail.service.customermanagement.impl;

import cn.hutool.core.bean.BeanUtil;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.basedetail.entity.customermanagement.CusLevel;
import com.zeroone.star.basedetail.mapper.customermanagement.CusLevelMapper;
import com.zeroone.star.basedetail.service.customermanagement.ICusLevelService;
import com.zeroone.star.project.vo.basedetail.customermanagement.CustomerLevelVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;


import java.util.List;
import java.util.stream.Collectors;

/**
 * @Description 查询客户等级的service
 * @auther j2-yizhiyang
 * @date 2023/2/13 19:16
 */
@Service
public class CusCLevelServiceImpl extends ServiceImpl<CusLevelMapper,CusLevel> implements ICusLevelService {
    @Autowired
    private CusLevelMapper cusLevelMapper;

    @Override
    public List<CustomerLevelVO> listAllCusLevel() {
        List<CusLevel> customerlevel = cusLevelMapper.selectList(null);
        //转换成VO类型，空就不会转
        List<CustomerLevelVO> CustomerLevelVOS = customerlevel
                .stream()
                .map(cuscate-> BeanUtil.copyProperties(cuscate, CustomerLevelVO.class))
                .collect(Collectors.toList());

        return CustomerLevelVOS;
    }
}
