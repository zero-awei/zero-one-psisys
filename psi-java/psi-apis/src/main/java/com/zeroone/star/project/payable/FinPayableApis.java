package com.zeroone.star.project.payable;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.payable.FinPayableDTO;
import com.zeroone.star.project.query.patable.PayableQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.payable.FinPayableVO;

/**
 * <p>
 * 应付单 服务类
 * </p>
 *
 * @author chosen1
 * @since 2023-02-13
 */
public interface FinPayableApis {
    /**
     * 分页查询
     * @param payableDTO 查询条件
     * @return 查询结果
     */
    JsonVO<Page<FinPayableVO>> listAll(FinPayableDTO payableDTO);

    /**
     * 根据ID查询
     * @param query 编号
     * @return 查询结果
     */
    JsonVO<FinPayableVO> getById(PayableQuery query);
}
