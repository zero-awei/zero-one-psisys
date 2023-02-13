package com.zeroone.star.project.vo.homepage;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;

/**
 * <p>
 * 描述：系统收支概况视图对象
 * </p>
 * @author YinXing
 * @date 2023年02月11日
 */
@Data
@ApiModel("系统收支概况视图对象")
public class SystemRevenueAndExpenditureInformationVO {

    @ApiModelProperty(value = "系统收支属性", example = "即时库存(元)")
    private String label;

    @ApiModelProperty(value = "价值", example = "98600")
    private BigDecimal value;

}