package com.zeroone.star.systemmanagement.service.addressbook.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.query.systemmanagement.addressbook.AddressbookQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.addressbook.AddressbookVO;
import com.zeroone.star.systemmanagement.entity.addressbook.SysUser;
import com.zeroone.star.systemmanagement.mapper.addressbook.SysUserMapper;
import com.zeroone.star.systemmanagement.service.addressbook.ISysUserService;
import org.apache.logging.log4j.util.Strings;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 * <p>
 * 描述：用户业务层实现类
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 西柚珍珠蜜
 * @version 1.0.0
 */
@Service
public class SysUserServiceImpl extends ServiceImpl<SysUserMapper, SysUser> implements ISysUserService {


    @Override
    public PageVO<AddressbookVO> listAddressbook(AddressbookQuery query) {
        // 构建分页对象
        Page<SysUser> addressBookPage = new Page<>(query.getPageIndex(), query.getPageSize());
        // 构建查询条件
        QueryWrapper<SysUser> addressBookQueryWrapper = new QueryWrapper<>();
        // 执行分页查询
        Page<SysUser> result = baseMapper.selectPage(addressBookPage, addressBookQueryWrapper);
        return PageVO.create(result, AddressbookVO.class);
    }


    @Override
    public PageVO<AddressbookVO> getByRealnameAndWorkNo(AddressbookQuery query, String realname, String workNo) {
        // 构建分页对象
        Page<SysUser> addressBookPage = new Page<>(query.getPageIndex(), query.getPageSize());
        // 构建查询条件
        QueryWrapper<SysUser> addressBookQueryWrapper = new QueryWrapper<>();
        if (realname != null){
            addressBookQueryWrapper.eq(Strings.isNotEmpty(realname),"realname",realname);
        }
        if (workNo != null){
            addressBookQueryWrapper.eq(Strings.isNotEmpty(workNo),"work_no",workNo);
        }
        // 执行分页查询
        Page<SysUser> result = baseMapper.selectPage(addressBookPage, addressBookQueryWrapper);
        return PageVO.create(result, AddressbookVO.class);
    }

}
