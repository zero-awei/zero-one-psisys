package com.zeroone.star.project.vo.homepage;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;

/**
 * <p>
 * 描述：采购概况显示对象
 * </p>
 * @author YinXing
 * @date 2023年02月11日
 */
@Data
@ApiModel("采购概况显示对象")
public class PurchaseInformationVO {

    @ApiModelProperty(value = "类型", example = "订单")
    private String label;

    @ApiModelProperty(value = "今日笔数", example = "3")
    private Integer tCount;

    @ApiModelProperty(value = "今日金额", example = "7.00")
    private BigDecimal tAmt;

    @ApiModelProperty(value = "本周笔数", example = "27")
    private Integer wCount;

    @ApiModelProperty(value = "本周金额", example = "385432.60")
    private BigDecimal wAmt;

    @ApiModelProperty(value = "本月笔数", example = "30")
    private Integer mCount;

    @ApiModelProperty(value = "本月金额", example = "398125.60")
    private BigDecimal mAmt;
}
