package com.zeroone.star.psisysmanagement.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.query.sysmanagement.rolemanagement.PermissionQuery;
import com.zeroone.star.psisysmanagement.entity.Permission;
import com.zeroone.star.psisysmanagement.mapper.PermissionMapper;
import com.zeroone.star.psisysmanagement.service.IPermissionService;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

/**
*
* @Author:阿狸
* @Version:1.1
*/
@Service
public class PermissionServiceImpl extends ServiceImpl<PermissionMapper, Permission> implements IPermissionService {

    /**
     *
     * @param RId
     * @return
     */
    @Override
    public List<PermissionQuery> listAll(String RId) {
        QueryWrapper<Permission> lisPermission = new QueryWrapper<>();
        lisPermission.eq("father_permission_id",RId);
        List<Permission> permissions = baseMapper.selectList(lisPermission);
        List<PermissionQuery> list = new ArrayList<>();
        for (Permission permission : permissions) {
            PermissionQuery permissionQuery = new PermissionQuery();
            BeanUtil.copyProperties(permission,permissionQuery);
            list.add(permissionQuery);
        }
        return list;
    }

    @Override
    public Boolean savePermission(PermissionQuery permissionQuery) {
        Permission permission = new Permission();
        BeanUtil.copyProperties(permissionQuery,permission);
        int num = baseMapper.insert(permission);
        if (num >= 1){
            return true;
        }
        return false;
    }

    @Override
    public Boolean deletePermission(String permissionId) {
        int num = baseMapper.deleteById(permissionId);
        if (num >= 1) {
            return true;
        }
        return false;
    }
}
