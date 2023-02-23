package com.zeroone.star.project.vo.sysmanagement.permissionmanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * @Author Freasy
 * @Version 1.0
 */
@ApiModel("权限显示对象")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class PermissionVO {
    @ApiModelProperty(value = "权限名称", example = "Redis监控")
    private String permissionName;

    @ApiModelProperty(value = "权限路径", example = "/monitor/redis/info")
    private String url;

    @ApiModelProperty(value = "权限等级", example = "2")
    private String permissionType;

    @ApiModelProperty(value = "父权限名称", example = "性能监控")
    private String fatherPermissionName;

    @ApiModelProperty(value = "父权限路径", example = "/monitor")
    private String fatherUrl;

    @ApiModelProperty(value = "对权限的说明", example = "拥有该权限的人可以对后台redis进行监控")
    private String instruction;

    @ApiModelProperty(value = "权限删除标志", example = "0")
    private Integer deleteFlag;
}
