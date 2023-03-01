package com.zeroone.star.payablemanagement.mapper;

import com.zeroone.star.payablemanagement.entity.FinPayableCheckEntry;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.query.payablemanagement.CheckPayableEntryQuery;
import com.zeroone.star.project.vo.payablemanagement.CheckPayableEntryVO;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 * 应付核销明细 Mapper 接口
 * </p>
 *
 * @author j3
 * @since 2023-02-14
 */
@Mapper
public interface FinPayableCheckEntryMapper extends BaseMapper<FinPayableCheckEntry> {

    List<CheckPayableEntryVO> getByMainId(CheckPayableEntryQuery condition);
}




