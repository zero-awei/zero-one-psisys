package com.zeroone.star.project.payment;

import com.zeroone.star.project.dto.payment.DeleteDTO;
import com.zeroone.star.project.vo.JsonVO;

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
     * 测试API接口
     * @param deleteDTO 包含付款单id
     * @return 删除结果
     */
    JsonVO<String> deleteById(DeleteDTO deleteDTO);
}
