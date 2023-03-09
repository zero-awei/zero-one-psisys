package com.zeroone.star.project.systemmanagement.organizationmanagement;

import com.zeroone.star.project.dto.systemmanagement.organizationmanagement.OrganizationManagementDTO;
import com.zeroone.star.project.query.systemmanagement.organizationmanagement.OrganizationListQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.organizationmanagement.OrganizationListVO;
import com.zeroone.star.project.vo.systemmanagement.organizationmanagement.OrganizationTreeVO;

import java.util.List;


/**
 *
 */
public interface OrganizationManagementApis {

    /**
     * 查询组织列表
     * @param condition 查询条件
     * @return 查询结果
     */
    JsonVO<PageVO<OrganizationListVO>> queryList(OrganizationListQuery condition);

    /**
     * 查询指定组织结构树
     *
     * @param departName 部门名称
     * @return 查询到的结构树属性
     */
    JsonVO<List<OrganizationTreeVO>> queryTree(String departName);

    /**
     * 新增组织结构
     *
     * @param data 数据
     * @return 是否添加成功
     */
    JsonVO<String> add(OrganizationManagementDTO data);

    /**
     * 修改组织结构
     * @param data 数据
     * @return 是否更新成功
     */
    JsonVO<String> modify(OrganizationManagementDTO data);

    /**
     * 删除指定组织结构
     *
     * @param id 部门id
     * @return 是否删除成功
     */
    JsonVO<String> remove(String id);

}
