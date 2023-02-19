package com.zeroone.star.payable.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.payable.entity.FinPayable;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.query.patable.purchase.MultiConditionPayableQuery;
import com.zeroone.star.project.query.patable.purchase.PayableQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payable.purchase.FinPayableVO;
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

    public PageVO<FinPayableVO> getAll(MultiConditionPayableQuery query);

    public FinPayableVO getById(@Validated PayableQuery query);
}
