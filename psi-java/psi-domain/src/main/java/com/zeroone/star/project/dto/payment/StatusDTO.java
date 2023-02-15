package com.zeroone.star.project.dto.payment;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * 修改状态DTO
 * author yu-hang
 */
@Data
@ApiModel("修改状态功能")
public class StatusDTO {
    @ApiModelProperty(value = "id")
    private String id;
}
