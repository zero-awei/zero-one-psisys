package com.zeroone.star.project.query.homepage;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：销售金额概况查询对象
 * </p>
 * @author YinXing
 * @date 2023年02月11日
 */
@Data
@ApiModel("销售金额概况查询对象")
public class SalesAmountIformationQuery {

    @ApiModelProperty(value = "id", example = "1580915783778701314")
    private String id;
}
