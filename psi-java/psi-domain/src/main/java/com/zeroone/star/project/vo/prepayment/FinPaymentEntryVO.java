package com.zeroone.star.project.vo.prepayment;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;

/**
 * ClassName FinPaymentVO
 * @escription 明细对应源单对象
 * Author HZP、KONG
 * Date 2023/2/12 15:32
 * Version 1.0
 **/
@Data
@ApiModel("明细源单对象")
public class FinPaymentEntryVO {
    @ApiModelProperty(value = "源单号",example = "CGFKSQ-230211-004")
    private String srcBillNo;

    @ApiModelProperty(value = "结算方式",example = "")
    private String settleMethod;

    @ApiModelProperty(value = "资金账户",example = "")
    private String bankAccountId;

    @ApiModelProperty(value = "金额",example = "90000")
    private BigDecimal amt;

    @ApiModelProperty(value = "备注",example = "")
    private String remark;

    @ApiModelProperty(value = "自定义1",example = "")
    private String custom1;

    @ApiModelProperty(value = "自定义2",example = "")
    private String custom2;
}

