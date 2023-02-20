package com.zeroone.star.project.dto.prepayment;


import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.ToString;
import org.springframework.format.annotation.DateTimeFormat;

import java.math.BigDecimal;
import java.time.LocalDate;
import java.util.List;
import org.springframework.web.multipart.MultipartFile;

/**
 * @Author: Kong
 * @License: (C) Copyright 2005-2019, xxx Corporation Limited.
 * @Contact: xxx@xxx.com
 * @Date: 2023-02-11 20:31
 * @Version: 1.0
 * @Description: 预付款
 */
@Data
@ToString
@ApiModel("预付款信息")
public class PrepaymentDTO {

    @ApiModelProperty(value = "金额",example = "1000.00")
    private BigDecimal amt;

    @ApiModelProperty(value = "附件",example = "temp/psi-预付_1676723329419.md")
    private String attachment;

    @ApiModelProperty(value = "单据日期",example = "2022-01-14")
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @JsonFormat(timezone = "GMT+8",pattern = "yyyy-MM-dd")
    private LocalDate billDate;

    @ApiModelProperty(value = "单据编号",example = "CGYF-221120-002")
    private String billNo;

    @ApiModelProperty(value = "已核销金额",example = "1000.00")
    private BigDecimal checkAmt;

    @ApiModelProperty(value = "是否自动单据",example = "0")
    private Integer isAuto;

    @ApiModelProperty(value = "是否红字",example = "0")
    private Integer isRubric;

    @ApiModelProperty(value = "付款类型",example = "2011")
    private String paymentType;

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

    @ApiModelProperty(value = "附件",example = "")
    private MultipartFile file;

}
