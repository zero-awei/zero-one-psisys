package com.zeroone.star.payablemanagement.service;

import com.zeroone.star.payablemanagement.entity.FinPayableCheck;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.query.payablemanagement.CheckPayableQuery;
import com.zeroone.star.project.query.payablemanagement.PayableBySupplierQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payablemanagement.CheckPayableVO;
import com.zeroone.star.project.vo.payablemanagement.PayableVO;

/**
 * <p>
 * 应付核销单 服务类
 * </p>
 *
 * @author j3
 * @since 2023-02-14
 */
public interface IFinPayableCheckService extends IService<FinPayableCheck> {

    /**
     * 查询单据列表
     * @param condition 查询条件
     * @return 查询结果
     * @author spk
     */
    public PageVO<CheckPayableVO> queryAll(CheckPayableQuery condition);

}
