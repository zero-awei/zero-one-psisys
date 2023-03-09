package com.zeroone.star.login.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.login.entity.Menu;
import com.zeroone.star.login.entity.SysMenu;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author Gerins
 * @since 2023-02-22
 */
@Mapper
public interface SysMenuMapper extends BaseMapper<SysMenu> {
    /**
     * 通过角色名获取对应的菜单资源
     * @param roleCode 角色编码
     * @return 返回菜单列表
     */
    List<SysMenu> selectByRoleCode(String roleCode);
}
