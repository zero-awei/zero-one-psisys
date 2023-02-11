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
@TableName("fin_receivable_bal")
public class FinReceivableBal implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * ID
     */
    private String id;

    /**
     * ID
     */
    private String customerId;

    /**
     * 名称
     */
    private String customerName;

    private BigDecimal debitBal;


}
