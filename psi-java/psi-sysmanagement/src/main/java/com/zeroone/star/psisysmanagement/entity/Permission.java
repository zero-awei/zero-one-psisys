package com.zeroone.star.psisysmanagement.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.*;

/**
 * @Description 权限类
 * @Author Freasy
 * @Date 2023-02-18
 * @Version 1.0
 */
@Getter
@Setter
@TableName("permission")
public class Permission {
    /**
     * 权限id
     */
    private String permissionId;

    /**
     * 权限名称
     */
    private String permissionName;

    /**
     * 权限对应的路径
     */
    private String url;

    /**
     * 父权限的id
     */
    private String fatherPermissionId;

    /**
     * 权限类型
     */
    private String permissionType;

    /**
     * 权限说明
     */
    private String instruction;

    /**
     * 权限删除标志
     */
    private Integer deleteFlag;
}
