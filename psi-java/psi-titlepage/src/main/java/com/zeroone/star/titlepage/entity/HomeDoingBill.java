package com.zeroone.star.titlepage.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.math.BigDecimal;

/**
 * <p>
 * VIEW
 * </p>
 *
 * @author ss
 * @since 2023-02-12
 */
@Getter
@Setter
@TableName("home_doing_bill")
public class HomeDoingBill implements Serializable {

    private static final long serialVersionUID = 1L;

    private String name;

    private BigDecimal edit;

    private BigDecimal appr;

    private BigDecimal exec;


}
