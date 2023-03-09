package com.zeroone.star.systemmanagement.service.addressbook;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.query.systemmanagement.addressbook.AddressbookQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.addressbook.AddressbookVO;
import com.zeroone.star.systemmanagement.entity.addressbook.SysUser;

/**
 * <p>
 * 描述：用户业务层接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 西柚珍珠蜜
 * @version 1.0.0
 */
public interface ISysUserService extends IService<SysUser> {

    /**
     * 查询通讯录列表
     * @param query 查询条件
     * @return 查询结果
     */
    PageVO<AddressbookVO> listAddressbook(AddressbookQuery query);


    /**
     * 根据姓名和工号查询通讯录列表
     * @param realname
     * @param workNo
     * @return
     */
    PageVO<AddressbookVO> getByRealnameAndWorkNo(AddressbookQuery query,String realname,String workNo);

}
