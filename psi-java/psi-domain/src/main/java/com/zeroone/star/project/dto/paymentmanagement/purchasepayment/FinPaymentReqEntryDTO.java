package com.zeroone.star.project.dto.paymentmanagement.purchasepayment;

import com.baomidou.mybatisplus.annotation.TableName;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.math.BigDecimal;

/**
 * @Describe 封装付款（有申请）的付款申请对象 --fin_payment_req_entry
 * @author 业峰
 * @since 2023-02-15
 */
@Data
@ApiModel("付款申请对象")
public class FinPaymentReqEntryDTO {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "申请金额",example = "15")
    private BigDecimal amt;
    @ApiModelProperty(value = "资金账户ID",example = "1625102683953471489")
    private String bankAccountId;
    @ApiModelProperty(value = "自定义1",example = "自定义1")
    private String custom1;
    @ApiModelProperty(value = "自定义2",example = "自定义2")
    private String custom2;
    @ApiModelProperty(value = "分录号",example = "10")
    private Integer entryNo;
    @ApiModelProperty(value = "备注",example = "备注")
    private String remark;
    @ApiModelProperty(value = "结算方式",example = "11")
    private String settleMethod;
    @ApiModelProperty(value = "源单号ID",example = "1628218091115945986")
    private String srcBillId;
    @ApiModelProperty(value = "源单类型",example = "FinPaymentReq:2011")
    private String srcBillType;
    @ApiModelProperty(value = "源单分录号",example = "CGYFSQ-230222-001")
    private String srcNo;

}
