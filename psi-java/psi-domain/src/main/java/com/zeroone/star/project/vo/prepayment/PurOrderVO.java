package com.zeroone.star.project.vo.prepayment;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;
import java.time.LocalDate;
import java.time.LocalDateTime;

/**
 * @ClassName PurOrderVO
 * @Description 采购订单对象
 * @Author HZP
 * @Date 2023/2/12 16:06
 * @Version 1.0
 **/
@Data
@ApiModel("采购订单对象")
public class PurOrderVO {
    /**
     * 单据编号
     */
    @ApiModelProperty(value = "单据编号",example = "CGFKSQ-230211-004")
    private String billNo;

    /**
     * 单据日期
     */
    @ApiModelProperty(value = "单据日期",example = "2023-02-11")
    private LocalDate billDate;

    /**
     * 单据主题
     */
    @ApiModelProperty(value = "单据主题",example = "")
    private String subject;

    /**
     * 源单号
     */
    @ApiModelProperty(value = "源单号",example = "")
    private String srcNo;

    /**
     * 采购类型
     */
    @ApiModelProperty(value = "采购类型",example = "")
    private String purType;
    /**
     * 金额
     */
    @ApiModelProperty(value = "采购金额",example = "")
    private BigDecimal amt;
    /**
     * 预付款余额
     */
    @ApiModelProperty(value = "预付余额",example = "")
    private BigDecimal prepaymentBal;
    /**
     * 结算金额
     */
    @ApiModelProperty(value = "结算金额",example = "")
    private BigDecimal settleAmt;
    /**
     * 已结算金额
     */
    @ApiModelProperty(value = "已结算金额",example = "")
    private BigDecimal settledAmt;
    /**
     * 付款方式
     */
    @ApiModelProperty(value = "付款方式",example = "")
    private String paymentMethod;

    /**
     * 结算方式
     */
    @ApiModelProperty(value = "结算方式",example = "")
    private String settleMethod;
    /**
     * 交货日期
     */
    @ApiModelProperty(value = "交货日期",example = "")
    private LocalDateTime deliveryTime;
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
     * 备注
     */
    @ApiModelProperty(value = "备注",example = "")
    private String remark;
}
