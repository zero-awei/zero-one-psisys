package com.zeroone.star.systemmanagement.service.organizationmanagement;

import com.zeroone.star.project.dto.systemmanagement.organizationmanagement.OrganizationManagementDTO;
import com.zeroone.star.project.query.systemmanagement.organizationmanagement.OrganizationListQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.organizationmanagement.OrganizationListVO;
import com.zeroone.star.project.vo.systemmanagement.organizationmanagement.OrganizationTreeVO;
import com.zeroone.star.systemmanagement.entity.organizationmanagement.SysDepart;
import com.baomidou.mybatisplus.extension.service.IService;

/**
 * <p>
 * 组织机构表 服务类
 * </p>
 *
 * @author Morrangee
 * @since 2023-02-13
 */
public interface IOrganizationmanagementService extends IService<SysDepart> {

    public PageVO<OrganizationListVO> queryList(OrganizationListQuery condition);
    public JsonVO<OrganizationTreeVO> queryTree(String departName);
    public String add(OrganizationManagementDTO data);
    public String modify(OrganizationManagementDTO data);
    public String delete(String id);
}
