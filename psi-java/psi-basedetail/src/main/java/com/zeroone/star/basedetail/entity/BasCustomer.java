package com.zeroone.star.basedetail.entity;

import com.alibaba.excel.annotation.ExcelIgnore;
import com.alibaba.excel.annotation.ExcelProperty;
import com.alibaba.excel.annotation.write.style.ColumnWidth;
import com.alibaba.excel.annotation.write.style.ContentStyle;
import com.alibaba.excel.enums.poi.HorizontalAlignmentEnum;
import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.math.BigDecimal;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;
import org.apache.poi.ss.usermodel.HorizontalAlignment;

/**
 * <p>
 * 客户
 * </p>
 *
 * @author ss
 * @since 2023-02-15
 */
@Getter
@Setter
@TableName("bas_customer")
@ColumnWidth(value = 20)
//@ContentStyle(horizontalAlignment = HorizontalAlignment.CENTER)
@ContentStyle(horizontalAlignment = HorizontalAlignmentEnum.CENTER)
public class BasCustomer implements Serializable {
    @Override
    public String toString() {
        return "BasCustomer{" +
                "id='" + id + '\'' +
                ", code='" + code + '\'' +
                ", name='" + name + '\'' +
                ", shortName='" + shortName + '\'' +
                ", auxName='" + auxName + '\'' +
                ", customerCategory='" + customerCategory + '\'' +
                ", customerLevel='" + customerLevel + '\'' +
                ", taxScale='" + taxScale + '\'' +
                ", creditQuota=" + creditQuota +
                ", headquarters='" + headquarters + '\'' +
                ", area='" + area + '\'' +
                ", bizArea='" + bizArea + '\'' +
                ", address='" + address + '\'' +
                ", website='" + website + '\'' +
                ", legalPerson='" + legalPerson + '\'' +
                ", legalPersonPhone='" + legalPersonPhone + '\'' +
                ", financialContacts='" + financialContacts + '\'' +
                ", financialPhone='" + financialPhone + '\'' +
                ", invoiceCompany='" + invoiceCompany + '\'' +
                ", invoiceTaxCode='" + invoiceTaxCode + '\'' +
                ", invoiceBankName='" + invoiceBankName + '\'' +
                ", invoiceBankCode='" + invoiceBankCode + '\'' +
                ", invoiceAccount='" + invoiceAccount + '\'' +
                ", invoicePhone='" + invoicePhone + '\'' +
                ", invoiceAddress='" + invoiceAddress + '\'' +
                ", paymentCompany='" + paymentCompany + '\'' +
                ", paymentBankName='" + paymentBankName + '\'' +
                ", paymentBankCode='" + paymentBankCode + '\'' +
                ", paymentAccount='" + paymentAccount + '\'' +
                ", recvName='" + recvName + '\'' +
                ", recvPhone='" + recvPhone + '\'' +
                ", recvFax='" + recvFax + '\'' +
                ", recvEmail='" + recvEmail + '\'' +
                ", recvAddress='" + recvAddress + '\'' +
                ", recvPostcode='" + recvPostcode + '\'' +
                ", attachment='" + attachment + '\'' +
                ", isEnabled='" + isEnabled + '\'' +
                ", remark='" + remark + '\'' +
                ", createBy='" + createBy + '\'' +
                ", createTime=" + createTime +
                ", updateBy='" + updateBy + '\'' +
                ", updateTime=" + updateTime +
                ", version=" + version +
                '}';
    }

    private static final long serialVersionUID = 1L;

    /**
     * ID
     */
    @ExcelIgnore
    private String id;

    /**
     * 编码
     */
    @ExcelProperty(value = "编码", index = 0)
    private String code;
    /**
     * 名称
     */
    @ExcelProperty(value = "名称", index = 1)
    private String name;
    /**
     * 简称
     */
    @ExcelProperty(value = "简称", index = 2)
    private String shortName;
    /**
     * 助记名
     */
    @ExcelProperty(value = "助记名", index = 3)
    private String auxName;
    /**
     * 客户分类
     */
    @ExcelProperty(value = "客户分类", index = 4)
    private String customerCategory;
    /**
     * 客户等级
     */
    @ExcelProperty(value = "客户等级", index = 5)
    private String customerLevel;
    /**
     * 纳税规模
     */
    @ExcelProperty(value = "纳税规模", index = 6)
    private String taxScale;

    /**
     * 欠款额度
     */
    @ExcelProperty(value = "欠款额度", index = 7)
    private BigDecimal creditQuota;

    /**
     * 所属总公司
     */
    @ExcelProperty(value = "所属总公司", index = 8)
    private String headquarters;

    /**
     * 所属地区
     */
    @ExcelProperty(value = "所属地区", index = 9)
    private String area;

    /**
     * 业务区域
     */
    @ExcelProperty(value = "业务区域", index = 10)
    private String bizArea;

    /**
     * 客户地址
     */
    @ExcelProperty(value = "客户地址", index = 11)
    private String address;

    /**
     * 客户网站
     */
    @ExcelProperty(value = "客户网站", index = 12)
    private String website;

    /**
     * 法人代表
     */
    @ExcelProperty(value = "法人代表", index = 13)
    private String legalPerson;

    /**
     * 法人电话
     */
    @ExcelProperty(value = "法人电话", index = 14)
    private String legalPersonPhone;

    /**
     * 财务信息联系人
     */
    @ExcelProperty(value = "财务信息联系人", index = 15)
    private String financialContacts;

    /**
     * 财务信息联系电话
     */
    @ExcelProperty(value = "财务信息联系电话", index = 16)
    private String financialPhone;

    /**
     * 开票信息单位名称
     */
    @ExcelProperty(value = "开票信息单位名称", index = 17)
    private String invoiceCompany;

    /**
     * 开票信息税号
     */
    @ExcelProperty(value = "开票信息税号", index = 18)
    private String invoiceTaxCode;

    /**
     * 开票信息开户行
     */
    @ExcelProperty(value = "开票信息开户行", index = 19)
    private String invoiceBankName;

    /**
     * 开票信息行号
     */
    @ExcelProperty(value = "开票信息行号", index = 20)
    private String invoiceBankCode;

    /**
     * 开票信息账号
     */
    @ExcelProperty(value = "开票信息账号", index = 21)
    private String invoiceAccount;

    /**
     * 开票信息联系电话
     */
    @ExcelProperty(value = "开票信息联系电话", index = 22)
    private String invoicePhone;

    /**
     * 开票地址
     */
    @ExcelProperty(value = "开票地址", index = 23)
    private String invoiceAddress;

    /**
     * 办款资料单位名称
     */
    @ExcelProperty(value = "办款资料单位名称", index = 24)
    private String paymentCompany;

    /**
     * 办款资料开户行
     */
    @ExcelProperty(value = "办款资料开户行", index = 25)
    private String paymentBankName;

    /**
     * 办款资料行号
     */
    @ExcelProperty(value = "办款资料行号", index = 26)
    private String paymentBankCode;

    /**
     * 办款资料账号
     */
    @ExcelProperty(value = "办款资料账号", index = 27)
    private String paymentAccount;

    /**
     * 收件信息收件人
     */
    @ExcelProperty(value = "收件信息收件人", index = 28)
    private String recvName;

    /**
     * 收件信息联系电话
     */
    @ExcelProperty(value = "收件信息联系电话", index = 29)
    private String recvPhone;

    /**
     * 收件信息传真
     */
    @ExcelProperty(value = "收件信息传真", index = 30)
    private String recvFax;

    /**
     * 收件信息Email
     */
    @ExcelProperty(value = "收件信息Email", index = 31)
    private String recvEmail;

    /**
     * 收件信息地址
     */
    @ExcelProperty(value = "收件信息地址", index = 32)
    private String recvAddress;

    /**
     * 收件信息邮编
     */
    @ExcelProperty(value = "收件信息邮编", index = 33)
    private String recvPostcode;

    /**
     * 附件
     */
    @ExcelProperty(value = "附件", index = 34)
    private String attachment;

    /**
     * 启用
     */
    @ExcelProperty(value = "启用", index = 35,converter = IsEnabledConverter.class)
    private String isEnabled;

    /**
     * 备注
     */
    @ExcelProperty(value = "备注", index = 36)
    private String remark;

    /**
     * 创建人
     */
    @ExcelIgnore
    private String createBy;

    /**
     * 创建时间
     */
    @ExcelIgnore
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 修改人
     */
    @ExcelIgnore
    private String updateBy;

    /**
     * 修改时间
     */
    @ExcelIgnore
    private LocalDateTime updateTime;

    /**
     * 版本
     */
    @ExcelProperty(value = "版本", index = 37)
    private Integer version;


}
