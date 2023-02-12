package com.zeroone.star.project.payment;

import com.zeroone.star.project.query.payment.DetQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.payment.DetHavVO;
import com.zeroone.star.project.vo.payment.DetNoVO;

/**
 * <p>
 * 描述：预付管理-查询订单详情
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 狂踹瘸子那条好腿
 * @version 1.0.0
 */
public interface PaymentDetApis {
    /**
     * 通过单据编号查询数据-采购预付有申请
     * @param condition 单据编号-查询条件
     * @return 查询结果
     */
    JsonVO<DetHavVO> queryByBillHav(DetQuery condition);

    /**
     *通过单据编号查询数据-采购预付无申请
     * @param condition 单据编号-查询条件
     * @return 查询结果
     */
    JsonVO<DetNoVO> queryByBillNo (DetQuery condition);
}
