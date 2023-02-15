package com.zeroone.star.systemmanagement.service.addressbook.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.query.systemmanagement.addressbook.OrganizationQuery;
import com.zeroone.star.project.query.systemmanagement.addressbook.OrganizationTreeQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.addressbook.OrganizationTreeVO;
import com.zeroone.star.project.vo.systemmanagement.addressbook.OrganizationVO;
import com.zeroone.star.systemmanagement.entity.addressbook.SysDepart;
import com.zeroone.star.systemmanagement.mapper.addressbook.SysDepartMapper;
import com.zeroone.star.systemmanagement.service.addressbook.ISysDepartService;
import org.bouncycastle.util.Strings;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 * <p>
 * 描述：组织机构业务层实现类
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 西柚珍珠蜜
 * @version 1.0.0
 */
@Service
public class SysDepartServiceImpl extends ServiceImpl<SysDepartMapper, SysDepart> implements ISysDepartService {

    @Resource
    SysDepartMapper mapper;


    @Override
    public PageVO<OrganizationVO> listOrganization(OrganizationQuery query) {
        // 构建分页对象
        Page<SysDepart> sysDepartPage = new Page<>(query.getPageIndex(), query.getPageSize());
        // 构建查询条件
        QueryWrapper<SysDepart> sysDepartQueryWrapper = new QueryWrapper<>();
        // 执行分页查询
        Page<SysDepart> result = baseMapper.selectPage(sysDepartPage, sysDepartQueryWrapper);
        return PageVO.create(result, OrganizationVO.class);
    }

    @Override
    public PageVO<OrganizationTreeVO> listOrganizationTree(OrganizationTreeQuery query,String departName) {
        // 构建分页对象
        Page<SysDepart> sysDepartPage = new Page<>(query.getPageIndex(), query.getPageSize());
        // 构建查询条件
        QueryWrapper<SysDepart> sysDepartQueryWrapper = new QueryWrapper<>();
        // 执行分页查询
        Page<SysDepart> result = mapper.getOrganizationTreeName(sysDepartPage, sysDepartQueryWrapper, departName);
        return PageVO.create(result, OrganizationTreeVO.class);
    }
}
