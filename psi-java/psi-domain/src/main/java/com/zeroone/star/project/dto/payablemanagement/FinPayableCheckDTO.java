package com.zeroone.star.project.dto.payablemanagement;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.math.BigDecimal;
import java.util.Date;

/**
 * @author spk
 * @since 2023-02-13 08:22
 * @description 应付核销单DTO。
 * 看了一下entity的字段，和VO一样，所以直接copy自VO。
 */
@Data
@ApiModel("应付核销单数据传输对象")
public class FinPayableCheckDTO {
    @ApiModelProperty(value = "核销金额", example = "202")
    private BigDecimal amt;

    @ApiModelProperty(value = "核批意见", example = "")
    private String approvalRemark;

    @ApiModelProperty(value = "核批结果", example = "1")
    private String approvalResultType;

    @ApiModelProperty(value = "核批人", example = "psi")
    private String approver;

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

    @ApiModelProperty(value = "流程id", example = "")
    private String bpmiInstanceId;

    @ApiModelProperty(value = "制单人", example = "psi")
    private String createBy;

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

    @ApiModelProperty(value = "已关闭", example = "1")
    private Integer isClosed;

    @ApiModelProperty(value = "已生效", example = "1")
    private Integer isEffective;

    @ApiModelProperty(value = "红字单据", example = "0")
    private Integer isRubric;

    @ApiModelProperty(value = "已作废", example = "0")
    private Integer isVoided;

    @ApiModelProperty(value = "核销类型", example = "2")
    private String payableCheckType;

    @ApiModelProperty(value = "备注", example = "")
    private String remark;

    @ApiModelProperty(value = "源单id", example = "")
    private String srcBillId;

    @ApiModelProperty(value = "源单类型", example = "")
    private String srcBillType;

    @ApiModelProperty(value = "源单号", example = "")
    private String srcNo;

    @ApiModelProperty(value = "单据主题", example = "3333333333")
    private String subject;

    @ApiModelProperty(value = "供应商", example = "1623284221748748290")
    private String supplierId;

    @ApiModelProperty(value = "制单部门", example = "A01A05")
    private String sysOrgCode;

    @ApiModelProperty(value = "修改人", example = "psi")
    private String updateBy;

    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss",timezone="GMT+8")
    @ApiModelProperty(value = "修改时间", example = "2023-02-09 03:27:18")
    private Date updateTime;

    @ApiModelProperty(value = "版本", example = "")
    private Integer version;
}
