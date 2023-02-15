package com.zeroone.star.systemmanagement.service.addressbook;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.query.systemmanagement.addressbook.OrganizationQuery;
import com.zeroone.star.project.query.systemmanagement.addressbook.OrganizationTreeQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.addressbook.OrganizationTreeVO;
import com.zeroone.star.project.vo.systemmanagement.addressbook.OrganizationVO;
import com.zeroone.star.systemmanagement.entity.addressbook.SysDepart;

/**
 * <p>
 * 描述：组织机构业务层接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 西柚珍珠蜜
 * @version 1.0.0
 */
public interface ISysDepartService extends IService<SysDepart> {

    /**
     * 查询组织列表
     * @param query 查询条件
     * @return 查询结果
     */
    PageVO<OrganizationVO> listOrganization(OrganizationQuery query);

    /**
     * 查询指定组织结构树
     * @param query 查询条件
     * @return 查询结果
     */
    PageVO<OrganizationTreeVO> listOrganizationTree(OrganizationTreeQuery query);

}
