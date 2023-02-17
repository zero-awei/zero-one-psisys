package com.zeroone.star.project.dto.prepayment;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;

import java.math.BigDecimal;
import java.sql.Date;
import java.util.List;

/**
 * @Author: Kong
 * @License: (C) Copyright 2005-2019, xxx Corporation Limited.
 * @Contact: xxx@xxx.com
 * @Date: 2023-02-11 20:31
 * @Version: 1.0
 * @Description: 预付款
 */
@ApiModel("预付款信息")
public class PrepaymentDTO {

    @ApiModelProperty(value = "金额",example = "1000.00")
    private BigDecimal amt;

    @ApiModelProperty(value = "单据日期",example = "2022-01-14")
    private Date billDate;

    @ApiModelProperty(value = "单据编号",example = "CGYF-221120-002")
    private String billNo;

    @ApiModelProperty(value = "已核销金额",example = "1000.00")
    private Integer checkAmt;

    @ApiModelProperty(value = "是否自动单据",example = "0")
    private Integer isAuto;

    @ApiModelProperty(value = "是否红字",example = "0")
    private Integer isRubric;

    @ApiModelProperty(value = "付款类型",example = "2011")
    private Integer paymentType;

    @ApiModelProperty(value = "备注",example = "remark..")
    private String remark;

    @ApiModelProperty(value = "源单类型",example = "FinPaymentReq:2011")
    private String srcBillType;

    @ApiModelProperty(value = "源单id",example = "1594317750844637186")
    private String srcBillId;

    @ApiModelProperty(value = "源单号",example = "CGYFSQ-221120-001")
    private String srcNo;

    @ApiModelProperty(value = "单据主题",example = "tittle")
    private String subject;

    @ApiModelProperty(value = "供应商",example = "1584950950470164481")
    private String supplierId;

    @ApiModelProperty(value = "采购明细单",example = "")
    private List<FinPaymentEntryDTO> finPaymentEntryList;

}
