package com.zeroone.star.role.service;

import com.zeroone.star.project.query.sample.SampleQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.sample.SampleVO;
import com.zeroone.star.role.entity.Sample;
import com.baomidou.mybatisplus.extension.service.IService;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author ali
 * @since 2023-02-12
 */
public interface ISampleService extends IService<Sample> {
    PageVO<SampleVO> listAll(SampleQuery query) ; // 分页查询
    SampleVO getById(int id); // 根据id查询
}
