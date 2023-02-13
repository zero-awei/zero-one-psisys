package com.zeroone.star.project.payment;

import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payment.PaymentReqEntryVO;

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

    JsonVO<PageVO<PaymentReqEntryVO>> queryAllByBillNo(String billNo);
}
