package com.zeroone.star.titlepage.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.vo.homepage.StkIoSumVO;
import com.zeroone.star.titlepage.entity.StkIoSum;

import java.util.List;

/**
 * <p>
 * 出入库汇总 服务类
 * </p>
 *
 * @author ss
 * @since 2023-02-12
 */
public interface IStkIoSumService extends IService<StkIoSum> {

    public List<StkIoSumVO> queryStkIoSum();
}
