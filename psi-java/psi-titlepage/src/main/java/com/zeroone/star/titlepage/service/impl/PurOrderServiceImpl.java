package com.zeroone.star.titlepage.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.vo.homepage.PurOrderVO;
import com.zeroone.star.titlepage.entity.PurOrder;
import com.zeroone.star.titlepage.mapper.PurOrderMapper;
import com.zeroone.star.titlepage.service.IPurOrderService;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 采购订单 服务实现类
 * </p>
 *
 * @author ss
 * @since 2023-02-12
 */
@Service
public class PurOrderServiceImpl extends ServiceImpl<PurOrderMapper, PurOrder> implements IPurOrderService {

    @Override
    public List<PurOrderVO> queryPurOrder() {
        //查询
        List<PurOrder> list = baseMapper.queryPurOrder();
        List<PurOrderVO> list1=new ArrayList<>();
        for (PurOrder purOrder : list) {
            PurOrderVO purOrderVO = new PurOrderVO();
            BeanUtil.copyProperties(purOrder,purOrderVO);
            list1.add(purOrderVO);
        }
        return list1;
    }
}
