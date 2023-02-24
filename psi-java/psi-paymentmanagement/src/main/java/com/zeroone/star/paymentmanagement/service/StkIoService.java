package com.zeroone.star.paymentmanagement.service;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.paymentmanagement.entity.StkIo;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.query.paymentmanagement.StkIoQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.paymentmanagement.StkIoVO;

import java.util.List;

/**
* @author 白也
* @description 针对表【stk_io(出入库单)】的数据库操作Service
* @createDate 2023-02-24 18:00:39
*/
public interface StkIoService extends IService<StkIo> {
    /**
     * 入库单查询
     * @param stkIoQuery
     * @return
     */
    Page<StkIoVO> queryAll(StkIoQuery stkIoQuery);

    /**
     * 采购退货出库单
     * @param stkIoQuery 条件
     * @return list
     */
    Page<StkIoVO> deliveryOrder(StkIoQuery stkIoQuery);

}
