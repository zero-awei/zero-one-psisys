package com.zeroone.star.prepayment.service;

import com.zeroone.star.prepayment.entity.BasSupplier;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.vo.prepayment.SupplierVO;

import java.util.List;

/**
 * <p>
 * 供应商 服务类
 * </p>
 *
 * @author Kong
 * @since 2023-02-17
 */
public interface IBasSupplierService extends IService<BasSupplier> {

    /**
     * 获取供应商列表
     * @return SupplierVO 供应商显示对象
     * @author Kong
     */
    public List<SupplierVO> getSupplierList();
}
