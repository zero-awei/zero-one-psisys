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
import java.util.Date;
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

    /**
     * 查询所有父结点
     * @param condition
     * @return
     */
    @Override
    public PageVO<ClassifiedDictionaryVO> listAll(PageQuery condition) {
        Page<SysCategory> page = new Page<>(condition.getPageIndex(),condition.getPageSize());
        LambdaQueryWrapper<SysCategory> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq(SysCategory::getPid,"0");
        Page<SysCategory> result = mapper.selectPage(page,wrapper);
        return PageVO.create(result,ClassifiedDictionaryVO.class);
    }

    /**
     * 查询对应子节点
     * @param condition
     * @return
     */
    @Override
    public PageVO<ClassifiedDictionaryVO> listChildren(String condition) {
        Page<SysCategory> page = new Page<>(1,10);
        LambdaQueryWrapper<SysCategory> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq(SysCategory::getPid,condition);
        Page<SysCategory> result = mapper.selectPage(page,wrapper);
        return PageVO.create(result,ClassifiedDictionaryVO.class);
    }

    /**
     * 更新对应的子节点
     * @param data
     * @return
     */
    @Override
    public String update(ClassifiedDictionaryUpdateDTO data) {
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
        /*sysCategory.setUpdateTime(now);*/
        int result = mapper.updateById(sysCategory);
        if(result == 0){
            return "更新失败";
        }
        return "更新成功";
    }

    /**
     * 删除对应的结点
     * @param id
     * @return
     */
    @Override
    public String remove(String id) {
        int result = mapper.deleteById(id);
        if(result == 1){
            return "删除成功";
        }
        return "删除失败";
    }

    /**
     * 插入节点
     * @param data
     * @return
     */
    @Override
    public String save(ClassifiedDictionarySaveDTO data) {
        // 查询待插入数据是否已存在
        LambdaQueryWrapper<SysCategory> wrapper = new LambdaQueryWrapper<>();
        wrapper.eq(SysCategory::getName,data.getName()).eq(SysCategory::getPid,data.getPid());
        List<SysCategory> sysCategories = mapper.selectList(wrapper);
        if(sysCategories.size() != 0){
            return "数据已存在";
        }else {
            SysCategory sysCategory = new SysCategory();
            // 对象属性匹配
            BeanUtil.copyProperties(data,sysCategory);
            // 获取并排序同级结点
            List<SysCategory> list = mapper.selectNodeOrderByCreateTime(data.getPid());
            int size = list.size();
            // 判断pid==0并判断一级结点的数量是否为0
            if(data.getPid().equals("0") && size == 0){
                sysCategory.setCode("A01");
            }else if(size == 0){        // 判断子节点的数量是否为0
                LambdaQueryWrapper<SysCategory> queryWrapper = new LambdaQueryWrapper<>();
                queryWrapper.eq(SysCategory::getId,data.getPid());
                SysCategory parentCategory = mapper.selectOne(queryWrapper);
                sysCategory.setCode(parentCategory.getCode()+"A01");
                // 更新父节点HasChild字段
                parentCategory.setHasChild("1");
                makeOperator(parentCategory);
                mapper.updateById(parentCategory);
            }else {
                String code = makeCode(list);
                sysCategory.setCode(code);
            }
            sysCategory.setHasChild("0");
            // set操作人和更新人
            String resultOperator = makeOperator(sysCategory);
            int result = mapper.insert(sysCategory);
            if(result != 0 && resultOperator.equals("1")){
                return "添加成功";
            }
            return "添加失败";
        }
    }


    /**
     * 根据最后一个创建的同级节点的code字段进行编码
     * @param  list 同级节点集合
     * @return code节点同级编码
     */
    public String makeCode(List<SysCategory> list){
        // 获取已经根据创建时间排序好的list的数量
        int recodes = list.size();
        // 创建拼接好code的变量
        String result = "";
        // 获取最后一个创建的同阶结点
        SysCategory sysCategory = list.get(0);
        // 将该节点的编码字段变成一个字符数组
        char[] chars = sysCategory.getCode().toCharArray();
        // 判断同级结点的数量是否超过到9这个临界点
        if(recodes%10 == 9){
            // 如果到9这个临界点则倒数第二个字符+1，最后一个字符为0
            chars[chars.length-1] = 0;
            chars[chars.length-2] = ++chars[chars.length-2];
            // 将设置好的字符数组转换为字符串
            result = String.valueOf(chars);
            return result;
        }else {
            // 如果没有到9这个临界点数组的最后一个字符自增
            chars[chars.length-1] = ++chars[chars.length-1];
            result = String.valueOf(chars);
            return result;
        }
    }

    /**
     * 更新操作人信息
     * @param sysCategory
     * @return
     */
  public String makeOperator(SysCategory sysCategory){
      try{
          UserDTO userDTO = holder.getCurrentUser();
          sysCategory.setCreateBy(userDTO.getUsername());
          sysCategory.setUpdateBy(userDTO.getUsername());
      }catch (Exception e){
          return e.getMessage();
      }
      return "1";
  }
}



