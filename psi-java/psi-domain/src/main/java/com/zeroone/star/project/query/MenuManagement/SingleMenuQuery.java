package com.zeroone.star.project.query.MenuManagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import javax.validation.constraints.NotBlank;

/**
 * @author xiaoyolee
 * @version 1.0
 */
@EqualsAndHashCode()
@Data
@ApiModel("查询菜单对象")
public class SingleMenuQuery {
    @NotBlank(message = "菜单不能为空")
    @ApiModelProperty(value = "编号", example = "3")
    private String id;
}
