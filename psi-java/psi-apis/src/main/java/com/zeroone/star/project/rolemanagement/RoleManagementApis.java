package com.zeroone.star.project.rolemanagement;

import com.zeroone.star.project.dto.rolemanagement.SysRoleDTO;
import com.zeroone.star.project.query.rolemanagement.SysRoleQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.rolemanagement.SysRoleVO;
import io.swagger.models.auth.In;

public interface RoleManagementApis {

    JsonVO<PageVO<SysRoleVO>> queryAll(SysRoleQuery condition);

    JsonVO<String> updateById(SysRoleDTO sysRoleDTO);

    JsonVO<String> insert(SysRoleDTO sysRoleDTO);

    JsonVO<String> deleteById(String id);

}
