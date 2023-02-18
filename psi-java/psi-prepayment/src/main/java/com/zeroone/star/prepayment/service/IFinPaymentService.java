package com.zeroone.star.prepayment.service;

import com.zeroone.star.project.dto.prepayment.PrepaymentDTO;

/**
 * @Author: Kong
 * @License: (C) Copyright 2005-2019, xxx Corporation Limited.
 * @Contact: xxx@xxx.com
 * @Date: 2023-02-18 20:51
 * @Version: 1.0
 * @Description:
 */

public interface IFinPaymentService {

    /**
     * 插入数据
     * @param prepaymentDTO 数据传输对象
     * @return
     */
    public int insert(PrepaymentDTO prepaymentDTO);
}