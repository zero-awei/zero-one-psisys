package com.zeroone.star.titlepage.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.titlepage.entity.PurOrder;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 * 采购订单 Mapper 接口
 * </p>
 *
 * @author ss
 * @since 2023-02-12
 */
@Mapper
public interface PurOrderMapper extends BaseMapper<PurOrder> {
    /*
    查询采购金额
     */
    List<PurOrder> queryPurOrder();
}
