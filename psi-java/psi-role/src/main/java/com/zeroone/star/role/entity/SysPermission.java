package com.zeroone.star.role.entity;

import io.swagger.annotations.ApiModelProperty;

import java.io.Serializable;

public class SysPermission implements Serializable {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "父id",example = "1")
    private Integer ParentId; // 父id

    @ApiModelProperty(value = "权限id",example = "1")
    private Integer Id; // 权限id

    @ApiModelProperty(value = "权限名",example = "用户列表")
    private String Name; // 权限名

    @ApiModelProperty(value = "url",example = "/result/success")
    private String Url; // url
}
