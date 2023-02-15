package com.zeroone.star.paymentmanagement.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.math.BigDecimal;
import java.time.LocalDate;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 付款申请单
 * </p>
 *
 * @author achuan
 * @since 2023-02-13
 */
@Getter
@Setter
@TableName("fin_payment_req")
public class FinPaymentReq implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * ID
     */
    private String id;

    /**
     * 单据编号
     */
    private String billNo;

    /**
     * 单据日期
     */
    private LocalDate billDate;

    /**
     * 源单类型
     */
    private String srcBillType;

    /**
     * 源单id
     */
    private String srcBillId;

    /**
     * 源单号
     */
    private String srcNo;

    private String subject;

    /**
     * 是否红字
     */
    private Integer isRubric;

    /**
     * 付款类型
     */
    private String paymentType;

    /**
     * 供应商
     */
    private String supplierId;

    /**
     * 业务部门
     */
    private String opDept;

    /**
     * 业务员
     */
    private String operator;

    /**
     * 申请金额
     */
    private BigDecimal amt;

    /**
     * 已付金额
     */
    private BigDecimal paidAmt;

    /**
     * 附件
     */
    private String attachment;

    /**
     * 备注
     */
    private String remark;

    /**
     * 是否自动生成
     */
    private Integer isAuto;

    /**
     * 单据阶段
     */
    private String billStage;

    /**
     * 审核人
     */
    private String approver;

    /**
     * 审批实例id
     */
    private String bpmiInstanceId;

    /**
     * 核批结果类型
     */
    private String approvalResultType;

    /**
     * 核批意见
     */
    private String approvalRemark;

    /**
     * 是否生效
     */
    private Integer isEffective;

    /**
     * 生效时间
     */
    private LocalDateTime effectiveTime;

    /**
     * 已关闭
     */
    private Integer isClosed;

    /**
     * 是否作废
     */
    private Integer isVoided;

    /**
     * 创建部门
     */
    private String sysOrgCode;

    /**
     * 创建人
     */
    private String createBy;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 修改人
     */
    private String updateBy;

    /**
     * 修改时间
     */
    private LocalDateTime updateTime;

    /**
     * 版本
     */
    private Integer version;


}
