package com.zeroone.star.titlepage.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.homepage.HomeDoingBillVO;
import com.zeroone.star.project.vo.homepage.SalOrderVO;
import com.zeroone.star.project.vo.homepage.SalesAmountInformationVO;
import com.zeroone.star.titlepage.entity.SalOrder;

import java.util.List;

/**
 * <p>
 * 销售订单 服务类
 * </p>
 *
 * @author ss
 * @since 2023-02-12
 */
public interface ISalOrderService extends IService<SalOrder> {
    /**
     * 查询毛利润
     */
    public List<SalOrderVO> listSalOrder();

    /**
     * 获取每月销售金额
     * @return 每月销售金额构成的list
     */
    public List<SalesAmountInformationVO> listSalesAmount();

}
