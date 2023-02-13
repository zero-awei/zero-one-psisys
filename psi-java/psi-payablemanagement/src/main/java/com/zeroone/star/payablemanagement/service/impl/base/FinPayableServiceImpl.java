package com.zeroone.star.payablemanagement.service.impl.base;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.payablemanagement.service.base.FinPayableService;
import entity.FinPayable;
import com.zeroone.star.payablemanagement.mapper.base.FinPayableMapper;
import org.springframework.stereotype.Service;

/**
* @author iceberg-work
* @description 针对表【fin_payable(应付单)】的数据库操作Service实现
* @createDate 2023-02-12 22:06:32
*/
@Service
public class FinPayableServiceImpl extends ServiceImpl<FinPayableMapper, FinPayable>
    implements FinPayableService {

}




