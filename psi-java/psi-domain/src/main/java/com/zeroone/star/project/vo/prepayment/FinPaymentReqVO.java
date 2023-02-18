package com.zeroone.star.project.vo.prepayment;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;

import java.math.BigDecimal;
import java.sql.Date;

/**
 * <p>
 * 付款申请单明细
 * </p>
 *
 * @author Kong
 * @since 2023-02-11
 */
@Data
@ApiModel("采购明细对象")
public class FinPaymentReqVO {
//jeecg_row_key
    /**
     * id
     */
    @ApiModelProperty(value = "id",example = "1594317750844637186")
    private String id;

    /**
     * 单据号
     */
    @ApiModelProperty(value = "单据编号",example = "CGYFSQ-221120-001")
    private String billNo;

    /**
     * 单据日期
     */
    @ApiModelProperty(value = "单据日期",example = "2022-11-20")
    private Date billDate;

    /**
     * 付款类型
     */
    @ApiModelProperty(value = "付款类型",example = "2011")
    private Integer paymentType;

    /**
     * 已关闭
     */
    @ApiModelProperty(value = "已关闭",example = "1")
    private Integer isClosed;

    @ApiModelProperty(value = "操作部门",example = "A01A03")
    private String opDept;

    /**
     * 业务员
     */
    @ApiModelProperty(value = "业务员",example = "zhagnxiao")
    private String operator;

    /**
     * 供应商
     */
    @ApiModelProperty(value = "供应商",example = "1584950950470164481")
    private String supplierId;

    /**
     * 含税金额
     */
    @ApiModelProperty(value = "申请金额",example = "1000.00")
    private BigDecimal amt;

    /**
     * 含税金额
     */
    @ApiModelProperty(value = "已付金额",example = "1000.00")
    private BigDecimal paidAmount;

    /**
     * 备注
     */
    @ApiModelProperty(value = "备注",example = "备注")
    private String remark;

}
