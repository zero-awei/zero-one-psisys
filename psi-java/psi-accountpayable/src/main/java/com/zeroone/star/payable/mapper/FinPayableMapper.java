package com.zeroone.star.payable.mapper;

import entity.FinPayable;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;

/**
* @author iceberg-work
* @description 针对表【fin_payable(应付单)】的数据库操作Mapper
* @createDate 2023-02-12 22:06:32
* @Entity entity.FinPayable
*/
@Mapper
public interface FinPayableMapper extends BaseMapper<FinPayable> {

}




