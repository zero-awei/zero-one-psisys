package com.zeroone.star.prepayment.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.zeroone.star.prepayment.entity.FinPayment;
import com.zeroone.star.prepayment.mapper.FinPaymentMapper;
import com.zeroone.star.prepayment.service.IFinPaymentService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.prepayment.AuditDTO;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.stereotype.Service;

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
     * 审核采购预付单功能
     * param auditDTO 审核DTO
     * return 查询结果
     * author forever爱
     */
    @Override
    public JsonVO<String> auditById(AuditDTO auditDTO) {

        FinPayment finPayment = new FinPayment();
        BeanUtil.copyProperties(auditDTO, finPayment);
        //时间
        finPayment.setUpdateTime(LocalDateTime.now());
        boolean flag = updateById(finPayment);
        //TODO 如何更新 修改人 如何获得？？
        if (flag){
            return JsonVO.success("修改成功");
        }
        return JsonVO.fail("修改失败");
    }
}
