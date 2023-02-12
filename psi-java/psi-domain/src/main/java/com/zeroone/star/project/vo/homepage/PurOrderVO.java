package com.zeroone.star.project.vo.homepage;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author Third uncle
 * @date 2023/2/12 - 18:19
 */
@Data
@ApiModel("显示对象")
public class PurOrderVO {

    @ApiModelProperty(value = "月份",example = "1")
    private String x;
    @ApiModelProperty(value = "采购金额",example = "0.0")
    private String y;

}
