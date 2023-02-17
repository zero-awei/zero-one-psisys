package com.zeroone.star.project.query.prepayment;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

@EqualsAndHashCode(callSuper = false)
@Data
@ApiModel("id查询")
public class IdQuery {
    @ApiModelProperty(value = "id",example = "")
    private String id;
}
