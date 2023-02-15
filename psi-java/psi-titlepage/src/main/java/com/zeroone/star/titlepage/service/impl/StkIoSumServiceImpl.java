package com.zeroone.star.titlepage.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.vo.homepage.StkIoSumVO;
import com.zeroone.star.titlepage.entity.StkIoSum;
import com.zeroone.star.titlepage.mapper.StkIoSumMapper;
import com.zeroone.star.titlepage.service.IStkIoSumService;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 出入库汇总 服务实现类
 * </p>
 *
 * @author ss
 * @since 2023-02-12
 */
@Service
public class StkIoSumServiceImpl extends ServiceImpl<StkIoSumMapper, StkIoSum> implements IStkIoSumService {

    @Override
    public List<StkIoSumVO> queryStkIoSum() {
        List<StkIoSum> list = baseMapper.queryStkIoSum();
        List<StkIoSumVO> list1=new ArrayList<>();
        for (StkIoSum stkIoSum : list) {
            StkIoSumVO stkIoSumVO = new StkIoSumVO();
            BeanUtil.copyProperties(stkIoSum,stkIoSumVO);
            list1.add(stkIoSumVO);
        }
        return list1;

    }
}
