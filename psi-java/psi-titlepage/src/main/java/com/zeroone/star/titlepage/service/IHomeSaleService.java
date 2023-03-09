package com.zeroone.star.titlepage.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.titlepage.entity.HomeSale;

import java.util.List;

/**
 * <p>
 * VIEW 服务类
 * </p>
 *
 * @author yx
 * @since 2023-02-11
 */
public interface IHomeSaleService extends IService<HomeSale> {

    /**
     * 查询销售状况
     * @return 销售状况构成的列表
     */
    public List<HomeSale> listHomeSales();
}
