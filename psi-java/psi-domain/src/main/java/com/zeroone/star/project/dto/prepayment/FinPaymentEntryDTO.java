package com.zeroone.star.project.dto.prepayment;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;

/**
 * <p>
 * 描述：付款单明细
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * author forever爱
 * version 1.0.0
 */
@Data
public class FinPaymentEntryDTO {
    @ApiModelProperty(value = "金额",example = "0")
    private BigDecimal amt;

    @ApiModelProperty(value = "资金账户",example = "")
    private String bankAccountId;

    @ApiModelProperty(value = "自定义1",example = "")
    private String custom1;

    @ApiModelProperty(value = "自定义2",example = "")
    private String custom2;

    @ApiModelProperty(value = "分录号",example = "10")
    private Integer entryNo;

    @ApiModelProperty(value = "id",example = "")
    private String id;

    @ApiModelProperty(value = "mid",example = "")
    private String mid;

    @ApiModelProperty(value = "备注",example = "备注")
    private String remark;

    @ApiModelProperty(value = "结算方式",example = "31")
    private String settleMethod;

    @ApiModelProperty(value = "源单id",example = "1594317750844637186")
    private String srcBillId;

    @ApiModelProperty(value = "源单类型",example = "FinPaymentReq:2011")
    private String srcBillType;

    @ApiModelProperty(value = "源单号",example = "CGYFSQ-221120-001")
    private String srcNo;



}
