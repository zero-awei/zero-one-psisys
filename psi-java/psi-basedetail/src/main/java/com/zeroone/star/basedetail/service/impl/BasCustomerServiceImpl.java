package com.zeroone.star.basedetail.service.impl;

import com.zeroone.star.basedetail.entity.BasCustomer;
import com.zeroone.star.basedetail.mapper.BasCustomerMapper;
import com.zeroone.star.basedetail.service.IBasCustomerService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * <p>
 * 客户 服务实现类
 * </p>
 *
 * @author ss
 * @since 2023-02-15
 */
@Service
public class BasCustomerServiceImpl extends ServiceImpl<BasCustomerMapper, BasCustomer> implements IBasCustomerService {

    @Override
    public List<BasCustomer> listBasCustomer() {
        List<BasCustomer> list = baseMapper.selectList(null);
        return list;
    }
}
