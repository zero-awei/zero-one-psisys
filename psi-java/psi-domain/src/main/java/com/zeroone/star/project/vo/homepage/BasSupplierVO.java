package com.zeroone.star.project.vo.homepage;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author Third uncle
 * @date 2023/2/12 - 18:23
 */
@Data
@ApiModel("显示对象")
public class BasSupplierVO {
    @ApiModelProperty(value = "月份",example = "今日+")
    private String label;
    @ApiModelProperty(value = "供应商数",example = "0")
    private String value;
    @ApiModelProperty(value = "width",example = "5")
    private String width;
}
