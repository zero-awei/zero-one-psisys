package com.zeroone.star.titlepage.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.vo.homepage.SystemRevenueAndExpenditureInformationVO;
import com.zeroone.star.titlepage.entity.StkInventory;

import java.math.BigDecimal;

/**
 * <p>
 * 实时库存 服务类
 * </p>
 *
 * @author yx
 * @since 2023-02-11
 */
public interface IStkInventoryService extends IService<StkInventory> {

    /**
     * 获取即时库存(元)视图对象
     * @return 系统收支概况视图对象
     */
    public SystemRevenueAndExpenditureInformationVO getInventoryVO();
}
