package com.zeroone.star.systemmanagement.mapper.addressbook;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.query.systemmanagement.addressbook.OrganizationQuery;
import com.zeroone.star.project.query.systemmanagement.addressbook.OrganizationTreeQuery;
import com.zeroone.star.systemmanagement.entity.addressbook.SysDepart;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 * 描述：组织机构表 Mapper 接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 西柚珍珠蜜
 * @version 1.0.0
 */
@Mapper
public interface SysDepartMapper extends BaseMapper<SysDepart> {

    public Page<SysDepart> getOrganizationName(Page page, OrganizationQuery condition);

    public Page<SysDepart> getOrganizationTreeName(Page page, OrganizationTreeQuery condition);


}
