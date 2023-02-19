package com.zeroone.star.systemmanagement.service.classifieddictionary.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.systemmanagement.classifieddictionary.ClassifiedDictionarySaveDTO;
import com.zeroone.star.project.dto.systemmanagement.classifieddictionary.ClassifiedDictionaryUpdateDTO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.classifieddictionary.ClassifiedDictionaryVO;
import com.zeroone.star.systemmanagement.entity.classifieddictionary.SysCategory;
import com.zeroone.star.systemmanagement.mapper.classifieddictionary.SysCategoryMapper;
import com.zeroone.star.systemmanagement.service.classifieddictionary.ISysCategoryService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.time.LocalDateTime;

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
    public PageVO<ClassifiedDictionaryVO> listAll(PageQuery condition) {
        Page<SysCategory> page = new Page<>(condition.getPageIndex(),condition.getPageSize());
        QueryWrapper<SysCategory> wrapper = new QueryWrapper<>();
        Page<SysCategory> result = mapper.selectPage(page,wrapper);
        return PageVO.create(result,ClassifiedDictionaryVO.class);
    }

    @Override
    public PageVO<ClassifiedDictionaryVO> listChildren(String condition) {
        Page<SysCategory> page = new Page<>(1,10);
        LambdaQueryWrapper<SysCategory> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq(SysCategory::getPid,condition);
        Page<SysCategory> result = mapper.selectPage(page,wrapper);
        return PageVO.create(result,ClassifiedDictionaryVO.class);
    }

    @Override
    public String update(ClassifiedDictionaryUpdateDTO data) {
        LocalDateTime now = LocalDateTime.now();
        if(data.getId() == null){
            return "更新失败";
        }
        SysCategory sysCategory = new SysCategory();
        BeanUtil.copyProperties(data,sysCategory);
        sysCategory.setUpdateTime(now);
        int result = mapper.updateById(sysCategory);
        if(result == 0){
            return "更新失败";
        }
        return "更新成功";
    }

    @Override
    public String remove(String id) {
        int result = mapper.deleteById(id);
        if(result == 1){
            return "删除成功";
        }
        return "删除失败";
    }

    @Override
    public String save(ClassifiedDictionarySaveDTO data) {
        //查询待插入数据是否已存在
        LambdaQueryWrapper<SysCategory> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq(SysCategory::getName,data.getName()).eq(SysCategory::getPid,data.getPid());
        SysCategory selectOne = mapper.selectOne(wrapper);
        if(selectOne != null){
            return "数据已存在";
        }
        //创建date对象获取当前时间
        LocalDateTime now = LocalDateTime.now();
        SysCategory sysCategory = new SysCategory();
        //对象属性匹配
        BeanUtil.copyProperties(data,sysCategory);
        //判断是否有子节点
        LambdaQueryWrapper<SysCategory> queryWrapper = new LambdaQueryWrapper<>();
        queryWrapper.eq(SysCategory::getPid,data.getPid());
        int records = mapper.selectList(queryWrapper).size();
        if(records == 0){
            sysCategory.setHasChild("0");
            //判断父节点的数量
            LambdaQueryWrapper<SysCategory> wrapperParent = new LambdaQueryWrapper<>();
            int numberP= mapper.selectList(wrapperParent).size();
            sysCategory.setCode(makeCode(numberP));
        }else {
            //根据pid（父节点id）获取子节点的数量
            int numberC = mapper.selectList(new LambdaQueryWrapper<SysCategory>()
                    .eq(SysCategory::getPid,data.getPid())).size();
            sysCategory.setCode(data.getPid()+makeCode(numberC));
        }
        sysCategory.setHasChild("1");
        //更新操作时间
        sysCategory.setCreateTime(now);
        sysCategory.setUpdateTime(now);
        //set操作人和更新人
        int result = mapper.insert(sysCategory);
        if(result != 0){
            return "添加成功";
        }
        return "添加失败";
    }


    /**
     * 根据同级节点的数量进行编码
     * @param recodes 同级节点数量
     * @return code节点同级编码
     */
    public String makeCode(int recodes){
        if(recodes == 0){
            return null;
        }
        int a = recodes%10;
        int b = recodes/10;
        return "A"+String.valueOf(a)+String.valueOf(b);
    }
}



