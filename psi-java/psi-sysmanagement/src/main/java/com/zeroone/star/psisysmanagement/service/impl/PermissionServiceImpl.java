package com.zeroone.star.psisysmanagement.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.query.sysmanagement.rolemanagement.PermissionQuery;
import com.zeroone.star.psisysmanagement.entity.SysPermission;
import com.zeroone.star.psisysmanagement.mapper.PermissionMapper;
import com.zeroone.star.psisysmanagement.service.IPermissionService;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

@Service
public class PermissionServiceImpl extends ServiceImpl<PermissionMapper, SysPermission> implements IPermissionService {

    @Override
    public List<PermissionQuery> showList(String RId) { // RId 是 父id ？
        QueryWrapper<SysPermission> lisPermission = new QueryWrapper<>();
        lisPermission.eq("parent_id",RId);
        List<SysPermission> permissions = baseMapper.selectList(lisPermission);
        List<PermissionQuery> list = new ArrayList<>();
        System.out.println("==============================");
        for (SysPermission permission : permissions) {
            PermissionQuery permissionQuery = new PermissionQuery();
            BeanUtil.copyProperties(permission,permissionQuery);
            System.out.println(permissionQuery);
            list.add(permissionQuery);
        }
        System.out.println("========================");
        return list;
    }

    @Override
    public Boolean addMenuOrPermission(PermissionQuery permission) {
        SysPermission sysPermission = new SysPermission();
        BeanUtil.copyProperties(permission,sysPermission);
        int num = baseMapper.insert(sysPermission);
        if (num >= 1){
            System.out.println("+++++++++++++"+num+"+++++++++++");
            System.out.println(sysPermission);
            return true;
        }
        return false;
    }

    @Override
    public Boolean deleteMenuOrPermission(String Id) {
        int num = baseMapper.deleteById(Id);
        if (num >= 1) {
            System.out.println("+++++++++++++++++++++++"+num+"++++++++++++++++++++++++");
            return true;
        }
        return false;
    }
}
