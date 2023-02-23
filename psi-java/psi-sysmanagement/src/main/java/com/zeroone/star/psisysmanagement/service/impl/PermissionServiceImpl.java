package com.zeroone.star.psisysmanagement.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.baomidou.mybatisplus.core.metadata.IPage;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.query.sysmanagement.permissionmanagement.PermissionQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.sysmanagement.permissionmanagement.PermissionVO;
import com.zeroone.star.psisysmanagement.entity.Permission;
import com.zeroone.star.psisysmanagement.entity.SysPermission;
import com.zeroone.star.psisysmanagement.mapper.PermissionMapper;
import com.zeroone.star.psisysmanagement.service.IPermissionService;
import com.zeroone.star.psisysmanagement.util.IDGenerator;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;

@Service
public class PermissionServiceImpl extends ServiceImpl<PermissionMapper, Permission> implements IPermissionService {

    @Resource
    private PermissionMapper permissionMapper;

    private final Integer DELETE_FLAG = 0;

    @Override
    public PageVO<PermissionVO> listPermissions(PermissionQuery condition) {
        long pageIndex = condition.getPageIndex();
        long pageSize = condition.getPageSize();

        Page<Permission> page = new Page<>(pageIndex, pageSize);
        QueryWrapper<Permission> queryWrapper = new QueryWrapper<>();
        queryWrapper
                .eq(condition.getPermissionName() != null, "permission_name", condition.getPermissionName())
                .eq(condition.getFatherPermissionName() != null, "father_permission_name", condition.getFatherPermissionName())
                .eq(condition.getFatherUrl() != null, "father_url", condition.getFatherUrl())
                .eq(condition.getPermissionLevel() != null, "permission_level", condition.getPermissionLevel())
                .eq("delete_flag", DELETE_FLAG);
        Page<Permission> page1 = permissionMapper.selectPage(page, queryWrapper);

        // 将查询结果封装成vo
        PageVO<PermissionVO> resultPageVO = PageVO.create(page1, PermissionVO.class);
        List<PermissionVO> rows = resultPageVO.getRows();
        for(PermissionVO row: rows) {
            switch (row.getPermissionType()) {
                case "0":
                    row.setPermissionType("根权限");
                    break;
                case "1":
                    row.setPermissionType("一级权限");
                    break;
                case "2":
                    row.setPermissionType("二级权限");
                    break;
                case "3":
                    row.setPermissionType("三级权限");
                    break;
                default:
                    break;
            }
        }

        return resultPageVO;
    }

    @Override
    public Boolean savePermission(Permission permission) {
        String permissionId = IDGenerator.nextID();
        permission.setPermissionId(permissionId);
        return super.save(permission);
    }

    @Override
    public Boolean removePermission(Permission permission) {
        permission.setDeleteFlag(1);
        return updatePermission(permission);
    }

    @Override
    public Boolean updatePermission(Permission permission) {
        UpdateWrapper<Permission> updateWrapper = new UpdateWrapper<>();
        updateWrapper
                .set(permission.getPermissionName() != null, "permission_name", permission.getPermissionName())
                .set(permission.getPermissionType() != null, "permission_type", permission.getPermissionType())
                .set(permission.getFatherPermissionId() != null, "father_permission_id", permission.getFatherPermissionId())
                .set(permission.getUrl() != null, "url", permission.getUrl())
                .set(permission.getDeleteFlag() != null, "delete_flag", permission.getDeleteFlag())
                .eq("permission_id", permission.getPermissionId());
        return update(updateWrapper);
    }
}
