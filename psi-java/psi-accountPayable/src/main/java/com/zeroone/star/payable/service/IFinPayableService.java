package com.zeroone.star.payable.service;

import com.zeroone.star.payable.entity.FinPayable;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.query.payable.FinPayableQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.accountPayable.otherPayable.OtherPayableVO;

/**
 * <p>
 * 应付单 服务类
 * </p>
 *
 * @author j3
 * @since 2023-02-14
 */
public interface IFinPayableService extends IService<FinPayable> {

    /**
     * 分页查询
     * @param query 查询条件
     * @return 查询结果
     */
    PageVO<OtherPayableVO> listAll(FinPayableQuery query);

    /**
     * 根据单据编号查询
     * @param billNo 单据编号
     * @return 查询结果
     */
    OtherPayableVO getByBillNo(String billNo);

}
