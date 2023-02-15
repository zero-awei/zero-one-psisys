package com.zeroone.star.project.vo.payment;

<<<<<<< HEAD
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;
import java.time.LocalDate;

/**
 * @ClassName finPaymentReqVO
 * @Description 采购预付申请单对象
 * @Author HZP
 * @Date 2023/2/12 15:54
 * @Version 1.0
 **/
@Data
@ApiModel("采购预付申请单对象")
public class FinPaymentReqVO {
    /**
     * 单据编号
     */
    @ApiModelProperty(value = "单据编号",example = "CGFKSQ-230211-004")
=======
import io.swagger.annotations.ApiModelProperty;
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
@Getter
@Setter
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
>>>>>>> j4-payment-KONG
    private String billNo;

    /**
     * 单据日期
     */
<<<<<<< HEAD
    @ApiModelProperty(value = "单据日期",example = "2023-02-11")
    private LocalDate billDate;

    /**
     * 单据主题
     */
    @ApiModelProperty(value = "单据主题",example = "")
    private String subject;

    /**
     * 申请金额
     */
    @ApiModelProperty(value = "申请金额",example = "90000")
    private BigDecimal amt;

    /**
     * 已付金额
     */
    @ApiModelProperty(value = "已付金额",example = "0")
    private BigDecimal paidAmt;

    /**
     * 备注
     */
    @ApiModelProperty(value = "备注",example = "")
    private String remark;
}
=======
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
    @ApiModelProperty(value = "含税金额",example = "1000.00")
    private BigDecimal amt;

    /**
     * 备注
     */
    @ApiModelProperty(value = "备注",example = "备注")
    private String remark;

}
>>>>>>> j4-payment-KONG
