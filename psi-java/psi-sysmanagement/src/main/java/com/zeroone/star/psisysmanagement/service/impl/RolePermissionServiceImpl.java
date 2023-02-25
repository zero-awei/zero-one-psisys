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
import com.zeroone.star.psisysmanagement.service.IRolePermissionService;
import com.zeroone.star.psisysmanagement.util.IDGenerator;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.List;

/**
*
* @Author:阿狸
* @Version:1.1
*/
@Service
public class RolePermissionServiceImpl extends ServiceImpl<PermissionMapper, Permission> implements IRolePermissionService {

     */
    @Override
            list.add(permissionQuery);
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
