package com.zeroone.star.sample.service;

import com.zeroone.star.project.query.sample.SampleQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.sample.SampleVO;
import com.zeroone.star.sample.entity.Sample;
import com.baomidou.mybatisplus.extension.service.IService;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author awei
 * @since 2023-02-04
 */
public interface ISampleService extends IService<Sample> {
    /**
     * 分页查询
     * @param query 查询条件
     * @return 查询结果
     */
    PageVO<SampleVO> listAll(SampleQuery query);

    /**
     * 根据ID查询
     * @param id 编号
     * @return 查询结果
     */
    SampleVO getById(int id);

    int testSeata();
}
