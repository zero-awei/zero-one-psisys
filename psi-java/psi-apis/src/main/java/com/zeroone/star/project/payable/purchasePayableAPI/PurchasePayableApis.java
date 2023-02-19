package com.zeroone.star.project.payable.purchasePayableAPI;

import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.query.patable.purchase.MultiConditionPayableQuery;
import com.zeroone.star.project.query.patable.purchase.PayableQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payable.purchase.FinPayableVO;

/**
 * <p>
 * 应付单 服务类
 * </p>
 *
 * @author chosen1
 * @since 2023-02-13
 */
public interface PurchasePayableApis {
    /**
     * 分页查询
     * @return 查询结果
     */
    JsonVO<PageVO<FinPayableVO>> listAll(PageQuery query);

    /**
     * 多条件分页查询
     * @param query 查询条件
     * @return 查询结果
     */
    JsonVO<PageVO<FinPayableVO>> multiConditionSearch(MultiConditionPayableQuery query);

    /**
     * 根据ID查询
     * @param query 编号
     * @return 查询结果
     */
    JsonVO<FinPayableVO> getById(PayableQuery query);
}
