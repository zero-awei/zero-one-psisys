package com.zeroone.star.project.systemmanagement.addressbook;

import com.zeroone.star.project.query.systemmanagement.addressbook.AddressbookQuery;
import com.zeroone.star.project.query.systemmanagement.addressbook.OrganizationQuery;
import com.zeroone.star.project.query.systemmanagement.addressbook.OrganizationTreeQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.addressbook.AddressbookVO;
import org.springframework.validation.annotation.Validated;

/**
 * <p>
 * 描述：查询通讯录列表
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 西柚珍珠蜜
 * @version 1.0.0
 */
public interface AddressbookApis {

    /**
     * 查询通讯录列表
     * @param condition 查询条件
     * @return 查询结果
     */
    JsonVO<PageVO<AddressbookVO>> queryAddressbook(AddressbookQuery condition);
    
    /**
     * 根据姓名和工号查询通讯录列表
     *
     * @param condition 查询条件
     * @return 查询结果
     */
    JsonVO<PageVO<AddressbookVO>> getByRealnameAndWorkNo(AddressbookQuery condition);

    /**
     * 根据姓名查询通讯录列表
     *
     * @param condition 查询条件
     * @return 查询结果
     */
    JsonVO<PageVO<AddressbookVO>> getByRealname(AddressbookQuery condition);

    /**
     * 根据工号查询通讯录列表
     *
     * @param condition 查询条件
     * @return 查询结果
     */
    JsonVO<PageVO<AddressbookVO>> getByWorkNo(AddressbookQuery condition);

    /**
     * 根据部门名称查询指定组织树
     * @param condition 查询条件
     * @return
     */
    JsonVO<PageVO<AddressbookVO>> getByDepartName(OrganizationTreeQuery condition);

    /**
     * 查询所有组织树
     * @param condition
     * @return
     */
    JsonVO<PageVO<AddressbookVO>> queryDepart(OrganizationQuery condition);

}
