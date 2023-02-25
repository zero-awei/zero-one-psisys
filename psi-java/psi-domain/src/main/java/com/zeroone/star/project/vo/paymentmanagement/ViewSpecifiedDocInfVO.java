package com.zeroone.star.project.vo.paymentmanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;

@Data
@ApiModel("查询指点单据信息")
public class ViewSpecifiedDocInfVO  {

    /**
     * ID
     */
    @ApiModelProperty(value = "ID",example = "1628749388070559746")
    private String id;

    /**
     * 主表
     */
    @ApiModelProperty(value = "主表",example = "1628749387961507842")
    private String mid;

    /**
     * 单据编号
     */
    @ApiModelProperty(value = "单据编号",example = "CGYF-230223-016")
    private String billNo;

    /**
     * 分录号
     */
    @ApiModelProperty(value = "分录号",example = "10")
    private Integer entryNo;

    /**
     * 源单类型
     */
    @ApiModelProperty(value = "源单类型",example = "FinPaymentReq:2011")
    private String srcBillType;

    /**
     * srcBillId
     */
    @ApiModelProperty(value = "源单号",example = "1628749388070559746")
    private String srcBillId;

    /**
     * 源单分录id
     */
    @ApiModelProperty(value = "源单号",example = "null")
    private String srcEntryId;

    /**
     * 源单分录号
     */
    @ApiModelProperty(value = "源单分录号",example = "CGYF-230223-001")
    private String srcNo;

    /**
     * 申请金额
     */
    @ApiModelProperty(value = "申请金额",example = "10")
    private BigDecimal amt;

    /**
     * 已付金额
     */

    @ApiModelProperty(value = "已付金额",example = "10")
    private BigDecimal paidAmt;

    /**
     * 备注
     */

    @ApiModelProperty(value = "备注",example = "")
    private String remark;

    /**
     * 自定义1
     */
    private String custom1;

    /**
     * 自定义2
     */
    private String custom2;


}
