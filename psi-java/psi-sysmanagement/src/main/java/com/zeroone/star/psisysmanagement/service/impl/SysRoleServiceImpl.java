package com.zeroone.star.psisysmanagement.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.sysmanagement.rolemanagement.SysRoleDTO;
import com.zeroone.star.project.query.sysmanagement.rolemanagement.SysRoleQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.sysmanagement.rolemanagement.SysRoleVO;
import com.zeroone.star.psisysmanagement.entity.SysRole;
import com.zeroone.star.psisysmanagement.mapper.SysRoleMapper;
import com.zeroone.star.psisysmanagement.service.ISysRoleService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import lombok.extern.slf4j.Slf4j;
import org.apache.logging.log4j.util.Strings;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;
import org.springframework.util.StringUtils;

import java.util.ArrayList;
import java.util.Arrays;

/**
 * <p>
 * 角色表 服务实现类
 * </p>
 *
 * @author Gerins
 * @since 2023-02-16
 */
@Slf4j
@Service
public class SysRoleServiceImpl extends ServiceImpl<SysRoleMapper, SysRole> implements ISysRoleService {

    /**
     * 分页查询角色信息
     * @param condition
     * @return 封装后的分页查询结果
     */
    @Override
    public PageVO<SysRoleVO> listAll(SysRoleQuery condition) {
        // 构建分页对象
        Page<SysRole> pageInfo = new Page<>(condition.getPageIndex(), condition.getPageSize());
        // 构建查询条件
        LambdaQueryWrapper<SysRole> lambdaQueryWrapper = new LambdaQueryWrapper<>();
        lambdaQueryWrapper.like(condition.getRoleName() != null, SysRole::getRoleName, condition.getRoleName());
        lambdaQueryWrapper.like(condition.getRoleCode() != null, SysRole::getRoleCode, condition.getRoleCode());
        // 查询结果
        Page<SysRole> result = baseMapper.selectPage(pageInfo, lambdaQueryWrapper);
        return PageVO.create(result, SysRoleVO.class);
    }

    /**
     * 修改角色信息
     * @param sysRoleDTO
     * @return 修改是否成功
     */
    @Override
    public Boolean modify(SysRoleDTO sysRoleDTO) {
        // 先判断id是否传过来
        String roleDTOId = sysRoleDTO.getId();
        if (Strings.isBlank(roleDTOId)) {
            // 没id就无法修改，失败
            return false;
        }
        // 再查询是否存在该角色
        SysRole sysRole = baseMapper.selectById(roleDTOId);
        if (sysRole == null) {
            // 不存在该角色修改失败
            return false;
        }

        // 执行修改操作
        SysRole role = new SysRole();
        BeanUtils.copyProperties(sysRoleDTO, role);
        baseMapper.updateById(role);

        return true;
    }

    /**
     * 新增角色
     * @param sysRoleDTO
     * @return 新增是否成功
     */
    @Override
    public Boolean save(SysRoleDTO sysRoleDTO) {
        // 先查询是否存在该角色
        String roleDTOId = sysRoleDTO.getId();
        SysRole sysRole = baseMapper.selectById(roleDTOId);
        if (sysRole != null) {
            // 说明已经存在该角色，插入失败
            return false;
        }

        // 执行插入操作
        SysRole role = new SysRole();
        BeanUtils.copyProperties(sysRoleDTO, role);
        baseMapper.insert(role);

        return true;
    }

    /**
     * 删除角色
     * @param ids
     * @return 删除是否成功
     */
    @Override
    public Boolean remove(String[] ids) {
        baseMapper.deleteBatchIds(Arrays.asList(ids));
        return true;
    }
}
