package com.zeroone.star.project.vo.homepage;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author Third uncle
 * @date 2023/2/12 - 18:15
 */
@Data
@ApiModel("显示对象")
public class SalOrderVO {
    @ApiModelProperty(value = "月份",example = "3月")
    private String x;
    @ApiModelProperty(value = "毛利润",example = "0.0")
    private String y;
}
