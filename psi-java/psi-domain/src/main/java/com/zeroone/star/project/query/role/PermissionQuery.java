package com.zeroone.star.project.query.role;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;


@ApiModel("编辑权限对象")
public class PermissionQuery {
    @ApiModelProperty(value = "父id",example = "1")
    private Integer ParentId; // 父id

    @ApiModelProperty(value = "权限id",example = "1")
    private Integer Id; // 权限id

    @ApiModelProperty(value = "权限名",example = "用户列表")
    private String Name; // 权限名

    @ApiModelProperty(value = "url",example = "/result/success")
    private String Url; // url
}
