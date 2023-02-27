package com.zeroone.star.payablemanagement.mapper;

import com.zeroone.star.payablemanagement.entity.FinPayableCheck;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.query.payablemanagement.CheckPayableQuery;
import com.zeroone.star.project.vo.payablemanagement.CheckPayableVO;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 * 应付核销单 Mapper 接口
 * </p>
 *
 * @author j3
 * @since 2023-02-14
 */
@Mapper
public interface FinPayableCheckMapper extends BaseMapper<FinPayableCheck> {

    List<CheckPayableVO> getAllCheckPayable(CheckPayableQuery condition);
}
