package com.zeroone.star.payable.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import entity.FinPayableCheckEntry;
import com.zeroone.star.payable.service.FinPayableCheckEntryService;
import com.zeroone.star.payable.mapper.FinPayableCheckEntryMapper;
import org.springframework.stereotype.Service;

/**
* @author iceberg-work
* @description 针对表【fin_payable_check_entry(应付核销明细)】的数据库操作Service实现
* @createDate 2023-02-12 22:06:48
*/
@Service
public class FinPayableCheckEntryServiceImpl extends ServiceImpl<FinPayableCheckEntryMapper, FinPayableCheckEntry>
    implements FinPayableCheckEntryService{

}




