package com.zeroone.star.payment.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.math.BigDecimal;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 付款单明细
 * </p>
 *
 * @author zhd
 * @since 2023-02-11
 */
@Getter
@Setter
@TableName("fin_payment_entry")
public class FinPaymentEntry implements Serializable {

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
     * 单据编号
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
     * 源单id
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
     * 结算方式
     */
    private String settleMethod;

    /**
     * 资金账户
     */
    private String bankAccountId;

    /**
     * 金额
     */
    private BigDecimal amt;

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
