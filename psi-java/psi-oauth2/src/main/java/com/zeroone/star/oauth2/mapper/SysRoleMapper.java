package com.zeroone.star.oauth2.mapper;

import com.zeroone.star.oauth2.entity.SysRole;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 * 角色表 Mapper 接口
 * </p>
 *
 * @author Gerins
 * @since 2023-02-22
 */
@Mapper
public interface SysRoleMapper extends BaseMapper<SysRole> {

    /**
     * 通过用户编号查询角色
     * @param userId 用户编号
     * @return 角色列表
     */
    List<SysRole> selectByUserId(String userId);

    /**
     * 通过菜单路径获取对应的角色
     * @param path 菜单路径
     * @return 角色列表
     */
    List<SysRole> selectByMenuPath(String path);

    /**
     * 通过用户名查询机构编码
     * @param username 用户名
     * @return 机构编码
     */
    String selectOrgCodeByUsername(String username);
}
