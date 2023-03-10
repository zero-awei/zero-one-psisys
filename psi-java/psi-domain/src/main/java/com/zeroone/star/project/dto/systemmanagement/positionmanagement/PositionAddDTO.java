package com.zeroone.star.project.dto.systemmanagement.positionmanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @Description add / update /delete
 * @Author mumu
 * @Data 2023-02-11 15:57
 */
@Data
@ApiModel("添加职务DTO")
public class PositionAddDTO {


    @ApiModelProperty(value = "职务编码", example = "devleader")
    private String code;

    @ApiModelProperty(value = "职务名称", example = "研发部经理")
    private String name;

    @ApiModelProperty(value = "职级", example = "2")
    private String postRank;

}
