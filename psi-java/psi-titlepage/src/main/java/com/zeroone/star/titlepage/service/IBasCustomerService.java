package com.zeroone.star.titlepage.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.vo.homepage.CustomerInformationVO;
import com.zeroone.star.titlepage.entity.BasCustomer;

/**
 * <p>
 * 客户 服务类
 * </p>
 *
 * @author yx
 * @since 2023-02-11
 */
public interface IBasCustomerService extends IService<BasCustomer> {

    /**
     * 查询今日的客户数量
     * @return 客今日的户数量视图对象
     */
    public CustomerInformationVO countCustomerOnTheDay();

    /**
     * 查询本周的客户数量
     * @return 本周的客户数量视图对象
     */
    public CustomerInformationVO countCustomerOfTheWeek();

    /**
     * 查询本月的客户数量
     * @return 本月的客户数量视图对象
     */
    public CustomerInformationVO countCustomerOnTheMonth();

    /**
     * 查询总客户数量
     * @return 总客户数量视图对象
     */
    public CustomerInformationVO countTotalCustomer();
}
