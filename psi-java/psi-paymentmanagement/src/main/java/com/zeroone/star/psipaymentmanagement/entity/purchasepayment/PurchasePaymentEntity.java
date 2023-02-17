package com.zeroone.star.psipaymentmanagement.entity.purchasepayment;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import lombok.ToString;

import java.util.Date;
import java.util.List;

/**
 * @author Tomcat
 * @Date 2023/2/15 23:32
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
@ToString
@TableName()
public class PurchasePaymentEntity {
    private String remark;
    private String billNo;
    private String approvalResultType;
    private String updateBy;
    private String isEffective;
    private String isVoided;
    private Date billType;
    private String approver;
    private Date billDate;
    private String srcBillType;
    private String approvalRemark;
    private String srcNo;
    private Date updateTime;
    private String isAuto;
    private String isRubric;
    private String sysOrgCode;
    private Date createTime;
    private String createBy;
    private String srcBillId;
    private String effectiveTime;
    private String billStage;
    private String version;
    private String attachment;
    private String subject;
    private String id;
    private String isClosed;
    private String bpmiInstanceId;
    private String paymentType;
    private String supplierId;
    private String amt;
    private String checkedAmt;
    private String uncheckedAmt;
    private String paymentTypeDictText;
    private String supplierIdDictText;
    private String updateByDictText;
    private String isEffectiveDictText;
    private String isVoidedDictText;
    private String isAutoDictText;
    private String isRubricDictText;
    private String sysOrgCodeDictText;
    private String createByDictText;
    private String billStageDictText;
    private String isClosedDictText;
    private List<String> finPaymentEntryList;
}
