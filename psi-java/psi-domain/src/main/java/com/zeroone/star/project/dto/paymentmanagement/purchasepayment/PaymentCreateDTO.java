package com.zeroone.star.project.dto.paymentmanagement.purchasepayment;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.Date;
import java.util.List;

/**
 * @author Tomcat
 * @Date 2023/2/15 17:32
 */
@Data
@ApiModel("增加采购付款的数据传输对象")
public class PaymentCreateDTO {

    @ApiModelProperty(value = "单据编号", example = "CGFK-230215-038")
    private String billNo;
    @ApiModelProperty(value =  "单据日期", example = "2023-02-15")
    private Date billDate;
    @ApiModelProperty(value =  "是否自动生成", example = "0")
    private String isAuto;
    @ApiModelProperty(value =  "是否红字", example = "0")
    private String isRubric;
    @ApiModelProperty(value =  "源单类型", example = "")
    private String srcBillType;
	@ApiModelProperty(value =  "源单id", example = "")
    private String srcBillId;
    @ApiModelProperty(value =  "源单号", example = "")
    private String srcNo;
	@ApiModelProperty(value =  "付款类型", example = "2021")
    private String paymentType;
	@ApiModelProperty(value =  "申请金额", example = "0")
    private String amt;
	@ApiModelProperty(value =  "已销核金额", example = "0")
    private String checkedAmt;
	@ApiModelProperty(value =  "单据主题", example = "123456")
    private String subject;
	@ApiModelProperty(value =  "供应商", example = "1623600860981665793")
    private String supplierId;
	@ApiModelProperty(value =  "备注", example = "test")
    private String remark;
	@ApiModelProperty(value =  "附件", example = "temp/QQ图片20230115205241_1676461436246.gif")
    private String attachment;
	@ApiModelProperty(value =  "付款单明细", example = "[]")
    private List<String> finPaymentEntryList;
}
