package com.zeroone.star.project.dto.sysmanagement.rolemanagement;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;
import java.util.Date;

@Data
@ApiModel("角色传输数据对象")
public class SysRoleDTO {

    @ApiModelProperty(value = "角色id", example = "f6817f48af4fb3af11b9e8bf182f618b")
    private String id;
    @ApiModelProperty(value = "角色名称", example = "管理员")
    private String roleName;
    @ApiModelProperty(value = "角色编码", example = "admin")
    private String roleCode;
    @ApiModelProperty(value = "描述", example = "管理员")
    private String description;

    @ApiModelProperty(value = "创建人", example = "admin")
    private String createBy;

    @JsonFormat(pattern = "yyyy-MM-dd HH-mm-ss")
    @ApiModelProperty(value = "创建时间", example = "2018-12-21 18:03:39")
    private Date createTime;

    @ApiModelProperty(value = "更新人", example = "admin")
    private String updateBy;

    @JsonFormat(pattern = "yyyy-MM-dd HH-mm-ss")
    @ApiModelProperty(value = "更新时间", example = "2019-05-20 11:40:26")
    private Date updateTime;
}
