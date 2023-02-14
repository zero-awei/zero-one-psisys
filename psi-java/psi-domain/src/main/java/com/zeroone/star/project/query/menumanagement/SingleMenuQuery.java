package com.zeroone.star.project.query.menumanagement;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import javax.validation.constraints.NotBlank;

/**
 * <p>
 * 描述：查询菜单
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 归
 * @version 1.0.0
 */
@EqualsAndHashCode
@Data
@ApiModel("查询菜单对象")
public class SingleMenuQuery {
    @NotBlank(message = "菜单不能空")
    @ApiModelProperty(value = "编号")
    private String id;
}
