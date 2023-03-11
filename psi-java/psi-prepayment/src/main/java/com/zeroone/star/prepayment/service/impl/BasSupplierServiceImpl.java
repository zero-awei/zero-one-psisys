package com.zeroone.star.prepayment.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.prepayment.entity.BasSupplier;
import com.zeroone.star.prepayment.mapper.BasSupplierMapper;
import com.zeroone.star.prepayment.service.IBasSupplierService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.vo.prepayment.SupplierVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 供应商 服务实现类
 * </p>
 *
 * @author Kong
 * @since 2023-02-17
 */
@Service
public class BasSupplierServiceImpl extends ServiceImpl<BasSupplierMapper, BasSupplier> implements IBasSupplierService {

    @Autowired
    BasSupplierMapper supplierMapper;

    @Override
    public List<SupplierVO> getSupplierList() {
        QueryWrapper queryWrapper = new QueryWrapper<>();
        List<BasSupplier> suppliers = supplierMapper.selectList(queryWrapper);

        ArrayList<SupplierVO> supplierVOS = new ArrayList<>();
        for (BasSupplier supplier : suppliers){
            supplierVOS.add(new SupplierVO(supplier.getId(),supplier.getAuxName())) ;
        }

        return supplierVOS;
    }
}
