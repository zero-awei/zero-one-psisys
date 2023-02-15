package com.zeroone.star.project.dto.systemmanagement.customermanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;

/**
 * @Description
 * @Author mumu
 * @Data 2023-02-13 11:36
 */
@Data
@ApiModel("查询客户DTO")
public class CustomerDTO {
    @ApiModelProperty(value = "客户对象ID", example = "1584950506310148098")
    private String Id;

    @ApiModelProperty(value = "客户对象编码code", example = "001")
    private String code;

    @ApiModelProperty(value = "客户对象名称name", example = "北京xx化学工业公司")
    private String name;

    @ApiModelProperty(value = "客户对象简称")
    private String short_name;

    @ApiModelProperty(value = "客户对象助记名aux_name", example = "001 北京xx化工")
    private String aux_name;

    @ApiModelProperty(value = "客户对象分类customer_category", example = "一级")
    private String customer_category;

    @ApiModelProperty(value = "客户对象客户等级customer_level")
    private String customer_level;

    @ApiModelProperty(value = "客户对象纳税规模tax_scale", example = "一般纳税人")
    private String tax_scale;
    /**
     * 欠款额度
     */
    @ApiModelProperty(value = "客户对象欠款额度creditQuota", example = "900.00")
    private BigDecimal creditQuota;

    /**
     * 所属总公司
     */
    @ApiModelProperty(value = "客户对象所属总公司headquarters")
    private String headquarters;

    /**
     * 所属地区
     */
    @ApiModelProperty(value = "客户对象所属地区area", example = "0101")
    private String area;

    /**
     * 业务区域
     */
    @ApiModelProperty(value = "客户对象业务区域bizArea", example = "0101")
    private String bizArea;

    /**
     * 客户地址
     */
    @ApiModelProperty(value = "客户对象地址address")
    private String address;

    /**
     * 客户网站
     */
    @ApiModelProperty(value = "客户对象网址website")
    private String website;

    /**
     * 法人代表
     */
    @ApiModelProperty(value = "客户对象法人代表legalPerson")
    private String legalPerson;

    /**
     * 法人电话
     */
    @ApiModelProperty(value = "客户对象法人电话legalPersonPhone")
    private String legalPersonPhone;

    /**
     * 财务信息联系人
     */
    @ApiModelProperty(value = "客户对象财务信息联系人financialContacts")
    private String financialContacts;

    /**
     * 财务信息联系电话
     */
    @ApiModelProperty(value = "客户对象财务信息联系电话financialPhone")
    private String financialPhone;

    /**
     * 开票信息单位名称
     */
    @ApiModelProperty(value = "客户对象开票信息单位名称invoiceCompany")
    private String invoiceCompany;

    /**
     * 开票信息税号
     */
    @ApiModelProperty(value = "客户对象开票信息税号invoiceTaxCode")
    private String invoiceTaxCode;

    /**
     * 开票信息开户行
     */
    private String invoiceBankName;

    /**
     * 开票信息行号
     */
    private String invoiceBankCode;

    /**
     * 开票信息账号
     */
    private String invoiceAccount;

    /**
     * 开票信息联系电话
     */
    private String invoicePhone;

    /**
     * 开票地址
     */
    private String invoiceAddress;

    /**
     * 办款资料单位名称
     */
    private String paymentCompany;

    /**
     * 办款资料开户行
     */
    private String paymentBankName;

    /**
     * 办款资料行号
     */
    private String paymentBankCode;

    /**
     * 办款资料账号
     */
    private String paymentAccount;

    /**
     * 收件信息收件人
     */
    private String recvName;

    /**
     * 收件信息联系电话
     */
    private String recvPhone;

    /**
     * 收件信息传真
     */
    private String recvFax;

    /**
     * 收件信息Email
     */
    private String recvEmail;

    /**
     * 收件信息地址
     */
    private String recvAddress;

    /**
     * 收件信息邮编
     */
    private String recvPostcode;

    /**
     * 附件
     */
    private String attachment;

    /**
     * 启用
     */
    private Integer isEnabled;

    /**
     * 备注
     */
    private String remark;

    /**
     * 创建人
     */
    private String createBy;
}
