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
@TableName("fin_payable_bal")
public class FinPayableBal implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * ID
     */
    private String id;

    /**
     * ID
     */
    private String supplierId;

    /**
     * 名称
     */
    private String supplierName;

    private BigDecimal creditBal;


}
