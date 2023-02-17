package com.zeroone.star.project.sysmanagement;

import com.zeroone.star.project.dto.sysmanagement.permissionmanagement.PermissionDTO;
import com.zeroone.star.project.query.sysmanagement.permissionmanagement.PermissionQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.sysmanagement.permissionmanagement.PermissionVO;

/**
 * @Author Freasy
 * @Version 1.0
 */
public interface PermissionApis {
    /**
     * 分页查询所有
     * @param condition 查询条件
     * @return 查询结果
     */
    JsonVO<PageVO<PermissionVO>> queryAll(PermissionQuery condition);

    /**
     * 根据用户输入的条件，分页查询
     * @param condition 查询条件
     * @return 查询结果
     */
    JsonVO<PageVO<PermissionVO>> queryByCondition(PermissionQuery condition);

    /**
     *
     * @param permissionInfo 要删除的权限的相关信息
     * @return 删除结果
     */
    JsonVO<String> delete(PermissionDTO permissionInfo);

    /**
     * 更新权限信息
     * @param permissionInfo 需要更新的权限的相关信息
     * @return 更新结果
     */
    JsonVO<String> update(PermissionDTO permissionInfo);

    /**
     * 新增权限
     * @param permissionInfo 新增权限的相关信息
     * @return 保存的结果
     */
    JsonVO<String> addPermission(PermissionDTO permissionInfo);


}
