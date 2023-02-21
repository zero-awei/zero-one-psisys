package com.zeroone.star.project.vo.prepayment;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;
import java.time.LocalDate;

/**
 * ClassName finPaymentReqVO
 * Description 采购预付申请单对象
 * Author HZP、KONG
 * Date 2023/2/12 15:54
 * Version 1.0
 **/
@Data
@ApiModel("采购预付申请单对象")
public class FinPaymentReqVO {
    @ApiModelProperty(value = "id",example = "1594317750844637186")
    private String id;

    @ApiModelProperty(value = "单据编号",example = "CGYFSQ-221120-001")
    private String billNo;

    @ApiModelProperty(value = "单据日期",example = "2023-02-11")
    private LocalDate billDate;

    @ApiModelProperty(value = "单据主题",example = "无")
    private String subject;

    @ApiModelProperty(value = "付款类型",example = "2011")
    private Integer paymentType;

    @ApiModelProperty(value = "供应商",example = "1584950950470164481")
    private String supplierId;

    @ApiModelProperty(value = "操作部门",example = "A01A03")
    private String opDept;

    @ApiModelProperty(value = "业务员",example = "zhagnxiao")
    private String operator;

    @ApiModelProperty(value = "申请金额",example = "90000")
    private BigDecimal amt;

    @ApiModelProperty(value = "已付金额",example = "0")
    private BigDecimal paidAmt;

    @ApiModelProperty(value = "备注",example = "无")
    private String remark;

    @ApiModelProperty(value = "已关闭",example = "1")
    private Integer isClosed;
}

