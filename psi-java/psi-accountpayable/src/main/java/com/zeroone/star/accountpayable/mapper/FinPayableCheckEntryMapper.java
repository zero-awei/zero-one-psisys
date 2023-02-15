package com.zeroone.star.accountpayable.mapper;

import entity.FinPayableCheckEntry;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;

/**
* @author iceberg-work
* @description 针对表【fin_payable_check_entry(应付核销明细)】的数据库操作Mapper
* @createDate 2023-02-12 22:06:48
* @Entity entity.FinPayableCheckEntry
*/
@Mapper
public interface FinPayableCheckEntryMapper extends BaseMapper<FinPayableCheckEntry> {

}




