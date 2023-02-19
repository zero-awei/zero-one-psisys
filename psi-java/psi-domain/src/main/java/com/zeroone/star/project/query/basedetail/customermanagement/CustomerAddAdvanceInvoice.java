package com.zeroone.star.project.query.basedetail.customermanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @Description 添加customer的发票高级选项
 * @author YinXing
 * @date 2023年02月19日
 */
@Data
@ApiModel("添加customer的发票高级选项")
public class CustomerAddAdvanceInvoice {

    @ApiModelProperty(value = "开票信息单位名称", example = " 微软（中国）有限公司")
    private String invoiceCompany;

    @ApiModelProperty(value = "开票信息税号", example = "91110108600040399G")
    private String invoiceTaxCode;

    @ApiModelProperty(value = "开票信息开户行", example = "中国银行股份有限公司北京阜成门内支行")
    private String invoiceBankName;

    @ApiModelProperty(value = "开票信息行号", example = "104100006386")
    private String invoiceBankCode;

    @ApiModelProperty(value = "开票信息账号", example = "6217851284825654498")
    private String invoiceAccount;

    @ApiModelProperty(value = "开票信息联系电话", example = "12345678920")
    private String invoicePhone;

    @ApiModelProperty(value = "开票地址", example = "北京市海淀区")
    private String invoiceAddress;
}
