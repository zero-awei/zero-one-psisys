package com.zeroone.star.payable.service;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.payable.entity.FinPayable;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.payable.FinPayableDTO;
import com.zeroone.star.project.query.sample.SampleQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payable.FinPayableVO;
import com.zeroone.star.project.vo.sample.SampleVO;

/**
 * <p>
 * 应付单 服务类
 * </p>
 *
 * @author chosen1
 * @since 2023-02-13
 */
public interface IFinPayableService extends IService<FinPayable> {
    /**
     * 分页查询
     * @param payableDTO 查询条件
     * @return 查询结果
     */
    JsonVO<Page<FinPayableVO>> listAll(FinPayableDTO payableDTO);

    /**
     * 根据ID查询
     * @param id 编号
     * @return 查询结果
     */
    JsonVO<FinPayableVO> getById(String id);
}
