package com.zeroone.star.project.vo.homepage;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;

/**
 * <p>
 * 描述：销售金额概况视图对象
 * </p>
 * @author YinXing
 * @date 2023年02月11日
 */
@Data
@ApiModel("销售金额概况视图对象")
public class SalesAmountInformationVO {

    @ApiModelProperty(value = "月份", example = "3月")
    private String x;

    @ApiModelProperty(value = "销售金额", example = "115500.0")
    private BigDecimal y;
}
