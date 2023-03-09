package com.zeroone.star.titlepage.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.titlepage.entity.HomeDoingBill;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

/**
 * <p>
 * VIEW Mapper 接口
 * </p>
 *
 * @author ss
 * @since 2023-02-12
 */
@Mapper
public interface HomeDoingBillMapper extends BaseMapper<HomeDoingBill> {

    HomeDoingBill selectbyName(@Param("name") String name);
}
