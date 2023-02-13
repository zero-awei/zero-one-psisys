package com.zeroone.star.project.payment;

import com.zeroone.star.project.dto.payment.ModifyDTO;
import com.zeroone.star.project.vo.JsonVO;

/**
 * <p>
 * 描述：修改（有申请）功能API接口定义
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author forever爱
 * @version 1.0.0
 */
public interface ModifyApis {
    /**
     * 测试API接口
     * @param modifyDTO 带明细表的收款单DTO
     * @return 查询结果
     */
    JsonVO<String> modifyById(ModifyDTO modifyDTO);

}
