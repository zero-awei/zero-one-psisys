package com.zeroone.star.payment.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.math.BigDecimal;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 采购订单明细
 * </p>
 *
 * @author zhd
 * @since 2023-02-11
 */
@Getter
@Setter
@TableName("pur_order_entry")
public class PurOrderEntry implements Serializable {

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
     * 单据号
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
     * srcBillId
     */
    private String srcBillId;

    /**
     * 源单分录id
     */
    private String srcEntryId;

    /**
     * 源单分录号
     */
    private String srcNo;

    /**
     * 物料
     */
    private String materialId;

    /**
     * 计量单位
     */
    private String unitId;

    /**
     * 数量
     */
    private BigDecimal qty;

    /**
     * 税率%
     */
    private BigDecimal taxRate;

    /**
     * 含税单价
     */
    private BigDecimal price;

    /**
     * 折扣率%
     */
    private BigDecimal discountRate;

    /**
     * 税额
     */
    private BigDecimal tax;

    /**
     * 含税金额
     */
    private BigDecimal amt;

    /**
     * 已入库数量
     */
    private BigDecimal inQty;

    /**
     * 已入库成本
     */
    private BigDecimal inCost;

    /**
     * 结算数量
     */
    private BigDecimal settleQty;

    /**
     * 结算金额
     */
    private BigDecimal settleAmt;

    /**
     * 已开票数量
     */
    private BigDecimal invoicedQty;

    /**
     * 已开票金额
     */
    private BigDecimal invoicedAmt;

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
