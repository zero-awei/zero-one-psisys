package com.zeroone.star.project.vo.login;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：树状菜单显示数据
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
@Data
public class MenuTreeVO {
    @ApiModelProperty(value = "序号", example = "1")
    private String id;
    @ApiModelProperty(value = "菜单名称", example = "获取菜单列表")
    private String name;
    @ApiModelProperty(value = "路由地址", example = "")
    private String path;
    @ApiModelProperty(value = "图标", example = "fa-stethoscope")
    private String icon;
    @ApiModelProperty(value = "父级菜单编号", example = "")
    private String parentMenuId;
}
