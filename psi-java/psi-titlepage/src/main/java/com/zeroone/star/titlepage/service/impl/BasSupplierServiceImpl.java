package com.zeroone.star.titlepage.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.vo.homepage.BasSupplierVO;
import com.zeroone.star.titlepage.entity.BasSupplier;
import com.zeroone.star.titlepage.mapper.BasSupplierMapper;
import com.zeroone.star.titlepage.service.IBasSupplierService;
import com.zeroone.star.titlepage.entity.BasSupplier;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 供应商 服务实现类
 * </p>
 *
 * @author ss
 * @since 2023-02-12
 */
@Service
public class BasSupplierServiceImpl extends ServiceImpl<BasSupplierMapper, BasSupplier> implements IBasSupplierService {

    @Override
    public List<BasSupplierVO> queryBasSupplier() {
        List<BasSupplier> list = baseMapper.queryBasSupplier();
        List<BasSupplierVO> list1=new ArrayList<>();
        for (BasSupplier basSupplier : list) {
            BasSupplierVO basSupplierVO = new BasSupplierVO();
            BeanUtil.copyProperties(basSupplier,basSupplierVO);
            list1.add(basSupplierVO);
        }
        return list1;
    }
}
