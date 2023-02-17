package com.zeroone.star.paymentmanagement.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.math.BigDecimal;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 付款申请单明细
 * </p>
 *
 * @author achuan
 * @since 2023-02-15
 */
@Getter
@Setter
@TableName("fin_payment_req_entry")
public class FinPaymentReqEntry implements Serializable {


    private static final long serialVersionUID = 1L;

    /**
     * ID
     */
    private String id;

    /**
     * 主表
     */
    private String mid;

    /**
     * 单据号
     */
    private String billNo;

    /**
     * 分录号
     */
    private Integer entryNo;

    /**
     * 源单类型
     */
    private String srcBillType;

    /**
     * srcBillId
     */
    private String srcBillId;

    /**
     * 源单分录id
     */
    private String srcEntryId;

    /**
     * 源单分录号
     */
    private String srcNo;

    /**
     * 申请金额
     */
    private BigDecimal amt;

    /**
     * 已付金额
     */
    private BigDecimal paidAmt;

    /**
     * 备注
     */
    private String remark;

    /**
     * 自定义1
     */
    private String custom1;

    /**
     * 自定义2
     */
    private String custom2;

    /**
     * 版本
     */
    private Integer version;


}
