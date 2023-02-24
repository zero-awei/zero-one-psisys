package com.zeroone.star.paymentmanagement.mapper;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.paymentmanagement.entity.FinPaymentReq;
import com.zeroone.star.paymentmanagement.entity.StkIo;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.query.paymentmanagement.StkIoQuery;
import com.zeroone.star.project.vo.paymentmanagement.StkIoVO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.io.Serializable;
import java.time.LocalDate;
import java.util.Collection;
import java.util.List;

/**
* @author 白也
* @description 针对表【stk_io(出入库单)】的数据库操作Mapper
* @createDate 2023-02-24 18:00:39
* @Entity com.zeroone.star.paymentmanagement.entity.StkIo
*/
@Mapper
public interface StkIoMapper extends BaseMapper<StkIo> {

    @Override
    List<StkIo> selectBatchIds(Collection<? extends Serializable> idList);

    /**
     * 入库单查询
     * @param stkIoQuery
     * @return
     */
    Page<StkIoVO> queryAll(@Param("page")Page<StkIo> page, @Param("billNo") String billNo, @Param("billDate") LocalDate billDate, @Param("supplierId") String supplierId);

}




