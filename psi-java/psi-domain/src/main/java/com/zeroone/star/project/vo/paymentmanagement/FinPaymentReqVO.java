package com.zeroone.star.project.vo.paymentmanagement;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;
import java.time.LocalDate;

/**
 * @author 白也
 * @title 付款申请单据列表
 * @date 2023/2/15 8:22 下午
 */

@ApiModel(description = "")
@Data
public class FinPaymentReqVO extends PageQuery {
    /**
     * 单据编号
     */
    @ApiModelProperty("单据编号")
    private String billNo;
    /**
     * 单据日期
     */
    @ApiModelProperty("单据日期")
    private LocalDate billDate;
    /**
     * 单据主题
     */
    @ApiModelProperty("单据主题")
    private String subject;
    /**
     * 付款类型
     */
    @ApiModelProperty("付款类型")
    private String paymentType;
    /**
     * 供应商
     */
    @ApiModelProperty("供应商")
    private String supplierId;
    /**
     * 业务部门
     */
    @ApiModelProperty("业务部门")
    private String opDept;
    /**
     * 业务员
     */
    @ApiModelProperty("业务员")
    private String operator;
    /**
     * 申请金额
     */
    @ApiModelProperty("申请金额")
    private BigDecimal amt;
    /**
     * 已付金额
     */
    @ApiModelProperty("已付金额")
    private BigDecimal paidAmt;
    /**
     * 备注
     */
    @ApiModelProperty("备注")
    private String remark;
    /**
     * 已关闭
     */
    @ApiModelProperty("已关闭")
    private Integer isClosed;
}
