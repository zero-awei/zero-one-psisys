package com.zeroone.star.paymentmanagement.service.impl;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.paymentmanagement.entity.StkIo;
import com.zeroone.star.paymentmanagement.service.StkIoService;
import com.zeroone.star.paymentmanagement.mapper.StkIoMapper;
import com.zeroone.star.project.query.paymentmanagement.StkIoQuery;
import com.zeroone.star.project.vo.paymentmanagement.StkIoVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

/**
* @author 白也
* @description 针对表【stk_io(出入库单)】的数据库操作Service实现
* @createDate 2023-02-24 18:00:39
*/
@Service
public class StkIoServiceImpl extends ServiceImpl<StkIoMapper, StkIo>
    implements StkIoService{
    @Autowired
    private StkIoMapper stkIoMapper;

    /**
     * 入库单查询
     *
     * @param stkIoQuery 条件
     * @return list
     */
    @Override
    public Page<StkIoVO> queryAll(StkIoQuery stkIoQuery) {
        Page<StkIo> page = new Page<>(1,10);
        return  stkIoMapper.queryAll(page, stkIoQuery.getBillNo(), stkIoQuery.getBillDate(), stkIoQuery.getSupplierId());
    }

    /**
     * 采购退货出库单
     *
     * @param stkIoQuery 条件
     * @return list
     */
    @Override
    public Page<StkIoVO> deliveryOrder(StkIoQuery stkIoQuery) {
        Page<StkIo> page = new Page<>(1,10);
        return  stkIoMapper.deliveryOrder(page, stkIoQuery.getBillNo(), stkIoQuery.getBillDate(), stkIoQuery.getSupplierId());
    }

}




