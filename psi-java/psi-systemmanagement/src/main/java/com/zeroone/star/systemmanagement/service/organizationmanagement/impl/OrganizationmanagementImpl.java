package com.zeroone.star.systemmanagement.service.organizationmanagement.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.systemmanagement.organizationmanagement.OrganizationManagementDTO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.query.systemmanagement.organizationmanagement.OrganizationListQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.organizationmanagement.OrganizationListVO;
import com.zeroone.star.project.vo.systemmanagement.organizationmanagement.OrganizationTreeVO;
import com.zeroone.star.systemmanagement.entity.organizationmanagement.SysDepart;
import com.zeroone.star.systemmanagement.mapper.organizationmanagement.OrganizationmanagementMapper;
import com.zeroone.star.systemmanagement.service.organizationmanagement.OrganizationmanagementService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.List;

/**
 * <p>
 * 组织机构表 服务实现类
 * </p>
 *
 * @author Morrangee
 * @since 2023-02-13
 */
@Service
public class OrganizationmanagementImpl extends ServiceImpl<OrganizationmanagementMapper, SysDepart> implements OrganizationmanagementService {
    @Resource
    private OrganizationmanagementMapper mapper;
    @Resource
    private UserHolder holder;

    @Override
    public PageVO<OrganizationListVO> queryList(PageQuery pageQuery) {
        // 从第一页开始，每一页查6条数据
        Page<SysDepart> page = new Page<>(pageQuery.getPageIndex(),pageQuery.getPageSize());
        QueryWrapper<SysDepart> wrapper = new QueryWrapper<>();
        Page<SysDepart> p = mapper.selectPage(page, wrapper);
        return PageVO.create(p, OrganizationListVO.class);
    }

    @Override
    public List<OrganizationTreeVO> queryTree(String departName) {
        List<OrganizationTreeVO> treeVOS = new ArrayList<>();
        HashMap<String, Object> map = new HashMap<>();
        map.put("depart_name", departName);
        List<SysDepart> sysDeparts = mapper.selectByMap(map);
        for (SysDepart depart : sysDeparts) {
            String parentId = depart.getParentId();
            OrganizationTreeVO treeVO = new OrganizationTreeVO();
            treeVO.setParentId(parentId);
            treeVO.setDepartName(departName);
            treeVOS.add(treeVO);
        }
        return treeVOS;
    }

    @Override
    public String add(OrganizationManagementDTO data) {
        SysDepart sysDepart = new SysDepart();
        BeanUtil.copyProperties(data, sysDepart);
        try {
            UserDTO userDTO = holder.getCurrentUser();
            sysDepart.setUpdateBy(userDTO.getUsername());
        } catch (Exception e) {
            return e.getMessage();
        }
        int result = mapper.insert(sysDepart);
        if (result == 0) {
            return "新增失败";
        }
        return "新增成功";
    }

    @Override
    public String modify(OrganizationManagementDTO data) {
        SysDepart sysDepart = new SysDepart();
        BeanUtil.copyProperties(data, sysDepart);
        try {
            UserDTO userDTO = holder.getCurrentUser();
            sysDepart.setUpdateBy(userDTO.getUsername());
        } catch (Exception e) {
            return e.getMessage();
        }
        int result = mapper.updateById(sysDepart);
        if (result == 0) {
            return "更新失败";
        }
        return "更新成功";
    }

    @Override
    public String remove(String id) {
        int result = mapper.deleteById(id);
        if (result == 0) {
            return "删除失败";
        }
        return "删除成功";
    }
}
