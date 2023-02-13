package com.zeroone.star.titlepage.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.math.BigDecimal;
import java.time.LocalDate;
import java.time.LocalDateTime;

/**
 * <p>
 * 采购订单
 * </p>
 *
 * @author ss
 * @since 2023-02-12
 */
@Getter
@Setter
@TableName("pur_order")
public class PurOrder implements Serializable {

    private static final long serialVersionUID = 1L;
    private String x;
    private String y;

}
