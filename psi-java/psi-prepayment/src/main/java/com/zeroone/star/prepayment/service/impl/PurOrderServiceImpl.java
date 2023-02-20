package com.zeroone.star.prepayment.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.prepayment.entity.PurOrder;
import com.zeroone.star.prepayment.mapper.PurOrderMapper;
import com.zeroone.star.prepayment.service.IPurOrderService;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * @ClassName PurOrderServiceImpl
 * @Description IPurOrderService服务类的实现
 * @Author HZP
 * @Date 2023/2/20 12:41
 * @Version 1.0
 **/
@Service
public class PurOrderServiceImpl extends ServiceImpl<PurOrderMapper, PurOrder> implements IPurOrderService {
    @Override
    public List<PurOrder> listBySrcBillId(String srcBillID) {
        QueryWrapper<PurOrder> PurOrderQueryWrapper = new QueryWrapper<>();
        PurOrderQueryWrapper.eq("src_bill_id",srcBillID);
        List<PurOrder> purOrderList = baseMapper.selectList(PurOrderQueryWrapper);
        return purOrderList;
    }
}