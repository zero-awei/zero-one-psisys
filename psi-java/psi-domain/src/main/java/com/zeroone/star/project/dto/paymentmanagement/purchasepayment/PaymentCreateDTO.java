package com.zeroone.star.project.dto.paymentmanagement.purchasepayment;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.math.BigDecimal;
import java.time.LocalDate;
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
    @DateTimeFormat(pattern = "yyyy-MM-dd")     //业峰：日期需要加格式注解才能格式正确
    @ApiModelProperty(value =  "单据日期", example = "2023-02-15")
    private LocalDate billDate;
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
	@ApiModelProperty(value =  "付款类型", example = "采购付款（有申请）2021、采购付款（无申请）2020、采购退货退款(红付)203")
    private String paymentType;
	@ApiModelProperty(value =  "申请金额", example = "0")
    private BigDecimal amt;
	@ApiModelProperty(value =  "已销核金额", example = "0")
    private BigDecimal checkedAmt;
	@ApiModelProperty(value =  "单据主题", example = "123456")
    private String subject;
	@ApiModelProperty(value =  "供应商", example = "1623600860981665793")
    private String supplierId;
	@ApiModelProperty(value =  "备注", example = "test")
    private String remark;
	@ApiModelProperty(value =  "附件", example = "temp/QQ图片20230115205241_1676461436246.gif")
    private String attachment;
	@ApiModelProperty(value =  "付款单明细", example = "FinPaymentReq")
    private List<FinPaymentReqEntryDTO> finPaymentEntryList;
}
