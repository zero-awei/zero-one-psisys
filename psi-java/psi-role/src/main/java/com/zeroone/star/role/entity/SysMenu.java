package com.zeroone.star.role.entity;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;

import java.io.Serializable;

@ApiModel("编辑菜单对象")
public class SysMenu implements Serializable {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "父id",example = "1")
    private Integer ParentId;

    @ApiModelProperty(value = "菜单id",example = "1")
    private int Id; // 菜单id

    @ApiModelProperty(value = "菜单名",example = "销售管理")
    private String Name; // 菜单名

    @ApiModelProperty(value = "url",example = "本菜单的访问路径")
    private String Url; // url
}
