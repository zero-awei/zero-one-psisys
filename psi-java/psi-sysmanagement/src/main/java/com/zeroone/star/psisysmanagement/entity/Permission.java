package com.zeroone.star.psisysmanagement.entity;

import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class Permission implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 权限编号
     */
    private String permissionId;

    /**
     * 权限名称
     */
    private String permissionName;

    /**
     * 权限对应的url
     */
    private String url;

    /**
     * 父权限id
     */
    private String fatherPermissionId;

    /**
     * 权限类型；0表示系统权限，有且只有一个。1一级权限，2二级权限，3三级权限
     */
    private Integer permissionType;

    /**
     * 权限介绍
     */
    private String instruction;
}
