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
    @ExcelProperty(value = "名称", index = 1)
    /**
     * 名称
     */
    private String name;
    @ExcelProperty(value = "简称", index = 2)
    /**
     * 简称
     */
    private String shortName;
    @ExcelProperty(value = "助记名", index = 3)
    /**
     * 助记名
     */
    private String auxName;
    @ExcelProperty(value = "客户分类", index = 4)
    /**
     * 客户分类
     */
    private String customerCategory;
    @ExcelProperty(value = "客户等级", index = 5)
    /**
     * 客户等级
     */
    private String customerLevel;
    @ExcelProperty(value = "纳税规模", index = 6)
    /**
     * 纳税规模
     */
    private String taxScale;
    @ExcelProperty(value = "欠款额度", index = 7)
    /**
     * 欠款额度
     */
    private BigDecimal creditQuota;
    @ExcelProperty(value = "所属总公司", index = 8)
    /**
     * 所属总公司
     */
    private String headquarters;
    @ExcelProperty(value = "所属地区", index = 9)
    /**
     * 所属地区
     */
    private String area;
    @ExcelProperty(value = "业务区域", index = 10)
    /**
     * 业务区域
     */
    private String bizArea;
    @ExcelProperty(value = "客户地址", index = 11)
    /**
     * 客户地址
     */
    private String address;
    @ExcelProperty(value = "客户网站", index = 12)
    /**
     * 客户网站
     */
    private String website;
    @ExcelProperty(value = "法人代表", index = 13)
    /**
     * 法人代表
     */
    private String legalPerson;
    @ExcelProperty(value = "法人电话", index = 14)
    /**
     * 法人电话
     */
    private String legalPersonPhone;
    @ExcelProperty(value = "财务信息联系人", index = 15)
    /**
     * 财务信息联系人
     */
    private String financialContacts;
    @ExcelProperty(value = "财务信息联系电话", index = 16)
    /**
     * 财务信息联系电话
     */
    private String financialPhone;
    @ExcelProperty(value = "开票信息单位名称", index = 17)
    /**
     * 开票信息单位名称
     */
    private String invoiceCompany;
    @ExcelProperty(value = "开票信息税号", index = 18)
    /**
     * 开票信息税号
     */
    private String invoiceTaxCode;
    @ExcelProperty(value = "开票信息开户行", index = 19)
    /**
     * 开票信息开户行
     */
    private String invoiceBankName;
    @ExcelProperty(value = "开票信息行号", index = 20)
    /**
     * 开票信息行号
     */
    private String invoiceBankCode;
    @ExcelProperty(value = "开票信息账号", index = 21)
    /**
     * 开票信息账号
     */
    private String invoiceAccount;
    @ExcelProperty(value = "开票信息联系电话", index = 22)
    /**
     * 开票信息联系电话
     */
    private String invoicePhone;
    @ExcelProperty(value = "开票地址", index = 23)
    /**
     * 开票地址
     */
    private String invoiceAddress;
    @ExcelProperty(value = "办款资料单位名称", index = 24)
    /**
     * 办款资料单位名称
     */
    private String paymentCompany;
    @ExcelProperty(value = "办款资料开户行", index = 25)
    /**
     * 办款资料开户行
     */
    private String paymentBankName;
    @ExcelProperty(value = "办款资料行号", index = 26)
    /**
     * 办款资料行号
     */
    private String paymentBankCode;
    @ExcelProperty(value = "办款资料账号", index = 27)
    /**
     * 办款资料账号
     */
    private String paymentAccount;
    @ExcelProperty(value = "收件信息收件人", index = 28)
    /**
     * 收件信息收件人
     */
    private String recvName;
    @ExcelProperty(value = "收件信息联系电话", index = 29)
    /**
     * 收件信息联系电话
     */
    private String recvPhone;
    @ExcelProperty(value = "收件信息传真", index = 30)
    /**
     * 收件信息传真
     */
    private String recvFax;
    @ExcelProperty(value = "收件信息Email", index = 31)
    /**
     * 收件信息Email
     */
    private String recvEmail;
    @ExcelProperty(value = "收件信息地址", index = 32)
    /**
     * 收件信息地址
     */
    private String recvAddress;
    @ExcelProperty(value = "收件信息邮编", index = 33)
    /**
     * 收件信息邮编
     */
    private String recvPostcode;
    @ExcelProperty(value = "附件", index = 34)
    /**
     * 附件
     */
    private String attachment;
    @ExcelProperty(value = "启用", index = 35,converter = IsEnabledConverter.class)
    /**
     * 启用
     */
    private String isEnabled;
    @ExcelProperty(value = "备注", index = 36)
    /**
     * 备注
     */
    private String remark;
    @ExcelIgnore
    /**
     * 创建人
     */
    private String createBy;
    @ExcelIgnore
    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;
    @ExcelIgnore
    /**
     * 修改人
     */
    private String updateBy;
    @ExcelIgnore
    /**
     * 修改时间
     */
    private LocalDateTime updateTime;
    @ExcelProperty(value = "版本", index = 37)
    /**
     * 版本
     */
    private Integer version;


}
