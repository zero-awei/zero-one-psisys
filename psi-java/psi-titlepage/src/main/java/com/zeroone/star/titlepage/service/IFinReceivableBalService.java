package com.zeroone.star.titlepage.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.vo.homepage.SystemRevenueAndExpenditureInformationVO;
import com.zeroone.star.titlepage.entity.FinReceivableBal;

/**
 * <p>
 * VIEW 服务类
 * </p>
 *
 * @author yx
 * @since 2023-02-11
 */
public interface IFinReceivableBalService extends IService<FinReceivableBal> {

    /**
     * 获取客户欠款(元)的视图对象
     * @return 客户欠款(元)视图对象
     */
    public SystemRevenueAndExpenditureInformationVO getCustomerDebtVO();
}
