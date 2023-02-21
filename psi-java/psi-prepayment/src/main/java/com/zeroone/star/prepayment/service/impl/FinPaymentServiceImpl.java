package com.zeroone.star.prepayment.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.zeroone.star.prepayment.entity.FinPayment;
import com.zeroone.star.prepayment.mapper.FinPaymentMapper;
import com.zeroone.star.prepayment.service.IFinPaymentService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.dto.prepayment.AuditDTO;
import com.zeroone.star.project.dto.prepayment.ModifyDTO;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.stereotype.Service;

import javax.jws.soap.SOAPBinding;
import java.time.LocalDateTime;
import java.util.Date;

/**
 * <p>
 * 付款单 服务实现类
 * </p>
 *
 * @author zhd
 * @since 2023-02-18
 */
@Service
public class FinPaymentServiceImpl extends ServiceImpl<FinPaymentMapper, FinPayment> implements IFinPaymentService {

    /**
     * 修改付款单
     * author forever爱
     */
    @Override
    public boolean updateById(ModifyDTO modifyDTO, UserDTO userDTO) {
        FinPayment finPayment = new FinPayment();
        BeanUtil.copyProperties(modifyDTO, finPayment);
        //时间
        finPayment.setUpdateTime(LocalDateTime.now());
        //用户信息
        finPayment.setUpdateBy(userDTO.getUsername());
        return updateById(finPayment);
    }

    /**
     * 审核采购预付单功能
     * param auditDTO 审核DTO
     * return 查询结果
     * author forever爱
     */
    @Override
    public JsonVO<String> auditById(AuditDTO auditDTO, UserDTO userDTO) {
        FinPayment finPayment = new FinPayment();
        BeanUtil.copyProperties(auditDTO, finPayment);
        //审核生效时间、修改时间
        finPayment.setUpdateTime(LocalDateTime.now());
        finPayment.setEffectiveTime(LocalDateTime.now());
        //审核人、修改人信息
        finPayment.setApprover(userDTO.getUsername());
        finPayment.setUpdateBy(userDTO.getUsername());
        boolean flag = updateById(finPayment);
        if (flag){
            return JsonVO.success("修改成功");
        }
        return JsonVO.fail("修改失败");
    }
}
