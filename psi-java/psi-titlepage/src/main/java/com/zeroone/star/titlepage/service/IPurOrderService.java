package com.zeroone.star.titlepage.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.vo.homepage.PurOrderVO;
import com.zeroone.star.titlepage.entity.PurOrder;

import java.util.List;

/**
 * <p>
 * 采购订单 服务类
 * </p>
 *
 * @author ss
 * @since 2023-02-12
 */
public interface IPurOrderService extends IService<PurOrder> {

    /**
     * 查询采购金额
     */
    public List<PurOrderVO> queryPurOrder();
}
