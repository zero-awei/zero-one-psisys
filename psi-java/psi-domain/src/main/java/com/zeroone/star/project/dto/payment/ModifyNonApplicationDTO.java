package com.zeroone.star.project.dto.payment;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.math.BigDecimal;
import java.time.LocalDate;

/**
 * <p>
 * 描述：查询对象——修改功能（有申请）
 * 数据库表：付款单fin_payment、付款单明细fin_payment_entry
 * 查询字段：是否需要输入修改时间和修改人？？
 * --------------------fin_payment---------------------------
 *      ID：private String id;
 *      备注：private String remark;
 *      单据日期：private LocalDate billDate;
 *      供应商：private String supplierId;
 *      附件：private String attachment;
 *      单据主题：private String subject;
 *      金额：private BigDecimal amt;
 * ---------------pur_order---------------------
 * ---------------pur_order_entry---------------------
 *      源单id：private String srcBillId;
 *      分录号：private Integer entryNo;
 *      结算方式：private String settleMethod;
 *      资金账户：private String bankAccountId;
 *      金额：private BigDecimal amt;
 *      备注：private String remark;
 *      自定义1：private String custom1;
 *      自定义2：private String custom2;
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author forever爱
 * @version 1.0.0
 */
@Data
@ApiModel("查询对象")
public class ModifyNonApplicationDTO {
    //    fin_payment
    @ApiModelProperty(value = "ID",example = "1590727821862420481")
    private String id;
    @ApiModelProperty(value = "备注",example = "采购预付")
    private String remark;
    @ApiModelProperty(value = "单据日期",example = "2022-01-14")
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    private LocalDate billDate;
    @ApiModelProperty(value = "供应商id",example = "1584950950470164481")
    private String supplierId;
    @ApiModelProperty(value = "附件",example = "temp/图片1_1676104987152.png")
    private String attachment;
    @ApiModelProperty(value = "单据主题",example = "主题名")
    private String subject;
    @ApiModelProperty(value = "金额",example = "90000")
    private BigDecimal amt;

    // fin_payment_entry
    @ApiModelProperty(value = "源单id",example = "1624306985947406338")
    private String srcBillId;
    @ApiModelProperty(value = "分录号",example = "10")
    private Integer entryNo;
    @ApiModelProperty(value = "结算方式",example = "支票")
    private String settleMethod;
    @ApiModelProperty(value = "资金账户",example = "1584913699556106242")
    private String bankAccountId;
    @ApiModelProperty(value = "分录金额",example = "80000")
    private BigDecimal amt_entry;//命名重复
    @ApiModelProperty(value = "分录备注",example = "备注")
    private String remark_entry;//命名重复
    @ApiModelProperty(value = "自定义1",example = "内容自定义")
    private String custom1;
    @ApiModelProperty(value = "自定义2",example = "内容自定义")
    private String custom2;

}
