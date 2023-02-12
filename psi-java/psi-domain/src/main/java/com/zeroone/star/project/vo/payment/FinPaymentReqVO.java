package com.zeroone.star.project.vo.payment;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;
import java.time.LocalDate;

/**
 * @ClassName finPaymentReqVO
 * @Description 采购预付申请单对象
 * @Author HZP
 * @Date 2023/2/12 15:54
 * @Version 1.0
 **/
@Data
@ApiModel("采购预付申请单对象")
public class FinPaymentReqVO {
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
     * 申请金额
     */
    @ApiModelProperty(value = "申请金额",example = "90000")
    private BigDecimal amt;

    /**
     * 已付金额
     */
    @ApiModelProperty(value = "已付金额",example = "0")
    private BigDecimal paidAmt;

    /**
     * 备注
     */
    @ApiModelProperty(value = "备注",example = "")
    private String remark;
}