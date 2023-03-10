package com.zeroone.star.systemmanagement.service.addressbook.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.query.systemmanagement.addressbook.AddressbookQuery;
import com.zeroone.star.project.query.systemmanagement.addressbook.OrganizationQuery;
import com.zeroone.star.project.query.systemmanagement.addressbook.OrganizationTreeQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.addressbook.AddressbookVO;
import com.zeroone.star.systemmanagement.entity.addressbook.Addressbook;
import com.zeroone.star.systemmanagement.entity.addressbook.SysDepart;
import com.zeroone.star.systemmanagement.mapper.addressbook.AddressbookMapper;
import com.zeroone.star.systemmanagement.mapper.addressbook.SysDepartMapper;
import com.zeroone.star.systemmanagement.service.addressbook.IAddressbookService;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;

/**
 * <p>
 * 描述：通讯录业务层实现类
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 西柚珍珠蜜
 * @version 1.0.0
 */
@Service
@Transactional
public class AddressbookServiceImpl extends ServiceImpl<AddressbookMapper, Addressbook> implements IAddressbookService {

    @Resource
    private AddressbookMapper mapper;
    @Resource
    private SysDepartMapper sysDepartMapper;



    @Override
    public PageVO<AddressbookVO> listAddressbook(AddressbookQuery query) {
        // 构建分页对象
        Page<Addressbook> addressBookPage = new Page<>(query.getPageIndex(), query.getPageSize());
        // 执行查询
        Page<Addressbook> result = mapper.listAddressbook(addressBookPage,query);
        return PageVO.create(result, AddressbookVO.class);
    }

    @Override
    public PageVO<AddressbookVO> getByRealnameAndWorkNo(AddressbookQuery query) {
        // 执行查询
        Page<Addressbook> addressBookPage = new Page<>(query.getPageIndex(), query.getPageSize());
        // 构建查询条件
        Page<Addressbook> result = mapper.getByRealnameAndWorkNo(addressBookPage,query);
        return PageVO.create(result, AddressbookVO.class);
    }

    @Override
    public PageVO<AddressbookVO> getByRealname(AddressbookQuery query) {
        // 执行查询
        Page<Addressbook> addressBookPage = new Page<>(query.getPageIndex(), query.getPageSize());
        // 构建查询条件
        Page<Addressbook> result = mapper.getByRealname(addressBookPage,query);
        return PageVO.create(result, AddressbookVO.class);
    }

    @Override
    public PageVO<AddressbookVO> getByWorkNo(AddressbookQuery query) {
        // 执行查询
        Page<Addressbook> addressBookPage = new Page<>(query.getPageIndex(), query.getPageSize());
        // 构建查询条件
        Page<Addressbook> result = mapper.getByWorkNo(addressBookPage,query);
        return PageVO.create(result, AddressbookVO.class);
    }

    @Override
    public PageVO<AddressbookVO> getByDepartName(OrganizationTreeQuery query) {
        // 构建查询条件
        Page<Addressbook> addressBookPage = new Page<>(query.getPageIndex(), query.getPageSize());
        // 执行查询
        Page<Addressbook> result = mapper.getByDepartName(addressBookPage,query);
        return PageVO.create(result, AddressbookVO.class);
    }

    @Override
    public PageVO<AddressbookVO> listDepart(OrganizationQuery query) {
        Page<Addressbook> addressBookPage = new Page<>(query.getPageIndex(), query.getPageSize());
        LambdaQueryWrapper<SysDepart> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq(SysDepart::getOrgCode,query.getOrgCode());
        String id = sysDepartMapper.selectOne(wrapper).getId();
        // 执行查询
        Page<Addressbook> result = mapper.listDepart(addressBookPage,id);
        return PageVO.create(result, AddressbookVO.class);
    }
}
