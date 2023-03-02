package com.zeroone.star.project.vo.paymentmanagement;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;
import java.util.Date;

/**
 * @author 白也
 * @title
 * @date 2023/2/24 6:03 下午
 */
@ApiModel(description = "")
@Data
public class StkIoVO extends PageQuery {
    /**
     * 单据编号
     */
    @ApiModelProperty("单据编号")
    private String billNo;
    /**
     * 单据日期
     */
    @ApiModelProperty("单据日期")
    private Date billDate;
    /**
     *单据主题
     */
    @ApiModelProperty("单据主题")
    private String subject;
    /**
     * 出入库类型
     */
    @ApiModelProperty("出入库类型")
    private String itemText;
    /**
     * 源单号
     */
    @ApiModelProperty("源单号")
    private String srcNo;
    /**
     * 供应商
     */
    @ApiModelProperty("供应商")
    private String name;
    /**
     * 业务部门
     */
    @ApiModelProperty("业务部门")
    private String departName;

    /**
     * 业务员
     */
    @ApiModelProperty("业务员")
    private String operator;

    /**
     * 结算金额
     */
    @ApiModelProperty("结算金额")
    private BigDecimal settleAmt;

    /**
     * 已结算金额
     */
    @ApiModelProperty("已结算金额")
    private BigDecimal settledAmt;

    /**
     * 已开票金额
     */
    @ApiModelProperty("已开票金额")
    private BigDecimal invoicedAmt;

    /**
     * 发票类型
     */
    @ApiModelProperty("发票类型")
    private String invoiceType;

    /**
     * 是否有涨吨
     */
    @ApiModelProperty("是否有涨吨")
    private Integer hasSwell;

    /**
     * 已关闭
     */
    @ApiModelProperty("已关闭")
    private Integer isClosed;

}
