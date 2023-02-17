package com.zeroone.star.project.sysmanagement;

import com.zeroone.star.project.dto.sysmanagement.rolemanagement.SysRoleDTO;
import com.zeroone.star.project.query.sysmanagement.rolemanagement.SysRoleQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.sysmanagement.rolemanagement.SysRoleVO;

import java.util.List;

public interface RoleManagementApis {

    /**
     * 根据条件分页查询角色信息
     * @param condition
     * @return 分页查询角色列表
     */
    JsonVO<PageVO<SysRoleVO>> queryAll(SysRoleQuery condition);

    /**
     * 修改角色信息
     * @param sysRoleDTO
     * @return 是否成功
     */
    JsonVO<String> updateById(SysRoleDTO sysRoleDTO);

    /**
     * 添加角色
     * @param sysRoleDTO
     * @return 是否成功
     */
    JsonVO<String> insert(SysRoleDTO sysRoleDTO);

    /**
     * 根据id删除角色
     * @param id
     * @return 是否成功
     */
    JsonVO<String> deleteById(String id);

}
