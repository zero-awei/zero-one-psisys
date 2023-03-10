package com.zeroone.star.payablemanagement.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.math.BigDecimal;
import java.time.LocalDateTime;

/**
 * <p>
 * 应付单
 * </p>
 *
 * @author j3
 * @since 2023-02-14
 */
@Getter
@Setter
@TableName("fin_payable")
public class FinPayable implements Serializable {

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
    private LocalDateTime billDate;

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

    /**
     * 单据主题
     */
    private String subject;

    /**
     * 是否红字
     */
    private Integer isRubric;

    /**
     * 应付类型
     */
    private String payableType;

    /**
     * 供应商
     */
    private String supplierId;

    private String opDept;

    /**
     * 业务员
     */
    private String operator;

    /**
     * 金额
     */
    private BigDecimal amt;

    /**
     * 已核销金额
     */
    private BigDecimal checkedAmt;

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
     * 处理状态
     */
    private String billStage;

    /**
     * 审核人
     */
    private String approver;

    /**
     * 流程id
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
     * 是否通过
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
    @TableField(fill = FieldFill.INSERT)
    private String createBy;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 修改人
     */
    @TableField(fill = FieldFill.INSERT_UPDATE)
    private String updateBy;

    /**
     * 修改时间
     */
    @TableField(fill = FieldFill.INSERT_UPDATE)
    private LocalDateTime updateTime;

    /**
     * 版本
     */
    private Integer version;

    @Override
    public String toString() {
        return "FinPayable{" +
                "id='" + id + '\'' +
                ", billNo='" + billNo + '\'' +
                ", billDate=" + billDate +
                ", srcBillType='" + srcBillType + '\'' +
                ", srcBillId='" + srcBillId + '\'' +
                ", srcNo='" + srcNo + '\'' +
                ", subject='" + subject + '\'' +
                ", isRubric=" + isRubric +
                ", payableType='" + payableType + '\'' +
                ", supplierId='" + supplierId + '\'' +
                ", opDept='" + opDept + '\'' +
                ", operator='" + operator + '\'' +
                ", amt=" + amt +
                ", checkedAmt=" + checkedAmt +
                ", attachment='" + attachment + '\'' +
                ", remark='" + remark + '\'' +
                ", isAuto=" + isAuto +
                ", billStage='" + billStage + '\'' +
                ", approver='" + approver + '\'' +
                ", bpmiInstanceId='" + bpmiInstanceId + '\'' +
                ", approvalResultType='" + approvalResultType + '\'' +
                ", approvalRemark='" + approvalRemark + '\'' +
                ", isEffective=" + isEffective +
                ", effectiveTime=" + effectiveTime +
                ", isClosed=" + isClosed +
                ", isVoided=" + isVoided +
                ", sysOrgCode='" + sysOrgCode + '\'' +
                ", createBy='" + createBy + '\'' +
                ", createTime=" + createTime +
                ", updateBy='" + updateBy + '\'' +
                ", updateTime=" + updateTime +
                ", version=" + version +
                '}';
    }
}
