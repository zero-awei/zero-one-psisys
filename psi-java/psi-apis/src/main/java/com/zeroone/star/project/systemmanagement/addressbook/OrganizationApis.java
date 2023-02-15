package com.zeroone.star.project.systemmanagement.addressbook;

import com.zeroone.star.project.query.systemmanagement.addressbook.OrganizationQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.addressbook.OrganizationVO;

/**
 * <p>
 * 描述：查询组织列表接口定义
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 西柚珍珠蜜
 * @version 1.0.0
 */

public interface OrganizationApis {


    /**
     * 查询组织列表
     * @param condition 查询条件
     * @return 查询结果
     */
    JsonVO<PageVO<OrganizationVO>> queryOrganization(OrganizationQuery condition);




}
