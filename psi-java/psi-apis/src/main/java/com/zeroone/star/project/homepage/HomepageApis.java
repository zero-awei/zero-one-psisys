package com.zeroone.star.project.homepage;

import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.homepage.*;

import java.util.List;

/**
 * @author Third uncle
 * @date 2023/2/12 - 19:05
 */
public interface HomepageApis {

    /**
     * 查询所有的毛利润
     * @return
     */
    public JsonVO<List<SalOrderVO>> querySalOrder();
    /**
     * 查询采购金额
     * @return
     */
    public JsonVO<List<PurOrderVO>> queryPurOrder();
    /**
     * 查询库存结存金额
     * @return
     */
    public JsonVO<List<StkIoSumVO>> queryStkIoSum();
    /**
     * 查询供应商
     * @return
     */
    public JsonVO<List<BasSupplierVO>> queryBasSupplier();
    /**
     * 查询处理中主要单据
     * @return
     */
    public JsonVO<List<HomeDoingBillVO>> queryHomeDoingBill();

}
