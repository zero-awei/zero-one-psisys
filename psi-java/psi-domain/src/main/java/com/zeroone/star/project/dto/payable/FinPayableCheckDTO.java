package com.zeroone.star.project.dto.payable;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.format.annotation.DateTimeFormat;

import java.math.BigDecimal;
import java.util.Date;

/**
 * @author spk
 * @since 2023-02-14
 * @description 应付核销单DTO。
 * 加入所有的 DictText
 */
@Data
@ApiModel("应付核销单数据传输对象")
@AllArgsConstructor
@NoArgsConstructor
public class FinPayableCheckDTO {
    @ApiModelProperty(value = "核销金额", example = "202")
    private BigDecimal amt;

    @ApiModelProperty(value = "核批意见", example = "")
    private String approvalRemark;

    @ApiModelProperty(value = "核批结果", example = "1")
    private String approvalResultType;

    @ApiModelProperty(value = "核批结果", example = "通过")
    private String approvalResultTypeDictText;

    @ApiModelProperty(value = "核批人", example = "psi")
    private String approver;

    @ApiModelProperty(value = "核批人", example = "管理员")
    private String approverDictText;

    @ApiModelProperty(value = "附件", example = "")
    private String attachment;

    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss",timezone="GMT+8")
    @ApiModelProperty(value = "单据日期", example = "2023-02-07")
    private Date billDate;

    @ApiModelProperty(value = "单据编号", example = "YFHX-230209-009")
    private String billNo;

    @ApiModelProperty(value = "单据阶段", example = "34")
    private String billStage;

    @ApiModelProperty(value = "单据阶段", example = "执行中")
    private String billStageDictText;

    /* 既不在网页上出现，也不在数据库中出现
     * billType: "FinPayableCheck:2"
     */
    @ApiModelProperty(value = "账单类型", example = "FinPayableCheck:2")
    private String billType;


    @ApiModelProperty(value = "流程id", example = "")
    private String bpmiInstanceId;

    @ApiModelProperty(value = "制单人", example = "psi")
    private String createBy;

    @ApiModelProperty(value = "制单人", example = "管理员")
    private String createByDictText;

    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss",timezone="GMT+8")
    @ApiModelProperty(value = "制单时间", example = "2023-02-09 02:20:36")
    private Date createTime;

    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss",timezone="GMT+8")
    @ApiModelProperty(value = "生效时间", example = "2023-02-09 03:27:18")
    private Date effectiveTime;

    @ApiModelProperty(value = "ID", example = "1623386325943361538")
    private String id;

    @ApiModelProperty(value = "自动单据", example = "0")
    private Integer isAuto;

    @ApiModelProperty(value = "自动单据", example = "否")
    private Integer isAutoDictText;

    @ApiModelProperty(value = "已关闭", example = "1")
    private Integer isClosed;

    @ApiModelProperty(value = "已关闭", example = "是")
    private Integer isClosedDictText;

    @ApiModelProperty(value = "已生效", example = "1")
    private Integer isEffective;

    @ApiModelProperty(value = "已生效", example = "是")
    private Integer isEffectiveDictText;

    @ApiModelProperty(value = "红字单据", example = "0")
    private Integer isRubric;

    @ApiModelProperty(value = "红字单据", example = "否")
    private Integer isRubricDictText;

    @ApiModelProperty(value = "已作废", example = "0")
    private Integer isVoided;

    @ApiModelProperty(value = "已作废", example = "否")
    private Integer isVoidedDictText;

    @ApiModelProperty(value = "核销类型", example = "2")
    private String payableCheckType;

    @ApiModelProperty(value = "核销类型", example = "应付核销")
    private String payableCheckTypeDictText;

    @ApiModelProperty(value = "备注", example = "")
    private String remark;

    @ApiModelProperty(value = "源单id", example = "")
    private String srcBillId;

    @ApiModelProperty(value = "源单类型", example = "")
    private String srcBillType;

    @ApiModelProperty(value = "源单类型", example = "")
    private String srcBillTypeDictText;

    @ApiModelProperty(value = "源单号", example = "")
    private String srcNo;

    @ApiModelProperty(value = "单据主题", example = "3333333333")
    private String subject;

    @ApiModelProperty(value = "供应商", example = "1623284221748748290")
    private String supplierId;

    @ApiModelProperty(value = "供应商", example = "学而思教育")
    private String supplierIdDictText;

    @ApiModelProperty(value = "制单部门", example = "A01A05")
    private String sysOrgCode;

    @ApiModelProperty(value = "制单部门", example = "研发部")
    private String sysOrgCodeDictText;

    @ApiModelProperty(value = "修改人", example = "psi")
    private String updateBy;

    @ApiModelProperty(value = "修改人", example = "管理员")
    private String updateByDictText;

    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss",timezone="GMT+8")
    @ApiModelProperty(value = "修改时间", example = "2023-02-09 03:27:18")
    private Date updateTime;

    @ApiModelProperty(value = "版本", example = "")
    private Integer version;
}
