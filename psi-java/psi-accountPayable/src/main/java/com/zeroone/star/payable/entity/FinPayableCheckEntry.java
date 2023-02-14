package com.zeroone.star.payable.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.math.BigDecimal;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 应付核销明细
 * </p>
 *
 * @author j3
 * @since 2023-02-14
 */
@Getter
@Setter
@TableName("fin_payable_check_entry")
public class FinPayableCheckEntry implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * ID
     */
    private String id;

    /**
     * 主表
     */
    private String mid;

    /**
     * 单据编号
     */
    private String billNo;

    /**
     * 分录号
     */
    private Integer entryNo;

    /**
     * 源单类型
     */
    private String srcBillType;

    /**
     * 源单id
     */
    private String srcBillId;

    /**
     * 源单分录id
     */
    private String srcEntryId;

    /**
     * 源单号
     */
    private String srcNo;

    /**
     * 核销方向
     */
    private String checkSide;

    /**
     * 核销金额
     */
    private BigDecimal amt;

    /**
     * 备注
     */
    private String remark;

    /**
     * 自定义1
     */
    private String custom1;

    /**
     * 自定义2
     */
    private String custom2;

    /**
     * 版本
     */
    private Integer version;


}
