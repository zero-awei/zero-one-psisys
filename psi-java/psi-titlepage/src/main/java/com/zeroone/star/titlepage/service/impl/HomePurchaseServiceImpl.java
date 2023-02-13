package com.zeroone.star.titlepage.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.titlepage.entity.HomePurchase;
import com.zeroone.star.titlepage.entity.HomeSale;
import com.zeroone.star.titlepage.mapper.HomePurchaseMapper;
import com.zeroone.star.titlepage.service.IHomePurchaseService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * <p>
 * VIEW 服务实现类
 * </p>
 *
 * @author yx
 * @since 2023-02-11
 */
@Service
public class HomePurchaseServiceImpl extends ServiceImpl<HomePurchaseMapper, HomePurchase> implements IHomePurchaseService {

    @Autowired
    HomePurchaseMapper mapper;

    /**
     * 查询采购状况
     * @return 采购状况构成的列表
     */
    @Override
    public List<HomePurchase> listHomePurchases() {
        return mapper.selectList(null);
    }
}