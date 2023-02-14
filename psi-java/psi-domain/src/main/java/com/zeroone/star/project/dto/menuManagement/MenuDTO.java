package com.zeroone.star.project.dto.menuManagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * 获取菜单返回信息封装
 * @author xiaoyolee
 * @version 1.0
 */
@ApiModel("授权登录上传数据对象")
@Data
@NoArgsConstructor
@AllArgsConstructor
public class MenuDTO {
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
