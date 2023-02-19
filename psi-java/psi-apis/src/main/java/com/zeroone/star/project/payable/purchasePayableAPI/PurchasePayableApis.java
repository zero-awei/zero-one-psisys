package com.zeroone.star.project.payable.purchasePayableAPI;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.payable.purchase.FinPayableDTO;
import com.zeroone.star.project.query.patable.purchase.MultiPayableQuery;
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
     * @param MultiPayableQuery 查询条件
     * @return 查询结果
     */
    JsonVO<PageVO<FinPayableVO>> listAll(MultiPayableQuery query);

    /**
     * 根据ID查询
     * @param query 编号
     * @return 查询结果
     */
    JsonVO<FinPayableVO> getById(PayableQuery query);
}
