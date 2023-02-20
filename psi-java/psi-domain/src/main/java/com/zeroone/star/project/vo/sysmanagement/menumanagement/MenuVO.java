package com.zeroone.star.project.vo.sysmanagement.menumanagement;

import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;

/**
 * @author xiaoyolee
 * @version 1.0
 */
@Getter
@Setter
public class MenuVO {
    @ApiModelProperty(value = "序号", example = "1")
    private Integer id;
    @ApiModelProperty(value = "菜单名称", example = "获取菜单列表")
    private String name;
    @ApiModelProperty(value = "路由地址", example = "/home")
    private String path;
    @ApiModelProperty(value = "图标", example = "fa-stethoscope")
    private String icon;
    @ApiModelProperty(value = "父级菜单编号", example = "1")
    private Integer parentMenuId;
}
