package com.zeroone.star.project.vo.payment;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;

/**
 * @ClassName FinPaymentVO
 * @Description 明细对应源单对象
 * @Author HZP
 * @Date 2023/2/12 15:32
 * @Version 1.0
 **/
@Data
@ApiModel("明细源单对象")
public class FinPaymentEntryVO {

    /**
     * 源单分录号
     */
    @ApiModelProperty(value = "源单号",example = "CGFKSQ-230211-004")
    private String srcNo;

    /**
     * 结算方式
     */
    @ApiModelProperty(value = "结算方式",example = "")
    private String settleMethod;

    /**
     * 资金账户
     */
    @ApiModelProperty(value = "资金账户",example = "")
    private String bankAccountId;

    /**
     * 金额
     */
    @ApiModelProperty(value = "金额",example = "90000")
    private BigDecimal amt;

    /**
     * 备注
     */
    @ApiModelProperty(value = "备注",example = "")
    private String remark;

    /**
     * 自定义1
     */
    @ApiModelProperty(value = "自定义1",example = "")
    private String custom1;

    /**
     * 自定义2
     */
    @ApiModelProperty(value = "自定义2",example = "")
    private String custom2;
}