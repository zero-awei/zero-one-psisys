package com.zeroone.star.project.vo.systemmanagement.positionmanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @Description position select returned  VO
 * @Author mumu
 * @Data 2023-02-11 16:32
 */
@Data
@ApiModel("职务查询返回对象VO")
public class PositionVO {

    @ApiModelProperty(value = "职务对象ID",example = "1624315388342083586")
    private String Id;

    @ApiModelProperty(value = "职务编码", example = "devleader")
    private String code;

    @ApiModelProperty(value = "职务名称", example = "研发部经理")
    private String name;

    @ApiModelProperty(value = "职级", example = "2")
    private String postRank;

}
