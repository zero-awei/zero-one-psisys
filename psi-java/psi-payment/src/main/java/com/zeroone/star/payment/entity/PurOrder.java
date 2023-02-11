package com.zeroone.star.payment.entity;

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
 * 采购订单
 * </p>
 *
 * @author zhd
 * @since 2023-02-11
 */
@Getter
@Setter
@TableName("pur_order")
public class PurOrder implements Serializable {

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
     * 采购类型
     */
    private String purType;

    /**
     * 供应商
     */
    private String supplierId;

    /**
     * 联系人
     */
    private String contact;

    /**
     * 联系电话
     */
    private String phone;

    /**
     * 传真
     */
    private String fax;

    /**
     * 电子邮件
     */
    private String email;

    private String opDept;

    /**
     * 业务员
     */
    private String operator;

    /**
     * 交货方式
     */
    private String deliveryMethod;

    /**
     * 交货地点
     */
    private String deliveryPlace;

    /**
     * 交货日期
     */
    private LocalDateTime deliveryTime;

    /**
     * 运输方式
     */
    private String transportMethod;

    /**
     * 付款方式
     */
    private String paymentMethod;

    /**
     * 结算方式
     */
    private String settleMethod;

    /**
     * 结算日期
     */
    private LocalDate settleTime;

    /**
     * 开票方式
     */
    private String invoiceMethod;

    /**
     * 发票类型
     */
    private String invoiceType;

    /**
     * 外币币种
     */
    private String currency;

    /**
     * 汇率
     */
    private BigDecimal exchangeRate;

    /**
     * 数量
     */
    private BigDecimal qty;

    /**
     * 金额
     */
    private BigDecimal amt;

    /**
     * 预付款余额
     */
    private BigDecimal prepaymentBal;

    /**
     * 结算数量
     */
    private BigDecimal settleQty;

    /**
     * 结算金额
     */
    private BigDecimal settleAmt;

    /**
     * 已入库数量
     */
    private Double inQty;

    /**
     * 已入库成本
     */
    private BigDecimal inCost;

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
