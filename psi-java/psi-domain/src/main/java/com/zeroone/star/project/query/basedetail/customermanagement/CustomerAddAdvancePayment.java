package com.zeroone.star.project.query.basedetail.customermanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @Description 添加customer的办款资料高级选项
 * @author YinXing
 * @date 2023年02月19日
 */
@Data
@ApiModel("添加customer的办款资料高级选项")
public class CustomerAddAdvancePayment {

    @ApiModelProperty(value = "办款资料单位名称", example = "百度")
    private String paymentCompany;

    @ApiModelProperty(value = "办款资料开户行", example = "中国银行股份有限公司北京阜成门内支行")
    private String paymentBankName;

    @ApiModelProperty(value = "办款资料行号", example = "104100006386")
    private String paymentBankCode;

    @ApiModelProperty(value = "办款资料账号", example = "6217851284827854498")
    private String paymentAccount;
}
