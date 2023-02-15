package com.zeroone.star.project.systemmanagement.addressbook;

import com.zeroone.star.project.query.systemmanagement.addressbook.OrganizationTreeQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.addressbook.OrganizationTreeVO;

/**
 * <p>
 * 描述：查询指定组织结构树接口定义
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 西柚珍珠蜜
 * @version 1.0.0
 */

public interface OrganizationTreeApis {

    /**
     * 查询指定组织结构树
     * @param condition 查询条件
     * @return 查询结果
     */
    JsonVO<PageVO<OrganizationTreeVO>> queryOrganizationTree(OrganizationTreeQuery condition);

}
