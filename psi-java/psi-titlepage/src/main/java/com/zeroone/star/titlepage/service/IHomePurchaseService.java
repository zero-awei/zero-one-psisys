package com.zeroone.star.titlepage.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.titlepage.entity.HomePurchase;
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
public interface IHomePurchaseService extends IService<HomePurchase> {

    /**
     * 查询采购状况
     * @return 采购状况构成的列表
     */
    public List<HomePurchase> listHomePurchases();
}
