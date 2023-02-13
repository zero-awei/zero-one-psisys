package com.zeroone.star.project.query.jurisdiction;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;


@ApiModel("编辑权限对象")
public class JurisdictionQuery {
    @ApiModelProperty(value = "权限id",example = "1")
    private int JId; // 权限id
    @ApiModelProperty(value = "权限名",example = "销售管理")
    private String JName; // 权限名
    @ApiModelProperty(value = "权限描述",example = "此权限用户可以访问销售记录")
    private String JDescribe; // 权限描述
    @ApiModelProperty(value = "url",example = "本权限的访问路径")
    private String JUrl; // url
}
