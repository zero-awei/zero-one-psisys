package com.zeroone.star.payable.mapper;

import entity.FinPayableCheck;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;

/**
* @author iceberg-work
* @description 针对表【fin_payable_check(应付核销单)】的数据库操作Mapper
* @createDate 2023-02-12 22:06:42
* @Entity entity.FinPayableCheck
*/
@Mapper
public interface FinPayableCheckMapper extends BaseMapper<FinPayableCheck> {

}




