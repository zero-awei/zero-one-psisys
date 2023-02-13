package com.zeroone.star.project.vo.payablemanagement;

import io.swagger.annotations.Api;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;

/**
 * @author spk
 * @since 2023-02-13 09:11
 * @description 应付核销单明细VO。
 * ApiModelProperty value 以网页显示内容为准，没有则用以数据库备注。
 */
@Data
@ApiModel("应付核销单明细显示对象")
public class FinPayableCheckEntryVO {

    @ApiModelProperty(value = "ID", example = "1623386325955944449")
    private String id;

    /**
     * 主表
     */
    @ApiModelProperty(value = "主表", example = "1623386325943361538")
    private String mid;

    /**
     * 单据编号
     */
    @ApiModelProperty(value = "单据编号", example = "YFHX-230209-009")
    private String billNo;

    /**
     * 分录号
     */
    @ApiModelProperty(value = "分录号", example = "101")
    private Integer entryNo;

    /**
     * 源单类型
     */
    @ApiModelProperty(value = "源单类型", example = "FinPayable:299")
    private String srcBillType;

    /**
     * 源单id
     */
    @ApiModelProperty(value = "源单ID", example = "1623342154423508993")
    private String srcBillId;

    /**
     * 源单分录id
     */
    @ApiModelProperty(value = "源单分录ID", example = "")
    private String srcEntryId;

    /**
     * 源单号
     */
    @ApiModelProperty(value = "源单号", example = "QTAP-230208-016")
    private String srcNo;

    /**
     * 核销方向
     * 1 为核销明细-应付
     * 2 为核销明细-
     */
    @ApiModelProperty(value = "核销方向", example = "1")
    private String checkSide;

    /**
     * 核销金额
     */
    @ApiModelProperty(value = "核销金额", example = "202")
    private BigDecimal amt;

    /**
     * 备注
     */
    @ApiModelProperty(value = "备注", example = "")
    private String remark;

    /**
     * 自定义1
     */
    @ApiModelProperty(value = "自定义1", example = "")
    private String custom1;

    /**
     * 自定义2
     */
    @ApiModelProperty(value = "自定义2", example = "")
    private String custom2;

    /**
     * 版本
     */
    @ApiModelProperty(value = "版本", example = "")
    private Integer version;

    /**
     * TODO 未核销金额
     * 在数据库中找不到
     */
    @ApiModelProperty(value = "未核销金额", example = "0")
    private BigDecimal uncheckedAmt;


}
