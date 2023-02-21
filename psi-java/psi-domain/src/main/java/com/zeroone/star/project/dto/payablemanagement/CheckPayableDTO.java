package com.zeroone.star.project.dto.payablemanagement;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.math.BigDecimal;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.List;

/**
 * @author The end
 * @date 2023/2/15
 */
@Data
@ApiModel("应付核销单")
public class CheckPayableDTO {

    /**
     * 单据编号
     */
    @ApiModelProperty(value = "单据编号", example = "YFHX-221110-001")
    private String billNo;

    /**
     * 单据日期
     */
    @ApiModelProperty(value = "单据日期", example = "2022-12-14")
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @JsonFormat(pattern = "yyyy-MM-dd", timezone = "GMT+8")
    private LocalDate billDate;

    /**
     * 源单类型
     */
    @ApiModelProperty(value = "源单类型", example = "FinPayment:2020", allowEmptyValue = true)
    private String srcBillType;

    /**
     * 源单id
     */
    @ApiModelProperty(value = "源单id", example = "1590727821862420481", allowEmptyValue = true)
    private String srcBillId;

    /**
     * 源单号
     */
    @ApiModelProperty(value = "源单号", example = "CGFK-221110-001", allowEmptyValue = true)
    private String srcNo;


    /**
     * 是否红字
     */
    @ApiModelProperty(value = "是否红字", example = "0")
    private Integer isRubric;

    /**
     * 核销类型
     */
    @ApiModelProperty(value = "核销类型", example = "2")
    private String payableCheckType;

    /**
     * 供应商id
     */
    @ApiModelProperty(value = "供应商id", example = "1584950950470164481", allowEmptyValue = true)
    private String supplierId;

    /**
     * 核销金额
     */
    @ApiModelProperty(value = "核销金额", example = "14200.00")
    private BigDecimal amt;

    /**
     * 附件
     */
    @ApiModelProperty(value = "附件", allowEmptyValue = true)
    private String attachment;

    /**
     * 备注
     */
    @ApiModelProperty(value = "备注", allowEmptyValue = true)
    private String remark;

    /**
     * 是否自动生成
     */
    @ApiModelProperty(value = "是否自动生成", example = "1")
    private Integer isAuto;

    /**
     * 处理状态
     */
    @ApiModelProperty(value = "处理状态", example = "34")
    private String billStage;

    /**
     * 审核人
     */
    @ApiModelProperty(value = "审核人", example = "admin", allowEmptyValue = true)
    private String approver;

    /**
     * 流程id
     */
    @ApiModelProperty(value = "流程id", allowEmptyValue = true)
    private String bpmiInstanceId;

    /**
     * 核批结果类型
     */
    @ApiModelProperty(value = "核批结果类型", example = "1", allowEmptyValue = true)
    private String approvalResultType;

    /**
     * 核批意见
     */
    @ApiModelProperty(value = "核批意见", allowEmptyValue = true)
    private String approvalRemark;

    /**
     * 是否通过
     */
    @ApiModelProperty(value = "是否通过", example = "1")
    private Boolean isEffective;

    /**
     * 生效时间
     */
    @ApiModelProperty(value = "生效时间", example = "2022-12-14 21:30:34", allowEmptyValue = true)
    private LocalDateTime effectiveTime;

    /**
     * 是否已关闭
     */
    @ApiModelProperty(value = "是否已关闭", example = "1")
    private Integer isClosed;

    /**
     * 是否作废
     */
    @ApiModelProperty(value = "是否作废", example = "0")
    private Boolean isVoided;

    @ApiModelProperty(value = "往来核销明细")
    private List<CheckPayableEntryDTO> checkPayableEntryList;


}
