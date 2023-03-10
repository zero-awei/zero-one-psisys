package com.zeroone.star.project.dto.paymentmanagement.purchasepayment;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.util.Date;
import java.util.List;

/**
 * @author Tomcat -- 业峰实现
 * @Date 2023/2/15 17:31
 */
@Data
@ApiModel("修改采购付款的数据传输对象")
public class PaymentUpdateDTO {
    @ApiModelProperty(value ="备注", example = "test")
    private String remark;
    @ApiModelProperty(value =  "单据编号", example = "CGFK-230215-035")
    private String billNo;
    @ApiModelProperty(value =  "核批结果类型", example = "")
    private String approvalResultType;
    @ApiModelProperty(value =  "修改人", example = "psi")
    private String updateBy;
    @ApiModelProperty(value =  "是否生效", example = "0")
    private String isEffective;
    @ApiModelProperty(value =  "是否作废", example = "0")
    private String isVoided;
    @ApiModelProperty(value =  "单据阶段", example = "FinPayment")
    private String billType;
    @ApiModelProperty(value =  "审核人", example = "")
    private String approver;
    //这里的单据日期应该指的是单据创建的日期，这里是修改，故不要这个属性值
    //@ApiModelProperty(value =  "单据日期", example = "2023-02-15")
    //private Date billDate;
    @ApiModelProperty(value =  "源单类型", example = "")
    private String srcBillType;
    @ApiModelProperty(value =  "核批意见", example = "null")
    private String approvalRemark;
    @ApiModelProperty(value =  "源单号", example = "")
    private String srcNo;
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @ApiModelProperty(value =  "修改时间", example = "2023-02-15 17")
    private Date updateTime;
    @ApiModelProperty(value =  "是否自动生成", example = "0")
    private String isAuto;
    @ApiModelProperty(value =  "是否红字", example = "0")
    private String isRubric;
    @ApiModelProperty(value =  "创建部门", example = "A01A05")
    private String sysOrgCode;
    //这里是更新操作，创建的时间是新增的时候就确定了，后期不可修改，故不存在这个属性值
    //@ApiModelProperty(value =  "创建时间", example = "2023-02-15 17")
    //private Date createTime;
    //创建人不可以修改
    //@ApiModelProperty(value =  "创建人", example = "psi")
    //private String createBy;
    @ApiModelProperty(value =  "源单id", example = "")
    private String srcBillId;
    @ApiModelProperty(value =  "生效时间", example = "null")
    private String effectiveTime;
    @ApiModelProperty(value =  "处理状态", example = "12")
    private String billStage;
    @ApiModelProperty(value =  "版本", example = "null")
    private String version;
    @ApiModelProperty(value =  "附件", example = "null")
    private String attachment;
    @ApiModelProperty(value =  "单据主题", example = "123456")
    private String subject;
    @ApiModelProperty(value =  "单据ID", example = "1625794808441511937")
    private String id;
    @ApiModelProperty(value =  "已关闭", example = "0")
    private String isClosed;
    @ApiModelProperty(value =  "流程id", example = "null")
    private String bpmiInstanceId;
    @ApiModelProperty(value =  "付款类型", example = "2021")
    private String paymentType;
    @ApiModelProperty(value =  "供应商", example = "1623600860981665793")
    private String supplierId;
    @ApiModelProperty(value =  "申请金额", example = "88885")
    private String amt;
    @ApiModelProperty(value =  "已销核金额", example = "0")
    private String checkedAmt;
    @ApiModelProperty(value =  "申请金额", example = "88885")
    private String uncheckedAmt;
    @ApiModelProperty(value =  "付款类型", example = "采购付款(有申请)")
    private String paymentTypeDictText;
    @ApiModelProperty(value =  "供应商", example = "公交卡")
    private String supplierIdDictText;
    @ApiModelProperty(value =  "真实姓名", example = "管理员")
    private String updateByDictText;
    @ApiModelProperty(value =  "是否通过", example = "否")
    private String isEffectiveDictText;
    @ApiModelProperty(value =  "是否作废", example = "否")
    private String isVoidedDictText;
    @ApiModelProperty(value =  "是否自动生成", example = "否")
    private String isAutoDictText;
    @ApiModelProperty(value =  "是否红字", example = "否")
    private String isRubricDictText;
    @ApiModelProperty(value =  "创建部门", example = "研发部")
    private String sysOrgCodeDictText;
    @ApiModelProperty(value =  "创建人", example = "管理员")
    private String createByDictText;
    @ApiModelProperty(value =  "处理状态", example = "编制中")
    private String billStageDictText;
    @ApiModelProperty(value =  "已关闭", example = "否")
    private String isClosedDictText;
    @ApiModelProperty(value =  "付款单明细", example = "[]")
    private List<String> finPaymentEntryList;
}
