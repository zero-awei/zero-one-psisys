package com.zeroone.star.payablemanagement.entity;
import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.math.BigDecimal;
import java.time.LocalDate;
import java.time.LocalDateTime;
import lombok.Data;

/**
 *
 * @author spk
 * @description 付款单 Entity cpoied from j4
 */
@Data
@TableName("fin_payment")
public class FinPayment implements Serializable {

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

    /**
     * 单据主题
     */
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
     * 是否自动单据
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
     * 流程
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
    private Boolean isVoided;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 创建人
     */
    @TableField(fill = FieldFill.INSERT)
    private String createBy;

    /**
     * 创建部门
     */
    private String sysOrgCode;

    /**
     * 修改时间
     */
    @TableField(fill = FieldFill.INSERT_UPDATE)
    private LocalDateTime updateTime;

    /**
     * 修改人
     */
    @TableField(fill = FieldFill.INSERT_UPDATE)
    private String updateBy;

    /**
     * 版本
     */
    private Integer version;

}
