package com.zeroone.star.paymentmanagement.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

/**
 * @Description 采购付款对象
 * @Author 业峰
 * @Date 2023/2/15
 */
@Data
@TableName("fin_payment_entry")     //付款单明细
public class FinPaymentEntry {
    private static final long serialVersionUID = 1L;

    //金额
    private String amt;
    //资金账户
    private String bankAccountId;
    //自定义1
    private String custom1;
    //自定义2
    private String custom2;
    //分录号
    private String entryNo;
    //备注
    private String remark;
    //结算方式
    private String settleMethod;
    //源单id
    private String srcBillId;
    //源单类型
    private String srcBillType;
    //源单分录号
    private String srcNo;

    //单据编号
    private String billNo;
}
