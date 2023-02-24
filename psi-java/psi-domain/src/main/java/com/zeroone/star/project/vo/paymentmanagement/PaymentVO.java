package com.zeroone.star.project.vo.paymentmanagement;


import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;
import java.time.LocalDateTime;

/**
 * @author spk
 * @since 2023-02-15
 * @description 应付核销-新增-根据供应商查血付款单 用到的付款显示对象VO
 * 从DTO修改，方式同FinPayableVO
 */
@ApiModel("付款显示对象")
@Data
public class PaymentVO {
    /**
     * ID
     */
//    @ApiModelProperty(value = "ID", example = "1624061659575525378")
//    private String id;

    /**
     * 单据编号
     */
    @ApiModelProperty(value = "单据编号", example = "CGYF-230210-041")
    private String billNo;

    /**
     * 单据日期
     */
    @ApiModelProperty(value = "单据日期", example = "2023-02-10")
    private LocalDateTime billDate;

    /**
     * 源单类型
     */
//    @ApiModelProperty(value = "源单类型", example = "")
//    private String srcBillType;

    @ApiModelProperty(value = "源单类型",example = "")
    private String srcBillTypeDictText;

    /**
     * 源单id
     */
//    @ApiModelProperty(value = "源单id", example = "")
//    private String srcBillId;

    /**
     * 源单号
     */
    @ApiModelProperty(value = "源单号", example = "")
    private String srcNo;

    /**
     * 单据主题
     */
    @ApiModelProperty(value = "单据主题", example = "")
    private String subject;

    /**
     * 是否红字
     */
//    @ApiModelProperty(value = "是否红字", example = "0")
//    private Integer isRubric;

    @ApiModelProperty(value = "是否红字", example = "否")
    private String isRubricDictText;

    /**
     * 付款类型
     */
//    @ApiModelProperty(value = "付款类型", example = "2011")
//    private String paymentType;

    @ApiModelProperty(value = "付款类型", example = "采购预付(有申请)")
    private String paymentTypeDictText;

    /**
     * 供应商
     */
//    @ApiModelProperty(value = "供应商", example = "1623573890197659650")
//    private String supplierId;

    @ApiModelProperty(value = "供应商", example = "光缆厂家1")
    private String supplierIdDicText;

    /**
     * 金额
     */
    @ApiModelProperty(value = "金额", example = "10000")
    private BigDecimal amt;

    /**
     * 已核销金额
     */
    @ApiModelProperty(value = "已核销金额", example = "0")
    private BigDecimal checkedAmt;

    /**
     * 未核销金额
     */
    @ApiModelProperty(value = "未核销金额", example = "10000")
    private BigDecimal uncheckedAmt;

    /**
     * 附件
     */
    @ApiModelProperty(value = "附件", example = "")
    private String attachment;

    /**
     * 备注
     */
    @ApiModelProperty(value = "备注", example = "")
    private String remark;

    /**
     * 是否自动生成
     */
//    @ApiModelProperty(value = "是否自动单据", example = "0")
//    private Integer isAuto;

    @ApiModelProperty(value = "是否自动单据", example = "否")
    private String isAutoDictText;

    /**
     * 处理状态
     */
//    @ApiModelProperty(value = "处理状态", example = "32")
//    private String billStage;

    @ApiModelProperty(value = "处理状态", example = "执行中")
    private String billStageDictText;

    /**
     * 审核人
     */
//    @ApiModelProperty(value = "审核人", example = "psi")
//    private String approver;

    @ApiModelProperty(value = "审核人", example = "管理员")
    private String approverDictText;

    /**
     * 流程id
     */
//    @ApiModelProperty(value = "流程id", example = "")
//    private String bpmiInstanceId;

    /**
     * 核批结果类型
     */
//    @ApiModelProperty(value = "核批结果类型", example = "1")
//    private String approvalResultType;

    @ApiModelProperty(value = "核批结果类型", example = "通过")
    private String approvalResultTypeDictText;


    /**
     * 核批意见
     */
    @ApiModelProperty(value = "核批意见")
    private String approvalRemark;

    /**
     * 是否通过
     */
//    @ApiModelProperty(value = "是否通过", example = "1")
//    private Integer isEffective;

    @ApiModelProperty(value = "是否通过", example = "是")
    private String isEffectiveDictText;

    /**
     * 生效时间
     */
    @ApiModelProperty(value = "生效时间", example = "2023-02-10 23:04:35")
    private LocalDateTime effectiveTime;

    /**
     * 已关闭
     */
//    @ApiModelProperty(value = "已关闭", example = "0")
//    private Integer isClosed;

    @ApiModelProperty(value = "已关闭", example = "否")
    private String isClosedDictText;

    /**
     * 是否作废
     */
//    @ApiModelProperty(value = "是否作废", example = "0")
//    private Integer isVoided;

    @ApiModelProperty(value = "是否作废", example = "否")
    private String isVoidedDictText;

    /**
     * 创建部门
     */
//    @ApiModelProperty(value = "创建部门", example = "A01A05")
//    private String sysOrgCode;

    @ApiModelProperty(value = "创建部门", example = "研发部")
    private String sysOrgCodeDictText;

    /**
     * 创建人
     */
//    @ApiModelProperty(value = "创建人", example = "psi")
//    private String createBy;

    @ApiModelProperty(value = "创建人", example = "管理员")
    private String createByDictText;

    /**
     * 创建时间
     */
    @ApiModelProperty(value = "创建时间", example = "2023-02-10 23:04:08")
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 修改人
     */
//    @ApiModelProperty(value = "修改人", example = "psi")
//    private String updateBy;

    @ApiModelProperty(value = "修改人", example = "管理员")
    private String updateByDictText;

    /**
     * 修改时间
     */
    @ApiModelProperty(value = "修改时间", example = "2023-02-10 23:05:13")
    private LocalDateTime updateTime;

    /**
     * 版本
     */
//    @ApiModelProperty(value = "版本")
//    private Integer version;
}
