package com.zeroone.star.psisysmanagement.service;

import com.zeroone.star.project.dto.sysmanagement.rolemanagement.SysRoleDTO;
import com.zeroone.star.project.query.sysmanagement.rolemanagement.SysRoleQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.sysmanagement.rolemanagement.SysRoleVO;
import com.zeroone.star.psisysmanagement.entity.SysRole;
import com.baomidou.mybatisplus.extension.service.IService;

/**
 * <p>
 * 角色表 服务类
 * </p>
 *
 * @author Gerins
 * @since 2023-02-16
 */
public interface ISysRoleService extends IService<SysRole> {

    /**
     * 分页查询角色信息
     * @param condition
     * @return 查询结果SysRoleVO
     */
    PageVO<SysRoleVO> listAll(SysRoleQuery condition);

    /**
     * 修改角色信息
     * @param sysRoleDTO
     * @return 修改是否成功
     */
    Boolean modify(SysRoleDTO sysRoleDTO);

    /**
     * 新增角色
     * @param sysRoleDTO
     * @return 新增是否成功
     */
    Boolean save(SysRoleDTO sysRoleDTO);

    /**
     * 删除角色
     * @param ids
     * @return 删除是否成功
     */
    Boolean remove(String[] ids);
}
