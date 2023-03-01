package com.zeroone.star.payablemanagement.service;

import com.zeroone.star.payablemanagement.entity.FinPayableCheckEntry;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.query.payablemanagement.CheckPayableEntryQuery;
import com.zeroone.star.project.vo.payablemanagement.CheckPayableEntryVO;

import java.util.List;

/**
 * <p>
 * 应付核销明细 服务类
 * </p>
 *
 * @author j3
 * @since 2023-02-14
 */
public interface IFinPayableCheckEntryService extends IService<FinPayableCheckEntry> {
    public List<CheckPayableEntryVO> getByMainId(CheckPayableEntryQuery query);
}
