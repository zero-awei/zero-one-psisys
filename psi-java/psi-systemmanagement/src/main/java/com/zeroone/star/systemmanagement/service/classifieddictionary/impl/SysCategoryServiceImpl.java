package com.zeroone.star.systemmanagement.service.classifieddictionary.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
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
import java.util.List;

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

    @Resource
    private UserHolder holder;

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
        //获取操作者的信息
        try{
            UserDTO userDTO = holder.getCurrentUser();
            sysCategory.setUpdateBy(userDTO.getUsername());
        }catch (Exception e){
            return e.getMessage();
        }
        //设置更新时间
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
        List<SysCategory> list = mapper.selectList(queryWrapper);
        int records = list.size();
        //实现sql，查询出所有子节点并按照创建时间降序获取top1
        //根据父节点查子节点的数量为0
        if(records == 0){
            sysCategory.setCode("A01");
            sysCategory.setHasChild("0");
        }
        //根据父节点查子节点的数量不为0
        sysCategory.setHasChild("1");
        List<SysCategory> listLastNode =mapper.selectNodeOrderByCreateTime(data.getPid());
        String code = makeCode(listLastNode);
        if(data.getPid().equals("0")){
            sysCategory.setCode(code);
        }
        sysCategory.setCode(data.getPid()+code);
        //更新操作时间
        sysCategory.setCreateTime(now);
        sysCategory.setUpdateTime(now);
        //set操作人和更新人
        try{
           UserDTO userDTO = holder.getCurrentUser();
           sysCategory.setCreateBy(userDTO.getUsername());
           sysCategory.setUpdateBy(userDTO.getUsername());
        }catch (Exception e){
            return e.getMessage();
        }
        int result = mapper.insert(sysCategory);
        System.out.println("test4");
        if(result != 0){
            return "添加成功";
        }
        return "添加失败";
    }


    /**
     * 根据最后一个创建的同级节点的code字段进行编码
     * @param  list 同级节点集合
     * @return code节点同级编码
     */
    public String makeCode(List<SysCategory> list){
        int recodes = list.size();
        String result = null;
        SysCategory sysCategory = list.get(0);
        char[] chars = sysCategory.getCode().toCharArray();
        if(recodes%10 == 9){
            chars[chars.length-1] = 0;
            chars[chars.length-2] = ++chars[chars.length-2];
            result = String.valueOf(chars);
            return result;
        }{
            chars[chars.length-1] = ++chars[chars.length-1];
            result = String.valueOf(chars);
        }
        return result;
    }
}



