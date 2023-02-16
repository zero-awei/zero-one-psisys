package com.zeroone.star.project.query.payable;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.util.Date;

/**
 * @author spk
 * @since 2023-02-13 08:43
 * @description 应付核销上的Query。在应付核销页面查询按钮左侧和上侧用到的字段。
 */
@Data
@ApiModel("应付核销单自定义查询")
public class FinPayableCheckListAdvancedQuery {
    // ---展开前---

    /**
     * 单据编号
     */
    @ApiModelProperty(value = "单据编号", example = "YFHX-230209-009")
    private String billNo;

    /**
     * 单据起始日期
     * billDate_begin
     */
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss",timezone="GMT+8")
    @ApiModelProperty(value = "单据起始日期", example = "2023-02-07")
    private Date billDateBegin;

    /**
     * 单据终止日期
     * billDate_end
     */
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss",timezone="GMT+8")
    @ApiModelProperty(value = "单据终止日期", example = "2023-02-07")
    private Date billDateEnd;


    // ---展开后---

    /**
     * 单据主题
     */
    @ApiModelProperty(value = "单据主题", example = "3333333333")
    private String subject;

    /**
     * 供应商
     */
    @ApiModelProperty(value = "供应商", example = "1623284221748748290")
    private String supplierId;

    /**
     * 单据阶段
     */
    @ApiModelProperty(value = "单据阶段", example = "34")
    private String billStage;

    /**
     * 已生效
     */
    @ApiModelProperty(value = "已生效", example = "1")
    private Integer isEffective;


    /**
     * 已关闭
     */
    @ApiModelProperty(value = "已关闭", example = "1")
    private Integer isClosed;


    /**
     * 已作废
     */
    @ApiModelProperty(value = "已作废", example = "0")
    private Integer isVoided;
}
