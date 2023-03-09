package com.zeroone.star.titlepage.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.titlepage.entity.BasSupplier;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 * 供应商 Mapper 接口
 * </p>
 *
 * @author ss
 * @since 2023-02-12
 */
@Mapper
public interface BasSupplierMapper extends BaseMapper<BasSupplier> {

    /*
    查询供应商
     */
    List<BasSupplier> queryBasSupplier();
}
