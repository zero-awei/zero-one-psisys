package com.zeroone.star.project.vo.payment;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;

@Data
@ApiModel("申请单明细显示对象")
public class PaymentReqEntryVO {

    /**
     * 单据编号
     */
    @ApiModelProperty(value = "源单号", example = "CGYFSQ-221120-001")
    private String billNo;

    /**
     * 结算方式
     */
    @ApiModelProperty(value = "结算方式", example = "现金")
    private String settleMethod;

    /**
     * 资金账户
     */
    @ApiModelProperty(value = "资金账户", example = "12345678901234567890")
    private String bankAccountId;

    /**
     * 金额
     */
    @ApiModelProperty(value = "金额", example = "10000")
    private BigDecimal amt;

    /**
     * 备注
     */
    @ApiModelProperty(value = "备注", example = "备注1")
    private String remark;

    /**
     * 自定义1
     */
    @ApiModelProperty(value = "自定义1", example = "自定义1")
    private String custom1;

    /**
     * 自定义2
     */
    @ApiModelProperty(value = "自定义2", example = "自定义2")
    private String custom2;

}
