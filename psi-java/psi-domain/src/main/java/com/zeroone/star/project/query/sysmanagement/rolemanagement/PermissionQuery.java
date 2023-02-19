package com.zeroone.star.project.query.sysmanagement.rolemanagement;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.validation.constraints.Max;
import javax.validation.constraints.Min;
import javax.validation.constraints.NotBlank;

@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("编辑权限对象")
public class PermissionQuery {

    /**
     * 权限编号
     */
    @TableId(type = IdType.ASSIGN_UUID)
    @ApiModelProperty(value = "权限编号")
    private String permissionId;

    /**
     * 权限名称
     */
    @ApiModelProperty(value = "权限名称",example = "成功")
    @NotBlank(message = "权限名称不能为空")
    private String permissionName;

    /**
     * 权限对应的url
     */
    @ApiModelProperty(value = "权限对应的url",example = "/result/success")
    @NotBlank(message = "权限对应的url不能为空")
    private String url;

    /**
     * 父权限id
     */
    @ApiModelProperty(value = "父权限id",example = "2e42e3835c2b44ec9f7bc26c146ee531")
    @NotBlank(message = "父id不能为空")
    private String fatherPermissionId;

    /**
     * 权限类型；0表示系统权限，有且只有一个。1一级权限，2二级权限，3三级权限
     */
    @ApiModelProperty(value = "权限类型",example = "2")
    @Min(value = 0,message = "不能小于0")
    @Max(value = 3,message = "不能大于3" )
    private Integer permissionType;

    /**
     * 权限介绍
     */
    @ApiModelProperty(value = "权限介绍")
    private String instruction;
}
