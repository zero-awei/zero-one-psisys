package com.zeroone.star.paymentmanagement.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import lombok.ToString;

/**
 * @author Tomcat
 * @Date 2023/2/15 23:41
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
@ToString
@TableName("fin_payment_entry")
public class FinPaymentEntry {
    private Integer amt;

    private String bankAccount;

    private String custom1;

    private String custom2;

    private Integer entryNo;

    private String remark;

    private String settleMethod;

    private String srcBillId;

    private String srcNo;
}
