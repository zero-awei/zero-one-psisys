package com.zeroone.star.titlepage.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.titlepage.entity.StkIoSum;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 * 出入库汇总 Mapper 接口
 * </p>
 *
 * @author ss
 * @since 2023-02-12
 */
@Mapper
public interface StkIoSumMapper extends BaseMapper<StkIoSum> {
    /*
    查询库存结余
     */
    List<StkIoSum> queryStkIoSum();
}
