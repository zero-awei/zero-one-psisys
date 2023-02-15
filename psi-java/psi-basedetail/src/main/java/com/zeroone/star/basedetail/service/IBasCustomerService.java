package com.zeroone.star.basedetail.service;

import com.zeroone.star.basedetail.entity.BasCustomer;
import com.baomidou.mybatisplus.extension.service.IService;

import java.util.List;

/**
 * <p>
 * 客户 服务类
 * </p>
 *
 * @author ss
 * @since 2023-02-15
 */
public interface IBasCustomerService extends IService<BasCustomer> {

    /**
    查询客户excel需要的字段
     */
    List<BasCustomer> listBasCustomer();

}
