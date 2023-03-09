package com.zeroone.star.titlepage.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.vo.homepage.BasSupplierVO;
import com.zeroone.star.titlepage.entity.BasSupplier;

import java.util.List;

/**
 * <p>
 * 供应商 服务类
 * </p>
 *
 * @author ss
 * @since 2023-02-12
 */
public interface IBasSupplierService extends IService<BasSupplier> {

    /*
    查询供应商
     */
    public List<BasSupplierVO> queryBasSupplier();
}
