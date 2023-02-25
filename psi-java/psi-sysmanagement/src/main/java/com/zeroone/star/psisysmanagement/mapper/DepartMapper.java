package com.zeroone.star.psisysmanagement.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.psisysmanagement.entity.Depart;
import org.apache.ibatis.annotations.Mapper;

/**
* @author dan
* @description 针对表【sys_depart(组织机构表)】的数据库操作Mapper
* @createDate 2023-02-22 22:18:42
* @Entity com.zeroone.star.psisysmanagement.entity.Depart
*/
@Mapper
public interface DepartMapper extends BaseMapper<Depart> {


}
