package com.zeroone.star.project.dto.paymentmanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import java.time.LocalDateTime;
import java.util.List;

/**
 * @Description 修改采购付款示例数据传输对象
 * @Author 业峰
 * @Date 2023/2/15
 */
@Data
@ApiModel("修改采购付款示例数据传输对象")     //fin_payment
public class UpdatePurchasePaymentDto {
    @ApiModelProperty(value = "金额", example = "88885")
    private String amt;
    @ApiModelProperty(value = "核批意见", example = "null")
    private String approvalRemark;
    @ApiModelProperty(value = "核批结果类型", example = "null")
    private String approvalResultType;
    @ApiModelProperty(value = "审核人", example = "null")
    private String approver;
    @ApiModelProperty(value = "附件", example = "temp/InterfaceToTable_1676526658855.md")
    private String attachment;
    @ApiModelProperty(value = "单据日期", example = "2023-02-16")
    private String billDate;
    @ApiModelProperty(value = "单据编号", example = "CGFK-230216-014")
    private String billNo;
    @ApiModelProperty(value = "处理状态名", example = "14")
    private String billStage;
    @ApiModelProperty(value = "处理状态", example = "编制完")
    private String billStage_dictText;
    @ApiModelProperty(value = "流程", example = "")
    private String bpmiInstanceId;
    @ApiModelProperty(value = "已核销金额", example = "0")
    private String checkedAmt;
    @ApiModelProperty(value = "创建人", example = "psi")
    private String createBy;
    @ApiModelProperty(value = "创建人名", example = "管理员")
    private String createBy_dictText;
    @ApiModelProperty(value = "创建时间", example = "2023-02-16 13:43:16")
    private String createTime;
    @ApiModelProperty(value = "生效时间", example = "2023-02-16 13:43:16")
    private String effectiveTime;
    @ApiModelProperty(value = "ID", example = "1626094838582910977")
    private String id;
    @ApiModelProperty(value = "是否自动单据", example = "0")
    private String isAuto;
    @ApiModelProperty(value = "是否自动单据", example = "否")
    private String isAuto_dictText;
    @ApiModelProperty(value = "已关闭", example = "0")
    private String isClosed;
    @ApiModelProperty(value = "已关闭", example = "否")
    private String isClosed_dictText;
    @ApiModelProperty(value = "是否通过", example = "0")
    private String isEffective;
    @ApiModelProperty(value = "是否通过", example = "否")
    private String isEffective_dictText;
    @ApiModelProperty(value = "是否红字", example = "0")
    private String isRubric;
    @ApiModelProperty(value = "是否红字", example = "否")
    private String isRubric_dictText;
    @ApiModelProperty(value = "是否作废", example = "0")
    private String isVoided;
    @ApiModelProperty(value = "是否作废", example = "否")
    private String isVoided_dictText;
    @ApiModelProperty(value = "付款类型", example = "2021")
    private String paymentType;
    @ApiModelProperty(value = "付款类型", example = "采购付款(有申请)")
    private String paymentType_dictText;
    @ApiModelProperty(value = "备注", example = "xd")
    private String remark;
    @ApiModelProperty(value = "源单id", example = "")
    private String srcBillId;
    @ApiModelProperty(value = "源单类型", example = "")
    private String srcBillType;
    @ApiModelProperty(value = "源单号", example = "")
    private String srcNo;
    @ApiModelProperty(value = "单据主题", example = "233")
    private String subject;
    @ApiModelProperty(value = "供应商", example = "1623600860981665793")
    private String supplierId;
    @ApiModelProperty(value = "供应商", example = "公交卡")
    private String supplierId_dictText;
    @ApiModelProperty(value = "创建部门", example = "A01A05")
    private String sysOrgCode;
    @ApiModelProperty(value = "创建部门", example = "研发部")
    private String sysOrgCode_dictText;
    @ApiModelProperty(value = "修改人", example = "")
    private String updateBy;
    @ApiModelProperty(value = "修改时间", example = "")
    private String updateTime;
    @ApiModelProperty(value = "版本", example = "")
    private String version;

    //表找不到对应
    @ApiModelProperty(value = "未核销金额", example = "0")
    private String uncheckedAmt;
    @ApiModelProperty(value = "原单列表", example = "finPaymentEntryList")
    private List finPaymentEntryList;
    @ApiModelProperty(value = "处理状态", example = "FinPayment:2021")
    private String billType;

}
