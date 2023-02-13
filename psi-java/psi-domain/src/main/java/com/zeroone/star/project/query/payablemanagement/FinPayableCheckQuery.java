package com.zeroone.star.project.query.payablemanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.Date;

/**
 * @author spk
 * @since 2023-02-13 08:43
 * @description 应付核销单Query。查询按钮左侧和上侧用到的字段。
 * TODO 是否需要区分展开前和展开后？先暂时不做区分
 * 因为已经包括了供应商，所以根据供应商查询应付单就不做了
 */
@Data
@ApiModel("应付核销单查询")
public class FinPayableCheckQuery {
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
    @ApiModelProperty(value = "单据起始日期", example = "2023-02-07")
    private Date billDateBegin;

    /**
     * 单据终止日期
     * billDate_end
     */
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
