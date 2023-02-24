package com.zeroone.star.project.vo.payablemanagement;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.*;
import org.springframework.format.annotation.DateTimeFormat;

import java.math.BigDecimal;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.Date;


/**
 * @author spk
 * @since 2023-02-14
 * @description 应付核销单VO: fin_payable_check
 * ApiModelProperty value 以网页上显示的名称为准，如果没有则使用数据库名称
 * 相比于DTO，缺少以下字段：
 * 所有的Id字段
 * 对于拥有DictText字段和原字段两者的，只保留DictText字段
 * version
 */
@Data
@ApiModel("应付核销单显示对象")
public class CheckPayableVO {

    @ApiModelProperty(value = "核销金额", example = "202")
    private BigDecimal amt;

    @ApiModelProperty(value = "核批意见", example = "")
    private String approvalRemark;

    @ApiModelProperty(value = "核批结果", example = "通过")
    private String approvalResultTypeDictText;

    @ApiModelProperty(value = "核批人", example = "管理员")
    private String approverDictText;

    @ApiModelProperty(value = "附件", example = "")
    private String attachment;

    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @JsonFormat
    @ApiModelProperty(value = "单据日期", example = "2023-02-07")
    private LocalDate billDate;

    @ApiModelProperty(value = "单据编号", example = "YFHX-230209-009")
    private String billNo;

    @ApiModelProperty(value = "单据阶段", example = "执行中")
    private String billStageDictText;

    /* 既不在网页上出现，也不在数据库中出现
     * billType: "FinPayableCheck:2"
     */
//    @ApiModelProperty(value = "账单类型", example = "FinPayableCheck:2")
//    private String billType;

//    @ApiModelProperty(value = "流程id", example = "")
//    private String bpmiInstanceId;

    @ApiModelProperty(value = "制单人", example = "管理员")
    private String createByDictText;

    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @JsonFormat
    @ApiModelProperty(value = "制单时间", example = "2023-02-09 02:20:36")
    private LocalDateTime createTime;

    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @JsonFormat
    @ApiModelProperty(value = "生效时间", example = "2023-02-09 03:27:18")
    private LocalDateTime effectiveTime;

    @ApiModelProperty(value = "ID", example = "1623386325943361538")
    private String id;

    @ApiModelProperty(value = "自动单据", example = "否")
    private String isAutoDictText;

    @ApiModelProperty(value = "已关闭", example = "是")
    private String isClosedDictText;

    @ApiModelProperty(value = "已生效", example = "是")
    private String isEffectiveDictText;

    @ApiModelProperty(value = "红字单据", example = "否")
    private String isRubricDictText;

    @ApiModelProperty(value = "已作废", example = "否")
    private String isVoidedDictText;

    @ApiModelProperty(value = "核销类型", example = "应付核销")
    private String payableCheckTypeDictText;

    @ApiModelProperty(value = "备注", example = "")
    private String remark;

//    @ApiModelProperty(value = "源单id", example = "")
//    private String srcBillId;

    @ApiModelProperty(value = "源单类型", example = "")
    private String srcBillTypeDictText;
    @ApiModelProperty(value = "源单号", example = "")
    private String srcNo;

    @ApiModelProperty(value = "单据主题", example = "3333333333")
    private String subject;

    @ApiModelProperty(value = "供应商", example = "学而思教育")
    private String supplierIdDictText;

    @ApiModelProperty(value = "制单部门", example = "研发部")
    private String sysOrgCodeDictText;

    @ApiModelProperty(value = "修改人", example = "管理员")
    private String updateByDictText;

    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @JsonFormat
    @ApiModelProperty(value = "修改时间", example = "2023-02-09 03:27:18")
    private LocalDateTime updateTime;

//    @ApiModelProperty(value = "版本", example = "")
//    private Integer version;

}
