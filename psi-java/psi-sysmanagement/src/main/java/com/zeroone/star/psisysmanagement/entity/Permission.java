package com.zeroone.star.psisysmanagement.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;

/**
*
* @Author:阿狸
* @Version:1.1
*/
@Getter
@Setter
@TableName("permission")
public class Permission implements Serializable {
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
    private Integer permissionType;

    /**
     * 权限说明
     */
    private String instruction;
}
