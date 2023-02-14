package com.zeroone.star.project.homepage;

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
     * @return 查询出来的系统收支信息
     */
    JsonVO<List<SystemRevenueAndExpenditureInformationVO>> querySystemInfo();

    /**
     * 通过编号查询销售概况
     * @return 查询出来的销售信息
     */
    JsonVO<List<SaleInformationVO>> querySaleInfo();

    /**
     * 通过编号查询采购概况
     * @return 查询出来的采购信息
     */
    JsonVO<List<PurchaseInformationVO>> queryPurchaseInfo();

    /**
     * 通过编号查询客户概况
     * @return 查询出来的客户数量信息
     */
    JsonVO<List<CustomerInformationVO>> queryCustomerInfo();

    /**
     * 通过编号查询销售金额概况
     * @return 查询出来的销售金额信息
     */
    JsonVO<List<SalesAmountInformationVO>> querySalesAmountInfo();
}
