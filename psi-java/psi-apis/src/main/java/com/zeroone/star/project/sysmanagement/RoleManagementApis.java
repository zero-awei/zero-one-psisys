package com.zeroone.star.project.sysmanagement;

import com.zeroone.star.project.dto.sysmanagement.rolemanagement.SysRoleDTO;
import com.zeroone.star.project.query.sysmanagement.rolemanagement.SysRoleQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.sysmanagement.rolemanagement.SysRoleVO;

import java.util.List;

public interface RoleManagementApis {

    JsonVO<PageVO<SysRoleVO>> queryAll(SysRoleQuery condition);

    JsonVO<String> updateById(SysRoleDTO sysRoleDTO);

    JsonVO<String> insert(SysRoleDTO sysRoleDTO);

    JsonVO<String> deleteById(String id);

}
