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
 * @since 2023-02-14
 */
public interface IFinPayableService extends IService<FinPayable> {

    public PageVO<PayableVO> getAll(PayableQuery query);

    public PayableVO getById(@Validated PayableBillNoQuery query);
}
