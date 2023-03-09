package com.zeroone.star.titlepage.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.titlepage.entity.StkInventory;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.math.BigDecimal;

/**
 * <p>
 * 实时库存 Mapper 接口
 * </p>
 *
 * @author yx
 * @since 2023-02-11
 */
@Mapper
public interface StkInventoryMapper extends BaseMapper<StkInventory> {

}
