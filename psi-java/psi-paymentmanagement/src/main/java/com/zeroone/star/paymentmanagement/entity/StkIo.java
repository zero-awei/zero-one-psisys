package com.zeroone.star.paymentmanagement.entity;

import java.io.Serializable;
import java.math.BigDecimal;
import java.util.Date;
import lombok.Data;

/**
 * 出入库单
 * @TableName stk_io
 */
@Data
public class StkIo implements Serializable {
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
    private Date billDate;

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
     * 
     */
    private String subject;

    /**
     * 是否红字
     */
    private Integer isRubric;

    /**
     * 出入库类型
     */
    private String stockIoType;

    /**
     * 业务部门
     */
    private String opDept;

    /**
     * 业务员
     */
    private String operator;

    /**
     * 出入库经办
     */
    private String handler;

    /**
     * 是否有往来
     */
    private Integer hasRp;

    /**
     * 是否有涨吨
     */
    private Integer hasSwell;

    /**
     * 供应商
     */
    private String supplierId;

    /**
     * 客户
     */
    private String customerId;

    /**
     * 发票类型
     */
    private String invoiceType;

    /**
     * 成本
     */
    private BigDecimal cost;

    /**
     * 结算金额
     */
    private BigDecimal settleAmt;

    /**
     * 已结算金额
     */
    private BigDecimal settledAmt;

    /**
     * 已开票金额
     */
    private BigDecimal invoicedAmt;

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
    private Date effectiveTime;

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
    private Date createTime;

    /**
     * 修改人
     */
    private String updateBy;

    /**
     * 修改时间
     */
    private Date updateTime;

    /**
     * 版本
     */
    private Integer version;

    private static final long serialVersionUID = 1L;
}