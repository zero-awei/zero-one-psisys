package com.zeroone.star.project.payable;

import com.zeroone.star.project.query.payable.FinPayableQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.accountPayable.otherPayable.OtherPayableVO;

/**
 * 描述：测试API接口定义
 *
 * @author: G.
 * @date: 2023/2/15 13:01
 */
public interface FinPayableApis {
    /**
     * 测试分页查询
     * @param condition 查询条件
     * @return 查询结果
     */
    JsonVO<PageVO<OtherPayableVO>> queryAll(FinPayableQuery condition);

    /**
     * 通过单据编号查询数据
     * @param billNo 单据编号
     * @return 查询结果
     */
    JsonVO<OtherPayableVO> queryByBillNo(String billNo);
}
