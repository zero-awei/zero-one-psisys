package com.zeroone.star.prepayment.service.impl;

import com.zeroone.star.prepayment.entity.SysDepart;
import com.zeroone.star.prepayment.mapper.SysDepartMapper;
import com.zeroone.star.prepayment.service.ISysDepartService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * <p>
 * 组织机构表 服务实现类
 * </p>
 *
 * @author Kong
 * @since 2023-02-17
 */
@Service
public class SysDepartServiceImpl extends ServiceImpl<SysDepartMapper, SysDepart> implements ISysDepartService {

    @Override
    public List<SysDepart> getDeparts() {
        return null;
    }
}
