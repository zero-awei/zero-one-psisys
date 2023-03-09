package com.zeroone.star.titlepage.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.titlepage.entity.BasCustomer;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

/**
 * <p>
 * 客户 Mapper 接口
 * </p>
 *
 * @author yx
 * @since 2023-02-11
 */
@Mapper
public interface BasCustomerMapper extends BaseMapper<BasCustomer> {

    /**
     * 查询今日的客户数量
     * @return 今日的客户数量
     */
    @Select("SELECT COUNT(1) value FROM bas_customer WHERE is_enabled = 1 \n" +
            "   AND create_time >= DATE(SYSDATE())")
    public Integer countCustomerOnTheDay();

    /**
     * 查询本周的客户数量
     * @return 本周的客户数量
     */
    @Select("SELECT COUNT(1) FROM bas_customer WHERE is_enabled = 1 \n" +
            "   AND YEARWEEK(create_time, 1) = YEARWEEK(SYSDATE(), 1)")
    public Integer countCustomerOfTheWeek();

    /**
     * 查询本月的客户数量
     * @return 本月的客户数量
     */
    @Select("SELECT COUNT(1) FROM bas_customer WHERE is_enabled = 1 \n" +
            "   AND YEAR(create_time) = YEAR(SYSDATE()) AND MONTH(create_time) = MONTH(SYSDATE())")
    public Integer countCustomerOnTheMonth();

    /**
     * 查询总客户数量
     * @return 总客户数量
     */
    @Select("SELECT COUNT(1) FROM bas_customer WHERE is_enabled = 1 ")
    public Integer countTotalCustomer();
}
