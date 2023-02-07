package com.zeroone.star.sample.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.query.sample.SampleQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.sample.SampleVO;
import com.zeroone.star.sample.entity.Sample;
import com.zeroone.star.sample.mapper.SampleMapper;
import com.zeroone.star.sample.service.ISampleService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 服务实现类
 * </p>
 * @author awei
 * @since 2023-02-04
 */
@Service
public class SampleServiceImpl extends ServiceImpl<SampleMapper, Sample> implements ISampleService {

    @Override
    public PageVO<SampleVO> listAll(SampleQuery query) {
        // 构建分页对象
        Page<Sample> samplePage = new Page<>(query.getPageIndex(), query.getPageSize());
        // 构建查询条件
        QueryWrapper<Sample> sampleQueryWrapper = new QueryWrapper<>();
        sampleQueryWrapper.like("name", query.getName());
        // 执行分页查询
        Page<Sample> result = baseMapper.selectPage(samplePage, sampleQueryWrapper);
        return PageVO.create(result, SampleVO.class);
    }

    @Override
    public SampleVO getById(int id) {
        Sample sample = baseMapper.selectById(id);
        if (sample != null) {
            SampleVO sampleVO = new SampleVO();
            BeanUtil.copyProperties(sample, sampleVO);
            return sampleVO;
        }
        return null;
    }
}
