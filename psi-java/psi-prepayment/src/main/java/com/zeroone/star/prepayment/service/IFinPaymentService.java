package com.zeroone.star.prepayment.service;

import com.zeroone.star.prepayment.entity.FinPayment;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.dto.prepayment.AuditDTO;
import com.zeroone.star.project.dto.prepayment.ModifyDTO;
import com.zeroone.star.project.vo.JsonVO;

/**
 * <p>
 * 付款单 服务类
 * </p>
 *
 * @author zhd
 * @since 2023-02-18
 */
public interface IFinPaymentService extends IService<FinPayment> {


    /**
     * 修改付款单
     * author forever爱
     */
    public boolean updateById(ModifyDTO modifyDTO, UserDTO userDTO);
    /**
     * 审核采购预付单功能
     * param auditDTO 审核DTO
     * return 查询结果
     * author forever爱
     */
    JsonVO<String> auditById(AuditDTO auditDTO, UserDTO userDTO);

}
