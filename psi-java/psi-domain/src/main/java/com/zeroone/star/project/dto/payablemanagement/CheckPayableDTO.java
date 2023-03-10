package com.zeroone.star.project.dto.payablemanagement;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.format.annotation.DateTimeFormat;

import java.math.BigDecimal;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.List;

/**
 * @author spk
 * @description 应付核销单DTO。 加入所有的 DictText
 * @since 2023-02-14
 */
@Data
@ApiModel("应付核销单数据传输对象")
@AllArgsConstructor
@NoArgsConstructor
public class CheckPayableDTO {

    @ApiModelProperty(value = "核销金额", example = "202")
    private BigDecimal amt;

    @ApiModelProperty(value = "核批意见")
    private String approvalRemark;

    @ApiModelProperty(value = "核批结果 1-审核通过 2-审核不通过", example = "1")
    private String approvalResultType;


    @ApiModelProperty(value = "核批人（后端自动生成）", example = "psi")
    private String approver;


    @ApiModelProperty(value = "附件（文件下载地址）")
    private String attachment;

    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @JsonFormat(pattern = "yyyy-MM-dd", timezone = "GMT+8")
    @ApiModelProperty(value = "单据日期", example = "2023-02-07")
    private LocalDate billDate;

    @ApiModelProperty(value = "单据编号", example = "YFHX-230209-009")
    private String billNo;

    @ApiModelProperty(value = "单据阶段 1-编制中 2-编制完 3-执行完 4-核批完", example = "1")
    private String billStage;


    /* 既不在网页上出现，也不在数据库中出现
     * billType: "FinPayableCheck:2"
     */
    @ApiModelProperty(value = "账单类型", example = "FinPayableCheck:2")
    private String billType;


    @ApiModelProperty(value = "流程id")
    private String bpmiInstanceId;

    @ApiModelProperty(value = "创建人（后端自动生成）", example = "psi")
    private String createBy;


    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss", timezone = "GMT+8")
    @ApiModelProperty(value = "创建时间（后端自动生成）", example = "2023-02-09 02:20:36")
    private LocalDateTime createTime;

    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss", timezone = "GMT+8")
    @ApiModelProperty(value = "生效时间（后端自动生成）", example = "2023-02-09 03:27:18")
    private LocalDateTime effectiveTime;

    @ApiModelProperty(value = "ID", example = "1623386325943361538")
    private String id;

    @ApiModelProperty(value = "是否为自动单据 0-否 1-是", example = "0")
    private Integer isAuto;


    @ApiModelProperty(value = "已关闭 0-未关闭 1-已关闭", example = "1")
    private Integer isClosed;


    @ApiModelProperty(value = "已生效 0-未生效 1-已生效", example = "1")
    private Integer isEffective;


    @ApiModelProperty(value = "是否为红字单据 0-否 1-是", example = "0")
    private Integer isRubric;


    @ApiModelProperty(value = "已作废 0-未作废 1-已作废", example = "0")
    private Integer isVoided;

    @ApiModelProperty(value = "核销类型", example = "2")
    private String payableCheckType;

    @ApiModelProperty(value = "备注")
    private String remark;

    @ApiModelProperty(value = "源单id")
    private String srcBillId;

    @ApiModelProperty(value = "源单类型")
    private String srcBillType;

    @ApiModelProperty(value = "源单号")
    private String srcNo;

    @ApiModelProperty(value = "单据主题", example = "3333333333")
    private String subject;

    @ApiModelProperty(value = "供应商id", example = "1623284221748748290")
    private String supplierId;

    @ApiModelProperty(value = "制单部门", example = "A01A05")
    private String sysOrgCode;

    @ApiModelProperty(value = "修改人（后端自动生成）", example = "psi")
    private String updateBy;


    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss", timezone = "GMT+8")
    @ApiModelProperty(value = "修改时间（后端自动生成）", example = "2023-02-09 03:27:18")
    private LocalDateTime updateTime;

    @ApiModelProperty(value = "版本")
    private Integer version;

    @ApiModelProperty(value = "往来核销明细")
    private List<CheckPayableEntryDTO> checkPayableEntryList;

}
