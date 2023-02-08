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
import com.zeroone.star.sample.service.SeataService;
import io.seata.spring.annotation.GlobalTransactional;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

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

    @Resource
    SeataService seata;

    @Override
    @GlobalTransactional
    public int testSeata() {
        // 先保存本地数据
        Sample sample = new Sample();
        sample.setAge(19);
        sample.setName("消炎");
        sample.setSex("女");
        int row = baseMapper.insert(sample);
        if (row != 1){
            throw new RuntimeException("本地数据保存失败");
        }
        // 在调用其他微服务
        Integer res = seata.testSave();
        if (res == null || res != 1){
            throw new RuntimeException("微服务数据保存失败");
        }
        return 1;
    }
}
