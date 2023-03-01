package com.zeroone.star.prepayment.entity;

import com.alibaba.excel.annotation.ExcelProperty;
import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.math.BigDecimal;
import java.time.LocalDate;
import java.time.LocalDateTime;

import com.zeroone.star.project.utils.easyExcel.converters.LocalDateConverter;
import com.zeroone.star.project.utils.easyExcel.converters.LocalDateTimeConverter;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 付款单
 * </p>
 *
 * @author zhd
 * @since 2023-02-18
 */
@Getter
@Setter
@TableName("fin_payment")
public class FinPayment implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * ID
     */
    @ExcelProperty("id")
    private String id;

    /**
     * 单据编号
     */
    @ExcelProperty("bill_no")
    private String billNo;

    /**
     * 单据日期
     */
    @ExcelProperty(value = "bill_date", converter = LocalDateConverter.class)
    private LocalDate billDate;

    /**
     * 源单类型
     */
    @ExcelProperty("src_bill_type")
    private String srcBillType;

    /**
     * 源单id
     */
    @ExcelProperty("src_bill_id")
    private String srcBillId;

    /**
     * 源单号
     */
    @ExcelProperty("src_no")
    private String srcNo;

    /**
     * 单据主题
     */
    @ExcelProperty("subject")
    private String subject;

    /**
     * 是否红字
     */
    @ExcelProperty("is_rubric")
    private Integer isRubric;

    /**
     * 付款类型
     */
    @ExcelProperty("payment_type")
    private String paymentType;

    /**
     * 供应商
     */
    @ExcelProperty("supplier_id")
    private String supplierId;

    /**
     * 金额
     */
    @ExcelProperty("amt")
    private BigDecimal amt;

    /**
     * 已核销金额
     */
    @ExcelProperty("checked_amt")
    private BigDecimal checkedAmt;

    /**
     * 附件
     */
    @ExcelProperty("attachment")
    private String attachment;

    /**
     * 备注
     */
    @ExcelProperty("remark")
    private String remark;

    /**
     * 是否自动单据
     */
    @ExcelProperty("is_auto")
    private Integer isAuto;

    /**
     * 处理状态
     */
    @ExcelProperty("bill_stage")
    private String billStage;

    /**
     * 审核人
     */
    @ExcelProperty("approver")
    private String approver;

    /**
     * 流程
     */
    @ExcelProperty("bpmi_instance_id")
    private String bpmiInstanceId;

    /**
     * 核批结果类型
     */
    @ExcelProperty("approval_result_type")
    private String approvalResultType;

    /**
     * 核批意见
     */
    @ExcelProperty("approval_mark")
    private String approvalRemark;

    /**
     * 是否通过
     */
    @ExcelProperty("is_effective")
    private Integer isEffective;

    /**
     * 生效时间
     */
    @ExcelProperty("effective_time")
    @TableField(fill = FieldFill.UPDATE)
    private LocalDateTime effectiveTime;

    /**
     * 已关闭
     */
    @ExcelProperty("is_closed")
    private Integer isClosed;

    /**
     * 是否作废
     */
    @ExcelProperty("is_voided")
    private Boolean isVoided;

    /**
     * 创建时间
     */
    @ExcelProperty(value = "create_time", converter = LocalDateTimeConverter.class)
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 创建人
     */
    @ExcelProperty("create_by")
    private String createBy;

    /**
     * 创建部门
     */
    @ExcelProperty("sys_org_code")
    private String sysOrgCode;

    /**
     * 修改时间
     */
    @TableField(fill = FieldFill.UPDATE)
    @ExcelProperty(value = "update_time", converter = LocalDateTimeConverter.class)
    private LocalDateTime updateTime;

    /**
     * 修改人
     */
    @ExcelProperty("update_by")
    private String updateBy;

    /**
     * 版本
     */
    @ExcelProperty("version")
    private Integer version;


}
