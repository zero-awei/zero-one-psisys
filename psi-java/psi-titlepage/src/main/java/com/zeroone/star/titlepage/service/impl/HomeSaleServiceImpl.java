package com.zeroone.star.titlepage.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.titlepage.entity.HomeSale;
import com.zeroone.star.titlepage.mapper.HomeSaleMapper;
import com.zeroone.star.titlepage.service.IHomeSaleService;
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
public class HomeSaleServiceImpl extends ServiceImpl<HomeSaleMapper, HomeSale> implements IHomeSaleService {

    @Autowired
    HomeSaleMapper mapper;

    /**
     * 查询销售状况
     * @return 销售状况构成的列表
     */
    @Override
    public List<HomeSale> listHomeSales() {
        return mapper.selectList(null);
    }
}
