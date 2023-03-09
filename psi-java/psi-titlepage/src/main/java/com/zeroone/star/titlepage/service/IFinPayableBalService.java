package com.zeroone.star.titlepage.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.vo.homepage.SystemRevenueAndExpenditureInformationVO;
import com.zeroone.star.titlepage.entity.FinPayableBal;

/**
 * <p>
 * VIEW 服务类
 * </p>
 *
 * @author yx
 * @since 2023-02-11
 */
public interface IFinPayableBalService extends IService<FinPayableBal> {

    /**
     * 获取欠供应商(元)的视图对象
     * @return 欠供应商(元)的视图对象
     */
    public SystemRevenueAndExpenditureInformationVO getMyDebtVO();
}
