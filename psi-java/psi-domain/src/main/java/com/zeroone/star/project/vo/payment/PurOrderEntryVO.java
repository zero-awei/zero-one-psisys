package com.zeroone.star.project.vo.payment;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import java.math.BigDecimal;
import java.sql.Date;
import java.time.LocalDateTime;

/**
 * <p>
 * 采购订单明细
 * </p>
 *  参数涉及 PurOrder + entry两张表
 * @author Kong
 * @since 2023-02-11
 */
@Data
@ApiModel("采购明细对象")
public class PurOrderEntryVO{
//TODO billDate需要单独传
    /**
     * id
     */
    @ApiModelProperty(value = "id",example = "1590710155294588930")
    private String id;

    /**
     * 单据号
     */
    @ApiModelProperty(value = "单据编号",example = "CGDD-221110-001")
    private String billNo;

    /**
     * 单据日期
     */
    @ApiModelProperty(value = "单据日期",example = "2022-01-14")
    private Date billDate;

    /**
     * 交货方式
     */
    @ApiModelProperty(value = "交货方式",example = "")
    private String deliveryMethod;

    /**
     * 交货地点
     */
    @ApiModelProperty(value = "交货地点",example = "")
    private String deliveryPlace;

    /**
     * 交货日期
     */
    @ApiModelProperty(value = "交货日期",example = "")
    private LocalDateTime deliveryTime;

    /**
     * 已关闭
     */
    @ApiModelProperty(value = "已关闭",example = "0")
    private Integer isClosed;

    @ApiModelProperty(value = "操作部门",example = "A01A03")
    private String opDept;

    /**
     * 业务员
     */
    @ApiModelProperty(value = "业务员",example = "zhagnxiao")
    private String operator;

    /**
     * 付款方式
     */
    @ApiModelProperty(value = "付款方式",example = "")
    private String paymentMethod;

    /**
     * 预付款余额
     */
    @ApiModelProperty(value = "预付款余额",example = "0.00")
    private BigDecimal prepaymentBal;

    /**
     * 采购类型
     */
    @ApiModelProperty(value = "采购类型",example = "2")
    private String purType;

    /**
     * 供应商
     */
    @ApiModelProperty(value = "供应商",example = "1584950950470164481")
    private String supplierId;

    /**
     * 分录号
     */
    @ApiModelProperty(value = "分录号",example = "10")
    private Integer entryNo;

    /**
     * 源单分录号
     */
    @ApiModelProperty(value = "源单分录号",example = "10")
    private String srcNo;

    /**
     * 数量
     */
    @ApiModelProperty(value = "数量",example = "11")
    private BigDecimal qty;

    /**
     * 含税金额
     */
    @ApiModelProperty(value = "含税金额",example = "88000.00")
    private BigDecimal amt;

    /**
     * 已入库数量
     */
    @ApiModelProperty(value = "已入库数量",example = "11.000000")
    private BigDecimal inQty;

    /**
     * 已入库成本
     */
    @ApiModelProperty(value = "已入库成本",example = "88000.00")
    private BigDecimal inCost;

    /**
     * 结算金额
     */
    @ApiModelProperty(value = "结算金额",example = "88000.00")
    private BigDecimal settleAmt;

    /**
     * 已开票金额
     */
    @ApiModelProperty(value = "已开票金额",example = "88000.00")
    private BigDecimal invoicedAmt;

    /**
     * 发票类型
     */
    private String invoiceType;

    /**
     * 备注
     */
    @ApiModelProperty(value = "备注",example = "备注")
    private String remark;

    /**
     * 自定义1
     */
    @ApiModelProperty(value = "自定义1",example = "")
    private String custom1;

    /**
     * 自定义2
     */
    @ApiModelProperty(value = "自定义2",example = "")
    private String custom2;

}
