package com.zeroone.star.project.query.sysmanagement.permissionmanagement;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import javax.validation.constraints.NotBlank;

/**
 * @Author Freasy
 * @Version 1.0
 */
@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("权限查询对象")
public class PermissionQuery extends PageQuery {
    @ApiModelProperty(value = "权限名称", example = "Redis监控")
    private String permissionName;

    @ApiModelProperty(value = "权限路径", example = "/monitor/redis/info")
    private String url;

    @ApiModelProperty(value = "权限等级", example = "1")
    private Integer permissionLevel;

    @ApiModelProperty(value = "父权限名称", example = "性能监控")
    private String fatherPermissionName;

    @ApiModelProperty(value = "父权限路径", example = "/monitor")
    private String fatherUrl;
}
