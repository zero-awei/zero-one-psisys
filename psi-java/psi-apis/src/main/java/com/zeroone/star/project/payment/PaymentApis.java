package com.zeroone.star.project.payment;

import com.zeroone.star.project.dto.payment.ModifyDTO;
import com.zeroone.star.project.vo.JsonVO;

import com.zeroone.star.project.query.payment.DocListQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payment.DocListVO;


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
     * 修改采购预付单功能
     * param modifyDTO 带明细表的收款单DTO
     * return 查询结果
     * author forever爱
     */
    JsonVO<String> modifyById(ModifyDTO modifyDTO);

    /**
     * 单据列表查询
     * @param condition 查询条件
     * @return 查询结果
     * @author husj
     * @version 1.0.0
     */
    JsonVO<PageVO<DocListVO>> queryAll(DocListQuery condition);
}
