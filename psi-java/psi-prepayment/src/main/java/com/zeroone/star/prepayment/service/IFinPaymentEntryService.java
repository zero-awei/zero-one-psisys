package com.zeroone.star.prepayment.service;
import com.zeroone.star.prepayment.entity.FinPayment;
import com.zeroone.star.prepayment.entity.FinPaymentEntry;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.prepayment.ModifyDTO;
import com.zeroone.star.project.dto.prepayment.PrepaymentDTO;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.stereotype.Component;

/**
 * <p>
 * 付款单明细 服务类
 * </p>
 *
 * @author zhd
 * @since 2023-02-18
 */
@Component
public interface IFinPaymentEntryService extends IService<FinPaymentEntry> {
    /**
     * 修改付款单明细
     * author forever爱
     */
    public boolean updateById(ModifyDTO modifyDTO);

    /**
     * 插入
     * author kong
     */
    public int insert(PrepaymentDTO prepaymentDTO);
}
