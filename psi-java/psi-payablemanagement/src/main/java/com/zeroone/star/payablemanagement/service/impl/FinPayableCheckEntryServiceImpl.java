package com.zeroone.star.payablemanagement.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.payablemanagement.entity.FinPayable;
import com.zeroone.star.payablemanagement.entity.FinPayableCheckEntry;
import com.zeroone.star.payablemanagement.mapper.FinPayableCheckEntryMapper;
import com.zeroone.star.payablemanagement.service.IFinPayableCheckEntryService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.payablemanagement.service.IFinPayableService;
import com.zeroone.star.project.query.payablemanagement.CheckPayableEntryQuery;
import com.zeroone.star.project.vo.payablemanagement.CheckPayableEntryVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.math.BigDecimal;
import java.util.List;
import java.util.stream.Collectors;

/**
 * <p>
 * 应付核销明细 服务实现类
 * </p>
 *
 * @author j3
 * @since 2023-02-14
 */
@Service
public class FinPayableCheckEntryServiceImpl extends ServiceImpl<FinPayableCheckEntryMapper, FinPayableCheckEntry> implements IFinPayableCheckEntryService {

    @Resource
    FinPayableCheckEntryMapper mapper;

    @Override
    public List<CheckPayableEntryVO> getByMainId(CheckPayableEntryQuery query) {
        List<CheckPayableEntryVO> list = mapper.getByMainId(query);
        if(list.isEmpty()) {
            return null;
        }
        return list;
    }

}
