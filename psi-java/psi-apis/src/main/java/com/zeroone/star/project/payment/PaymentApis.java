package com.zeroone.star.project.payment;

import com.zeroone.star.project.query.payment.PreDetQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.payment.DetHavVO;
import com.zeroone.star.project.vo.payment.DetNoVO;

/**
 * <p>
 * 描述：API接口定义
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author forever爱
 * @version 1.0.0
 */
public interface PaymentApis {
    /**
     * 通过单据编号查询数据-采购预付有申请
     * @param condition 单据编号-查询条件
     * @return 查询结果
     */
    JsonVO<DetHavVO> queryByBillHav(PreDetQuery condition);

    /**
     *通过单据编号查询数据-采购预付无申请
     * @param condition 单据编号-查询条件
     * @return 查询结果
     */
    JsonVO<DetNoVO> queryByBillNo (PreDetQuery condition);
}
