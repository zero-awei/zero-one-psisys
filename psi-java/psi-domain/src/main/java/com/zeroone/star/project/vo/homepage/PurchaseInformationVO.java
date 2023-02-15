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

    @ApiModelProperty(value = "今日笔数", example = "0")
    private Long todayCount;

    @ApiModelProperty(value = "今日金额", example = "0.00")
    private BigDecimal todayAmt;

    @ApiModelProperty(value = "本周笔数", example = "0")
    private Long weekCount;

    @ApiModelProperty(value = "本周金额", example = "0.00")
    private BigDecimal weekAmt;

    @ApiModelProperty(value = "本月笔数", example = "0")
    private Long monthCount;

    @ApiModelProperty(value = "本月金额", example = "0.00")
    private BigDecimal monthAmt;
}
