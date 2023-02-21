package com.zeroone.star.project.dto.basedetail.customermanagement;

import com.alibaba.fastjson.annotation.JSONField;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.math.BigDecimal;
import java.math.BigInteger;
import java.time.LocalDateTime;
import java.util.Date;

/**
 * @Description 添加customer
 * @author YinXing
 * @date 2023年02月19日
 */
@Data
@ApiModel("添加客户")
public class CustomerAddDTO {
    @ApiModelProperty(value = "客户编码",example = "003")
    private String code;

    @ApiModelProperty(value = "客户名称",example = "Microsoft Corporation")
    private String name;

    @ApiModelProperty(value = "助记名", example = "微软")
    private String auxName;

    @ApiModelProperty(value = "客户分类",example = "001")
    private String customerCategory;

    @ApiModelProperty(value = "客户分类",example = "001")   //?
    private String customerLevel;

    @ApiModelProperty(value = "客户纳税规模",example = "一般纳税人")
    private String taxScale;

    @ApiModelProperty(value = "欠款额度",example = "100000")
    private BigDecimal creditQuota;

    @ApiModelProperty(value = "启用", example = "1")
    private Integer isEnabled;

    @ApiModelProperty(value = "备注", example = "欠款未还")
    private String remark;

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

    @ApiModelProperty(value = "办款资料单位名称", example = "百度")
    private String paymentCompany;

    @ApiModelProperty(value = "办款资料开户行", example = "中国银行股份有限公司北京阜成门内支行")
    private String paymentBankName;

    @ApiModelProperty(value = "办款资料行号", example = "104100006386")
    private String paymentBankCode;

    @ApiModelProperty(value = "办款资料账号", example = "6217851284827854498")
    private String paymentAccount;

    @ApiModelProperty(value = "收件信息收件人", example = "张三")
    private String recvName;

    @ApiModelProperty(value = "收件信息联系电话", example = "12345678920")
    private String recvPhone;

    @ApiModelProperty(value = "收件信息传真", example = "02088888888")
    private String recvFax;

    @ApiModelProperty(value = "收件信息Email", example = "1234657890@qq.com")
    private String recvEmail;

    @ApiModelProperty(value = "收件信息地址", example = "北京市海淀区上地十街10号百度大厦")
    private String recvAddress;

    @ApiModelProperty(value = "收件信息邮编", example = "100085")
    private String recvPostcode;

    @ApiModelProperty(value = "财务信息联系人", example = "李四")
    private String financialContacts;

    @ApiModelProperty(value = "财务信息联系电话", example = "12345678905")
    private String financialPhone;

    @ApiModelProperty(value = "简称", example = "baidu")
    private String shortName;

    @ApiModelProperty(value = "辅助名称", example = "百度")
    private String auxiliaryName;

    @ApiModelProperty(value = "客户网站", example = "com.baidu.com")
    private String website;

    @ApiModelProperty(value = "法人代表", example = "沈抖")
    private String legalPerson;

    @ApiModelProperty(value = "法人电话", example = "12345678909")
    private String legalPersonPhone;

    @ApiModelProperty(value = "所属总公司", example = "百度")
    private String headquarters;

    @ApiModelProperty(value = "所属地区", example = "北京")
    private String area;

    @ApiModelProperty(value = "业务区域", example = "北京")
    private String bizArea;

    @ApiModelProperty(value = "客户地址", example = "上海自由贸易试验区纳贤路701号")
    private String address;

    @ApiModelProperty(value = "附件", example = "测试发送内容")
    private String attachment;
}
