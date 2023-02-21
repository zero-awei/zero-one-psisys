package com.zeroone.star.payablemanagement.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.payablemanagement.entity.FinPayable;
import com.zeroone.star.project.query.payablemanagement.PayableQuery;
import com.zeroone.star.project.query.payablemanagement.PayableBillNoQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payablemanagement.PayableVO;
import org.springframework.validation.annotation.Validated;

/**
 * <p>
 * 应付单 服务类
 * </p>
 *
 * @author chosen1
 * @author j3
 * @since 2023-02-14
 */
public interface IFinPayableService extends IService<FinPayable> {

    public PageVO<PayableVO> getAll(PayableQuery query);

    public PayableVO getById(@Validated PayableBillNoQuery query);
    /**
     * 根据条件分页查询
     * @param query 查询条件
     * @return 查询结果
     */
    PageVO<PayableVO> queryAll(PayableQuery query);

    /**
     * 根据单据编号查询
     * @param billNo 单据编号
     * @return 查询结果
     */
    PayableVO getByBillNo(String billNo);

}
