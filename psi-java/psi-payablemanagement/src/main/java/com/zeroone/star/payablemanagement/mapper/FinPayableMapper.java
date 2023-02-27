package com.zeroone.star.payablemanagement.mapper;

import com.zeroone.star.payablemanagement.entity.FinPayable;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.query.payablemanagement.PayableBySupplierQuery;
import com.zeroone.star.project.vo.payablemanagement.PayableVO;
import com.zeroone.star.project.query.payablemanagement.PayableQuery;
import com.zeroone.star.project.vo.payablemanagement.PayableVO;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 * 应付单 Mapper 接口
 * </p>
 *
 * @author chosen1, G.
 * @since 2023-02-14
 */
@Mapper
public interface FinPayableMapper extends BaseMapper<FinPayable>{
    List<PayableVO> queryPayable(PayableQuery query);

    List<PayableVO> getBySupplierId(PayableBySupplierQuery condition);
    PayableVO getOneByBillNo(String billNo);
}
