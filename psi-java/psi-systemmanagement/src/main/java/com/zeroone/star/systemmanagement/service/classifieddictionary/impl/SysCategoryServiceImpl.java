package com.zeroone.star.systemmanagement.service.classifieddictionary.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.systemmanagement.classifieddictionary.ClassifiedDictionaryDTO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.classifieddictionary.ClassifiedDictionaryVO;
import com.zeroone.star.systemmanagement.entity.classifieddictionary.SysCategory;
import com.zeroone.star.systemmanagement.mapper.classifieddictionary.SysCategoryMapper;
import com.zeroone.star.systemmanagement.service.classifieddictionary.ISysCategoryService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author suqier
 * @since 2023-02-11
 */
@Service
public class SysCategoryServiceImpl extends ServiceImpl<SysCategoryMapper, SysCategory> implements ISysCategoryService {

    @Resource
    private SysCategoryMapper mapper;
    @Override
    public PageVO<ClassifiedDictionaryVO> queryAll(PageQuery condition) {
        Page<SysCategory> page = new Page<>(condition.getPageIndex(),condition.getPageSize());
        QueryWrapper<SysCategory> wrapper = new QueryWrapper<>();
        Page<SysCategory> result = mapper.selectPage(page,wrapper);
        return PageVO.create(result,ClassifiedDictionaryVO.class);
    }

    @Override
    public PageVO<ClassifiedDictionaryVO> queryOne(String condition) {
        Page<SysCategory> page = new Page<>(1,10);
        LambdaQueryWrapper<SysCategory> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq(SysCategory::getPid,condition);
        Page<SysCategory> result = mapper.selectPage(page,wrapper);
        return PageVO.create(result,ClassifiedDictionaryVO.class);
    }

    @Override
    public String update(ClassifiedDictionaryDTO data) {
        SysCategory sysCategory = new SysCategory();
        BeanUtil.copyProperties(data,sysCategory);
        int result = mapper.updateById(sysCategory);
        if(result == 0){
            return "更新失败";
        }
        return "更新成功";
    }

    @Override
    public String delete(String id) {
        int result = mapper.deleteById(id);
        if(result == 1){
            return "删除成功";
        }
        return "删除失败";
    }

    @Override
    public String insert(ClassifiedDictionaryDTO data) {
        SysCategory sysCategory = new SysCategory();
        BeanUtil.copyProperties(data,sysCategory);
        int result = mapper.insert(sysCategory);
        if(result == 1){
            return "添加成功";
        }
        return "添加失败";
    }
}
