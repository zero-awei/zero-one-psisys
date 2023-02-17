package com.zeroone.star.titlepage.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.titlepage.entity.SalOrder;
import org.apache.ibatis.annotations.Mapper;
import com.zeroone.star.project.vo.homepage.SalesAmountInformationVO;
import com.zeroone.star.titlepage.entity.SalOrder;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 * 销售订单 Mapper 接口
 * </p>
 *
<<<<<<< HEAD
 * @author ss yx
 * @since 2023-02-12
 */
@Mapper
public interface SalOrderMapper extends BaseMapper<SalOrder> {

    /*
    查询毛利润
     */
    List<SalOrder> querySalOrder();

    /**
     * 获取每月销售金额
     * @return 每月销售金额构成的list
     */
    @Select("SELECT CONCAT(MAX(MONTH(b.bill_date)), '月') as month, IFNULL(SUM(b.amt),0) as money FROM sal_order b \n" +
            " WHERE b.is_effective = 1 AND b.is_voided = 0\n" +
            " AND b.bill_date BETWEEN fn_first_day(DATE_ADD(SYSDATE(), INTERVAL -11 MONTH)) AND LAST_DAY(SYSDATE())\n" +
            " GROUP BY YEAR(b.bill_date), MONTH(b.bill_date)\n" +
            " ORDER BY YEAR(b.bill_date), MONTH(b.bill_date)")
     List<SalesAmountInformationVO> listSalesAmount();

}
