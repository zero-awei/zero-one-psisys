package com.zeroone.star.systemmanagement.service.organizationmanagement.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.systemmanagement.organizationmanagement.OrganizationManagementDTO;
import com.zeroone.star.project.query.systemmanagement.organizationmanagement.OrganizationListQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.organizationmanagement.OrganizationListVO;
import com.zeroone.star.project.vo.systemmanagement.organizationmanagement.OrganizationTreeVO;
import com.zeroone.star.systemmanagement.entity.organizationmanagement.SysDepart;
import com.zeroone.star.systemmanagement.mapper.organizationmanagement.OrganizationmanagementMapper;
import com.zeroone.star.systemmanagement.service.organizationmanagement.OrganizationmanagementService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 组织机构表 服务实现类
 * </p>
 *
 * @author Morrangee
 * @since 2023-02-13
 */
@Service
public class OrganizationmanagementImpl extends ServiceImpl<OrganizationmanagementMapper, SysDepart> implements OrganizationmanagementService {
    @Autowired
    private OrganizationmanagementMapper mapper;

    @Override
    public PageVO<OrganizationListVO> queryList(OrganizationListQuery condition) {
        // 从第一页开始，每一页查6条数据
        Page<SysDepart> page = new Page<>(1, 6);
        QueryWrapper<SysDepart> wrapper = new QueryWrapper<>();
        wrapper.eq("departName", condition.getDepartName());
        Page<SysDepart> p = mapper.selectPage(page, wrapper);
        return PageVO.create(p, OrganizationListVO.class);
    }

    @Override
    public JsonVO<OrganizationTreeVO> queryTree(String departName) {
        SysDepart sysDepart = mapper.selectById(departName);
        String parentId = sysDepart.getParentId();
        OrganizationTreeVO treeVO = new OrganizationTreeVO();
        treeVO.setDepartName(departName);
        treeVO.setParentId(parentId);
        return JsonVO.success(treeVO);
    }

    @Override
    public String add(OrganizationManagementDTO data) {
        SysDepart sysDepart = new SysDepart();
        BeanUtil.copyProperties(data, sysDepart);
        int result = mapper.insert(sysDepart);
        if (result == 0) {
            return "新增失败";
        }
        return "新增成功";
    }

    @Override
    public String modify(OrganizationManagementDTO data) {
        SysDepart sysDepart = new SysDepart();
        BeanUtil.copyProperties(data, sysDepart);
        int result = mapper.updateById(sysDepart);
        if (result == 0) {
            return "更新失败";
        }
        return "更新成功";
    }

    @Override
    public String remove(String id) {
        int result = mapper.deleteById(id);
        if (result == 0) {
            return "删除失败";
        }
        return "删除成功";
    }
}
