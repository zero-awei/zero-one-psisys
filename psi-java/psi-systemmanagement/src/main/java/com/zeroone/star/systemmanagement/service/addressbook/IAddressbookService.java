package com.zeroone.star.systemmanagement.service.addressbook;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.query.systemmanagement.addressbook.AddressbookQuery;
import com.zeroone.star.project.query.systemmanagement.addressbook.OrganizationQuery;
import com.zeroone.star.project.query.systemmanagement.addressbook.OrganizationTreeQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.addressbook.AddressbookVO;
import com.zeroone.star.systemmanagement.entity.addressbook.Addressbook;
/**
 * <p>
 * 描述：通讯录业务层接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 西柚珍珠蜜
 * @version 1.0.0
 */
public interface IAddressbookService extends IService<Addressbook> {

    /**
     * 查询通讯录列表
     * @param query 查询条件
     * @return 查询结果
     */
    PageVO<AddressbookVO> listAddressbook(AddressbookQuery query);


    /**
     * 根据姓名和工号查询通讯录列表
     * @param query 查询条件
     * @return
     */
    PageVO<AddressbookVO> getByRealnameAndWorkNo(AddressbookQuery query);


    /**
     * 根据姓名查询通讯录列表
     * @param query 查询条件
     * @return
     */
    PageVO<AddressbookVO> getByRealname(AddressbookQuery query);


    /**
     * 根据工号查询通讯录列表
     * @param query 查询条件
     * @return
     */
    PageVO<AddressbookVO> getByWorkNo(AddressbookQuery query);


    /**
     * 根据部门名称查询组织结构
     * @param query 查询条件
     * @return
     */
    PageVO<AddressbookVO> getByDepartName(OrganizationTreeQuery query);

    /**
     * 查询所有组织结构
     * @param query
     * @return
     */
    PageVO<AddressbookVO> listDepart(OrganizationQuery query);

}
