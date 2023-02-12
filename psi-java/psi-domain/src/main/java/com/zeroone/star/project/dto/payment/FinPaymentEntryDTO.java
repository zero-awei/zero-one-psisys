package com.zeroone.star.project.dto.payment;

import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.math.BigDecimal;

/**
 * <p>
 * 付款单明细
 * </p>
 *
 * @author Kong
 * @since 2023-02-12
 */
@Getter
@Setter
public class FinPaymentEntryDTO{
    //billNo

    @ApiModelProperty(value = "分录号",example = "10")
    private Integer entryNo;

    @ApiModelProperty(value = "源单类型",example = "FinPaymentReq:2011")
    private String srcBillType;

    @ApiModelProperty(value = "源单id",example = "1594317750844637186")
    private String srcBillId;

    @ApiModelProperty(value = "源单号",example = "CGYFSQ-221120-001")
    private String srcNo;

    @ApiModelProperty(value = "结算方式",example = "31 （银行代扣）")
    private String settleMethod;

    @ApiModelProperty(value = "资金账户",example = "")
    private String bankAccountId;

    @ApiModelProperty(value = "金额",example = "0")
    private BigDecimal amt;

    @ApiModelProperty(value = "备注",example = "备注")
    private String remark;

    @ApiModelProperty(value = "自定义1",example = "")
    private String custom1;

    @ApiModelProperty(value = "自定义2",example = "")
    private String custom2;


}
