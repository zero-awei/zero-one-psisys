package com.zeroone.star.prepayment.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 供应商
 * </p>
 *
 * @author Kong
 * @since 2023-02-17
 */
@Getter
@Setter
@TableName("bas_supplier")
public class BasSupplier implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * ID
     */
    private String id;

    /**
     * 编码
     */
    private String code;

    /**
     * 名称
     */
    private String name;

    /**
     * 简称
     */
    private String shortName;

    /**
     * 助记名
     */
    private String auxName;

    /**
     * 供应商分类
     */
    private String supplierCategory;

    /**
     * 供应商等级
     */
    private String supplierLevel;

    /**
     * 纳税规模
     */
    private String taxScale;

    /**
     * 所属总公司
     */
    private String headquarters;

    /**
     * 所属地区
     */
    private String area;

    /**
     * 业务区域
     */
    private String bizArea;

    /**
     * 供应商地址
     */
    private String address;

    /**
     * 供应商网站
     */
    private String website;

    /**
     * 法人代表
     */
    private String legalPerson;

    /**
     * 法人电话
     */
    private String legalPersonPhone;

    /**
     * 财务信息联系人
     */
    private String financialContacts;

    /**
     * 财务信息联系电话
     */
    private String financialPhone;

    /**
     * 开票信息单位名称
     */
    private String invoiceCompany;

    /**
     * 开票信息税号
     */
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
    private String receiptCompany;

    /**
     * 办款资料开户行
     */
    private String receiptBankName;

    /**
     * 办款资料行号
     */
    private String receiptBankCode;

    /**
     * 办款资料账号
     */
    private String receiptAccount;

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
     * 备选供应商
     */
    private String alterSuppliers;

    /**
     * 备注
     */
    private String remark;

    /**
     * 创建人
     */
    private String createBy;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 修改人
     */
    private String updateBy;

    /**
     * 修改时间
     */
    private LocalDateTime updateTime;

    /**
     * 版本
     */
    private Integer version;


}
