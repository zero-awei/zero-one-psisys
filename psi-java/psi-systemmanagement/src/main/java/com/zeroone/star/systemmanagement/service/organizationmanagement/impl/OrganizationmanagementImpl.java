package com.zeroone.star.systemmanagement.service.organizationmanagement.impl;

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
import com.zeroone.star.systemmanagement.service.organizationmanagement.IOrganizationmanagementService;
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
public class OrganizationmanagementImpl extends ServiceImpl<OrganizationmanagementMapper, SysDepart> implements IOrganizationmanagementService {
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
        sysDepart.setId(data.getId());
        sysDepart.setParentId(data.getParentId());
        sysDepart.setDepartName(data.getDepartName());
        sysDepart.setDepartNameEn(data.getDepartNameEn());
        sysDepart.setDepartNameEn(data.getDepartNameAbbr());
        sysDepart.setDepartOrder(data.getDepartOrder());
        sysDepart.setDescription(data.getDescription());
        sysDepart.setOrgCategory(data.getOrgCategory());
        sysDepart.setOrgType(data.getOrgType());
        sysDepart.setOrgCode(data.getOrgCode());
        sysDepart.setMobile(data.getMobile());
        sysDepart.setFax(data.getFax());
        sysDepart.setAddress(data.getAddress());
        sysDepart.setMemo(data.getMemo());
        sysDepart.setStatus(data.getStatus());
        sysDepart.setDelFlag(data.getDelFlag());
        sysDepart.setQywxIdentifier(data.getQywxIdentifier());
        sysDepart.setCreateBy(data.getCreatBy());
        sysDepart.setCreateTime(data.getCreatTime());
        sysDepart.setUpdateBy(data.getUpdateBy());
        sysDepart.setUpdateTime(data.getUpdateTime());
        mapper.insert(sysDepart);
        return "新增完毕";
    }

    @Override
    public String modify(OrganizationManagementDTO data) {
        SysDepart sysDepart = new SysDepart();
        sysDepart.setId(data.getId());
        sysDepart.setParentId(data.getParentId());
        sysDepart.setDepartName(data.getDepartName());
        sysDepart.setDepartNameEn(data.getDepartNameEn());
        sysDepart.setDepartNameEn(data.getDepartNameAbbr());
        sysDepart.setDepartOrder(data.getDepartOrder());
        sysDepart.setDescription(data.getDescription());
        sysDepart.setOrgCategory(data.getOrgCategory());
        sysDepart.setOrgType(data.getOrgType());
        sysDepart.setOrgCode(data.getOrgCode());
        sysDepart.setMobile(data.getMobile());
        sysDepart.setFax(data.getFax());
        sysDepart.setAddress(data.getAddress());
        sysDepart.setMemo(data.getMemo());
        sysDepart.setStatus(data.getStatus());
        sysDepart.setDelFlag(data.getDelFlag());
        sysDepart.setQywxIdentifier(data.getQywxIdentifier());
        sysDepart.setCreateBy(data.getCreatBy());
        sysDepart.setCreateTime(data.getCreatTime());
        sysDepart.setUpdateBy(data.getUpdateBy());
        sysDepart.setUpdateTime(data.getUpdateTime());
        mapper.updateById(sysDepart);
        return "修改完毕";
    }

    @Override
    public String delete(String id) {
        mapper.deleteById(id);
        return "删除完毕";
    }
}
