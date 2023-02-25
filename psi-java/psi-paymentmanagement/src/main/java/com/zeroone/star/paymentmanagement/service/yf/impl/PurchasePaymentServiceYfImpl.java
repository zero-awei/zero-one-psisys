package com.zeroone.star.paymentmanagement.service.yf.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.paymentmanagement.entity.FinPayment;
import com.zeroone.star.paymentmanagement.mapper.yf.PurchasePaymentYfMapper;
import com.zeroone.star.paymentmanagement.service.yf.PurchasePaymentYfService;
import com.zeroone.star.project.dto.paymentmanagement.AddPurchasePaymentDto;
import com.zeroone.star.project.dto.paymentmanagement.UpdatePurchasePaymentDto;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.time.LocalDate;
import java.time.LocalDateTime;

/**
 * @Description 采购付款增删改表现层
 * @Author 业峰
 * @Date 2023/2/20
 */
@Service
public class PurchasePaymentServiceYfImpl extends ServiceImpl<PurchasePaymentYfMapper, FinPayment> implements PurchasePaymentYfService {

    @Autowired
    PurchasePaymentYfMapper purchasePaymentMapper;

    /**
     * 新增单据
     * @param addPurchasePaymentDto
     * @return
     */
    @Override
    public int insert(AddPurchasePaymentDto addPurchasePaymentDto) {
        //将输入的dto转弯插入数据库的entry对象
        FinPayment finPayment = new FinPayment();
        finPayment.setBillNo(addPurchasePaymentDto.getBillNo());
        finPayment.setSrcBillId(addPurchasePaymentDto.getSrcBillId());
        finPayment.setBillDate(LocalDate.now());
        finPayment.setSrcBillType(addPurchasePaymentDto.getSrcBillType());
        finPayment.setSrcNo(addPurchasePaymentDto.getSrcNo());
        finPayment.setSubject(addPurchasePaymentDto.getSubject());
        finPayment.setIsRubric(addPurchasePaymentDto.getIsRubric());
        finPayment.setPaymentType(addPurchasePaymentDto.getPaymentType());
        finPayment.setSupplierId(addPurchasePaymentDto.getSupplierId());
        finPayment.setAmt(addPurchasePaymentDto.getAmt());
        finPayment.setCheckedAmt(addPurchasePaymentDto.getCheckedAmt());
        finPayment.setRemark(addPurchasePaymentDto.getRemark());
        finPayment.setIsAuto(addPurchasePaymentDto.getIsAuto());
        finPayment.setCreateTime(LocalDateTime.now());
        //private String billStage;状态
        //private String approver;审核人
        //private String bpmiInstanceId;流程
        //private String approvalResultType;核批结果类型
        //private String approvalRemark;核批意见
        //private Integer isEffective;是否通过
        //private Integer isClosed;已关闭
        //private Boolean isVoided;是否作废
        //EffectiveTime生效时间
        //private String createBy;
        //private String sysOrgCode;创建部门
        //private LocalDateTime updateTime;修改时间
        //private String updateBy;修改人
        //private Integer version;版本

        return purchasePaymentMapper.insert(finPayment);

    }

    /**
     * 根据单据编号删除
     * @param billNo
     * @return
     */
    @Override
    public int delete(String billNo) {
        QueryWrapper<FinPayment> wrapper = new QueryWrapper<>();
        wrapper.eq("bill_no",billNo);
        return purchasePaymentMapper.delete(wrapper);
    }

    /**
     * 根据单据编号修改
     * @param updatePurchasePaymentDto
     * @return
     */
    @Override
    public int update(UpdatePurchasePaymentDto updatePurchasePaymentDto) {
        FinPayment finPayment = new FinPayment();
        BeanUtils.copyProperties(updatePurchasePaymentDto,finPayment);
        UpdateWrapper<FinPayment> wrapper = new UpdateWrapper<>();
        wrapper.eq("bill_no",updatePurchasePaymentDto.getBillNo());
        return purchasePaymentMapper.update(finPayment, wrapper);
    }
}
