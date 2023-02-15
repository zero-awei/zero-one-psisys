package com.zeroone.star.project.query.systemmanagement.positionmanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @Description list / conditional select
 * @Author mumu
 * @Data 2023-02-11 16:21
 */
@Data
@ApiModel("职务查询Query")
public class PositionQuery {
    @ApiModelProperty(value = "职务编码", example = "devleader")
    private String code;

    @ApiModelProperty(value = "职务名称", example = "研发部经理")
    private String name;

    @ApiModelProperty(value = "职级", example = "2")
    private String postRank;
}
