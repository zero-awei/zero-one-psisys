package com.zeroone.star.systemmanagement.mapper.classifieddictionary;

import com.zeroone.star.systemmanagement.entity.classifieddictionary.SysCategory;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author suqier
 * @since 2023-02-11
 */
@Mapper
public interface SysCategoryMapper extends BaseMapper<SysCategory> {

    /**
     * 查询最后创建的节点，获取其code字段
     * @return
     */
    List<SysCategory> selectNodeOrderByCreateTime(String pid);

}
