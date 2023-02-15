package com.zeroone.star.project.dto.accountpayable;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;

/**
 * @author The end
 * @date 2023/2/15
 */
@Data
@ApiModel("往来核销明细")
public class FinPayableCheckEntryDto {

    /**
     * 分录号
     */
    @ApiModelProperty(value = "分录号", example = "101")
    private Integer entryNo;

    /**
     * 核销方向
     */
    @ApiModelProperty(value = "核销方向", example = "1")
    private String checkSide;

    /**
     * 源单类型
     */
    @ApiModelProperty(value = "源单类型", example = "FinPayable:201")
    private String srcBillType;

    /**
     * 源单id
     */
    @ApiModelProperty(value = "源单id", example = "1624235050093813761")
    private String srcBillId;

    /**
     * 源单号
     */
    @ApiModelProperty(value = "源单号", example = "CGAP-230211-002")
    private String srcNo;

    /**
     * 核销金额
     */
    @ApiModelProperty(value = "核销金额", example = "2.00")
    private BigDecimal amt;

    @ApiModelProperty(value = "未核销金额", example = "2.00")
    private BigDecimal uncheckedAmt;

    /**
     * 备注
     */
    @ApiModelProperty(value = "备注", allowEmptyValue = true)
    private String remark;

    /**
     * 自定义1
     */
    @ApiModelProperty(value = "自定义1", allowEmptyValue = true)
    private String custom1;

    /**
     * 自定义2
     */
    @ApiModelProperty(value = "自定义2", allowEmptyValue = true)
    private String custom2;

}
