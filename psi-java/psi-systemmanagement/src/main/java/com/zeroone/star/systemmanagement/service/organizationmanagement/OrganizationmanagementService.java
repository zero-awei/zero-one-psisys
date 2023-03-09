package com.zeroone.star.systemmanagement.service.organizationmanagement;

import com.zeroone.star.project.dto.systemmanagement.organizationmanagement.OrganizationManagementDTO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.query.systemmanagement.organizationmanagement.OrganizationListQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.organizationmanagement.OrganizationListVO;
import com.zeroone.star.project.vo.systemmanagement.organizationmanagement.OrganizationTreeVO;
import com.zeroone.star.systemmanagement.entity.organizationmanagement.SysDepart;
import com.baomidou.mybatisplus.extension.service.IService;

import java.util.List;

/**
 * <p>
 * 组织机构表 服务类
 * </p>
 *
 * @author Morrangee
 * @since 2023-02-13
 */
public interface OrganizationmanagementService extends IService<SysDepart> {

    public PageVO<OrganizationListVO> queryList(PageQuery condition);
    public List<OrganizationTreeVO> queryTree(String departName);
    public String add(OrganizationManagementDTO data);
    public String modify(OrganizationManagementDTO data);
    public String remove(String id);
}
