package com.zeroone.star.systemmanagement.mapper.addressbook;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.query.systemmanagement.addressbook.AddressbookQuery;
import com.zeroone.star.systemmanagement.entity.addressbook.Addressbook;
import org.mapstruct.Mapper;

import java.sql.Wrapper;
/**
 * <p>
 * 描述：自建 通讯录 Mapper 接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 西柚珍珠蜜
 * @version 1.0.0
 */
@Mapper
public interface AddressbookMapper extends BaseMapper<Addressbook> {

    public Page<Addressbook> listAddressbook(Page page, AddressbookQuery condition);

    public Page<Addressbook> getByRealnameAndWorkNo(Page page,AddressbookQuery condition);

    public Page<Addressbook> getByRealname(Page page,AddressbookQuery condition);

    public Page<Addressbook> getByWorkNo(Page page,AddressbookQuery condition);

}
