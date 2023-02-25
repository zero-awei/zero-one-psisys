package com.zeroone.star.project.dto.paymentmanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import java.math.BigDecimal;
import java.time.LocalDate;
import java.util.List;

/**
 * @Description 新增采购付款示例数据传输对象
 * @Author 业峰
 * @Date 2023/2/15
 */
@Data
@ApiModel("新增采购付款示例数据传输对象")
public class AddPurchasePaymentDto {
    @ApiModelProperty(value = "金额", example = "0")
    private BigDecimal amt;
    /*
    @NotBlank(message = "单据日期不能为空")
    @ApiModelProperty(value = "单据日期", example = "2023-02-15")
    private LocalDate billDate;
    */

    @NotBlank(message = "单据编号不能为空")
    @ApiModelProperty(value = "单据编号", example = "CGFK-230215-005")
    private String billNo;
    @ApiModelProperty(value = "已核销金额", example = "0")
    private BigDecimal checkedAmt;
    @ApiModelProperty(value = "源单列表", example = "finalPaymentEntryList")
    private List<String> finalPaymentEntryList;
    @ApiModelProperty(value = "是否自动单据", example = "0")
    private Integer isAuto;
    @ApiModelProperty(value = "红字单据", example = "0")
    private Integer isRubric;
    @ApiModelProperty(value = "结算方式代号", example = "2021")
    private String paymentType;
    @ApiModelProperty(value = "源单号", example = "CGYFSQ-230210-007")
    private String srcBillId;
    @ApiModelProperty(value = "源单号类型", example = "")
    private String srcBillType;
    @ApiModelProperty(value = "源单号", example = "")
    private String srcNo;
    @NotBlank(message = "供应商不能为空")
    @ApiModelProperty(value = "供应商ID", example = "1623600860981665793")
    private String supplierId;
    @ApiModelProperty(value = "主题", example = "主题")
    private String subject;
    @ApiModelProperty(value = "备注", example = "备注")
    private String Remark;

}
