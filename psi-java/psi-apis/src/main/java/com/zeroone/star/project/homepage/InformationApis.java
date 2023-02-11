package com.zeroone.star.project.homepage;

import com.zeroone.star.project.query.homepage.*;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.homepage.*;

import java.util.List;

/**
 * <p>
 * 描述：首页信息接收API接口定义
 * </p>
 * @author YinXing
 * @date 2023年02月11日
 */
public interface InformationApis {

    /**
     * 通过编号查询系统收支概况
     * @param query 系统收支概况查询对象
     * @return 查询出来的系统收支信息
     */
    JsonVO<List<SystemRevenueAndExpenditureInformationVO>> querySystemInfoById(SystemRevenueAndExpenditureInformationQuery query);

    /**
     * 通过编号查询销售概况
     * @param query 销售概况查询对象
     * @return 查询出来的销售信息
     */
    JsonVO<List<SaleInformationVO>> querySaleInfoById(SaleInformationQuery query);

    /**
     * 通过编号查询采购概况
     * @param query 采购概况查询对象
     * @return 查询出来的采购信息
     */
    JsonVO<List<PurchaseInformationVO>> queryPurchaseInfoById(PurchaseInformationQuery query);

    /**
     * 通过编号查询客户概况
     * @param query 客户信息概况查询对象
     * @return 查询出来的客户数量信息
     */
    JsonVO<List<CustomerInformationVO>> queryCustomerInfoById(CustomerInformationQuery query);

    /**
     * 通过编号查询销售金额概况
     * @param query 销售金额概况查询对象
     * @return 查询出来的销售金额信息
     */
    JsonVO<List<SalesAmountInformationVO>> querySalesAmountInfoById(SalesAmountIformationQuery query);
}
