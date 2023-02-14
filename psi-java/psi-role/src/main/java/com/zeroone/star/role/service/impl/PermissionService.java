package com.zeroone.star.role.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.query.role.PermissionQuery;
import com.zeroone.star.role.entity.SysPermission;
import com.zeroone.star.role.mapper.PermissionMapper;
import com.zeroone.star.role.service.IPermissionService;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class PermissionService extends ServiceImpl<PermissionMapper, SysPermission> implements IPermissionService {

    @Override
    public List<PermissionQuery> showList(int RId) {
        return null;
    }

    @Override
    public Boolean addMenuOrJurisdiction(List<PermissionQuery> listMenu) {
        return null;
    }

    @Override
    public Boolean deleteMenuOrJurisdiction(int RId, int MId) {
        return null;
    }
}
