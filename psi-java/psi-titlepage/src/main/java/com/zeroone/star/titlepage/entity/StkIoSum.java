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

    /**
     * ID
     */
    private String id;

    /**
     * year
     */
    private Integer year;

    /**
     * month
     */
    private Integer month;

    /**
     * 仓库
     */
    private String warehouseId;

    /**
     * 物料
     */
    private String materialId;

    /**
     * 批次
     */
    private String batchNo;

    /**
     * 计量单位
     */
    private String unitId;

    /**
     * 期初数量
     */
    private BigDecimal beginQty;

    /**
     * 期初成本
     */
    private BigDecimal beginCost;

    /**
     * 入库数量
     */
    private BigDecimal inQty;

    /**
     * 入库成本
     */
    private BigDecimal inCost;

    /**
     * 出库数量
     */
    private BigDecimal outQty;

    /**
     * 出库成本
     */
    private BigDecimal outCost;

    /**
     * 结存数量
     */
    private BigDecimal balQty;

    /**
     * 结存成本
     */
    private BigDecimal balCost;


}
