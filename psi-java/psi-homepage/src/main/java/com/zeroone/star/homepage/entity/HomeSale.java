package com.zeroone.star.homepage.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.math.BigDecimal;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * VIEW
 * </p>
 *
 * @author yx
 * @since 2023-02-11
 */
@Getter
@Setter
@TableName("home_sale")
public class HomeSale implements Serializable {

    private static final long serialVersionUID = 1L;

    private String label;

    private Long tCount;

    private BigDecimal tAmt;

    private Long wCount;

    private BigDecimal wAmt;

    private Long mCount;

    private BigDecimal mAmt;


}
