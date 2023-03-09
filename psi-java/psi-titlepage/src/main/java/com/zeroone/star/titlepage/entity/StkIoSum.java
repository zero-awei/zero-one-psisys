package com.zeroone.star.titlepage.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.math.BigDecimal;

/**
 * <p>
 * 出入库汇总
 * </p>
 *
 * @author ss
 * @since 2023-02-12
 */
@Getter
@Setter
@TableName("stk_io_sum")
public class StkIoSum implements Serializable {

    private static final long serialVersionUID = 1L;
    private String x;
    private String y;


}
