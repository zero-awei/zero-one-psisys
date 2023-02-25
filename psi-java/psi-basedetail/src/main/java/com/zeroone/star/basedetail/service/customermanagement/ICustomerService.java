package com.zeroone.star.basedetail.service.customermanagement;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.basedetail.entity.customermanagement.Customer;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.query.basedetail.customermanagement.CustomerQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.basedetail.customermanagement.CustomerShowVO;
import com.zeroone.star.project.vo.basedetail.customermanagement.CustomerVO;


/**
 * <p>
 * 客户 服务类
 * </p>
 *
 * @author yizhiyang
 * @since 2023-02-13
 */
public interface ICustomerService extends IService<Customer> {
        /**
         * 根据ID查询
         * @param id 编号
         * @return 查询结果
         */
        CustomerShowVO getById(String id);
        /**
         * 根据条件进行分页查询
         * @param customerQuery 查询条件
         * @return PageVO<CustomerVO> 查询的分页对象
         */
        PageVO<CustomerShowVO> getByCondition(CustomerQuery customerQuery);

}


