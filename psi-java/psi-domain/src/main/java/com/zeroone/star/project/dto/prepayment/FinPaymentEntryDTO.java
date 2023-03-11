package com.zeroone.star.project.dto.prepayment;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;
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
    @ApiModelProperty(value = "金额",example = "1000.00")
    @NotNull(message = "金额不能为空")
    private BigDecimal amt;

    @ApiModelProperty(value = "资金账户",example = "")
    private String bankAccountId;

    @ApiModelProperty(value = "自定义1",example = "")
    private String custom1;

    @ApiModelProperty(value = "自定义2",example = "")
    private String custom2;

    @ApiModelProperty(value = "mid",example = "1626949545251745795")
    @NotBlank(message = "mid不能为空")
    private String mid;

    @ApiModelProperty(value = "单据编号",example = "TEST-202302-002")
    @NotBlank(message = "单据编号不能为空")
    private String billNo;

    @ApiModelProperty(value = "分录号",example = "10")
    @NotNull(message = "分录号不能为空")
    private Integer entryNo;

    @ApiModelProperty(value = "源单类型",example = "FinPaymentReq:2011")
    private String srcBillType;

    @ApiModelProperty(value = "源单号",example = "TESTSQ-202302-002")
    private String srcNo;

    @ApiModelProperty(value = "备注",example = "备注")
    private String remark;

    @ApiModelProperty(value = "结算方式",example = "31")
    private String settleMethod;

    @ApiModelProperty(value = "源单id",example = "1594317750844637186")
    private String srcBillId;





}
