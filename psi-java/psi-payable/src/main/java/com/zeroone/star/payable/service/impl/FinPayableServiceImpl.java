package com.zeroone.star.payable.service.impl;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.payable.entity.FinPayable;
import com.zeroone.star.payable.mapper.FinPayableMapper;
import com.zeroone.star.payable.service.IFinPayableService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.payable.FinPayableDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payable.FinPayableVO;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 应付单 服务实现类
 * </p>
 *
 * @author chosen1
 * @since 2023-02-13
 */
@Service
public class FinPayableServiceImpl extends ServiceImpl<FinPayableMapper, FinPayable> implements IFinPayableService {

    @Override
    public JsonVO<Page<FinPayableVO>> listAll(FinPayableDTO payableDTO) {
        return null;
    }

    @Override
    public JsonVO<FinPayableVO> getById(String id) {
        return null;
    }
}
