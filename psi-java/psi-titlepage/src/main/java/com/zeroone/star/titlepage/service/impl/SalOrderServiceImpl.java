package com.zeroone.star.titlepage.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.vo.homepage.SalOrderVO;
import com.zeroone.star.titlepage.entity.SalOrder;
import com.zeroone.star.titlepage.mapper.SalOrderMapper;
import com.zeroone.star.titlepage.service.ISalOrderService;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 销售订单 服务实现类
 * </p>
 *
 * @author ss
 * @since 2023-02-12
 */
@Service
public class SalOrderServiceImpl extends ServiceImpl<SalOrderMapper, SalOrder> implements ISalOrderService {

    @Override
    public List<SalOrderVO> listSalOrder() {
        //调用方法查询毛利润
        List<SalOrder> list = baseMapper.querySalOrder();
        List<SalOrderVO> list1=new ArrayList<>();
        //list里的元素转化为VO类型
        for (SalOrder salOrder : list) {
            SalOrderVO salOrderVO = new SalOrderVO();
            BeanUtil.copyProperties(salOrder,salOrderVO);
            list1.add(salOrderVO);
        }
        return list1;
    }
}
