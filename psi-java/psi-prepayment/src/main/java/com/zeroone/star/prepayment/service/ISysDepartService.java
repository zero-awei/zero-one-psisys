package com.zeroone.star.prepayment.service;

import com.zeroone.star.prepayment.entity.SysDepart;
import com.baomidou.mybatisplus.extension.service.IService;

import java.util.List;

/**
 * <p>
 * 组织机构表 服务类
 * </p>
 *
 * @author Kong
 * @since 2023-02-17
 */
public interface ISysDepartService extends IService<SysDepart> {

    public List<SysDepart> getDeparts();
}
