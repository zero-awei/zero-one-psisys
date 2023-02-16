package com.zeroone.star.systemmanagement.service.organizationmanagement.impl;

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

    private OrganizationmanagementMapper mapper;
    @Override
    public JsonVO<PageVO<OrganizationListVO>> queryList(OrganizationListQuery condition) {
        return null;
    }

    @Override
    public JsonVO<PageVO<OrganizationTreeVO>> queryTree(String departName) {
        return null;
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
        return null;
    }
}
