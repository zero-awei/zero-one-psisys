package com.zeroone.star.titlepage.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.homepage.HomeDoingBillVO;
import com.zeroone.star.titlepage.entity.HomeDoingBill;

import java.util.List;

/**
 * <p>
 * VIEW 服务类
 * </p>
 *
 * @author ss
 * @since 2023-02-12
 */
public interface IHomeDoingBillService extends IService<HomeDoingBill> {
    /**
     * 查询处理中单据
     * @return
     */
    public List<HomeDoingBillVO> listHomeDoingBill();
}
