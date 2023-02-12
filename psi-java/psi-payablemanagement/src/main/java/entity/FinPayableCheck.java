package entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.math.BigDecimal;
import java.util.Date;
import lombok.Data;

/**
 * 应付核销单
 * @TableName fin_payable_check
 */
@TableName(value ="fin_payable_check")
@Data
public class FinPayableCheck implements Serializable {
    /**
     * ID
     */
    @TableId
    private String id;

    /**
     * 单据编号
     */
    private String billNo;

    /**
     * 单据日期
     */
    private Date billDate;

    /**
     * 源单类型
     */
    private String srcBillType;

    /**
     * 源单id
     */
    private String srcBillId;

    /**
     * 源单号
     */
    private String srcNo;

    /**
     * 
     */
    private String subject;

    /**
     * 是否红字
     */
    private Integer isRubric;

    /**
     * 核销类型
     */
    private String payableCheckType;

    /**
     * 供应商
     */
    private String supplierId;

    /**
     * 核销金额
     */
    private BigDecimal amt;

    /**
     * 附件
     */
    private String attachment;

    /**
     * 备注
     */
    private String remark;

    /**
     * 是否自动生成
     */
    private Integer isAuto;

    /**
     * 处理状态
     */
    private String billStage;

    /**
     * 审核人
     */
    private String approver;

    /**
     * 流程id
     */
    private String bpmiInstanceId;

    /**
     * 核批结果类型
     */
    private String approvalResultType;

    /**
     * 核批意见
     */
    private String approvalRemark;

    /**
     * 是否通过
     */
    private Integer isEffective;

    /**
     * 生效时间
     */
    private Date effectiveTime;

    /**
     * 已关闭
     */
    private Integer isClosed;

    /**
     * 是否作废
     */
    private Integer isVoided;

    /**
     * 创建时间
     */
    private Date createTime;

    /**
     * 创建人
     */
    private String createBy;

    /**
     * 创建部门
     */
    private String sysOrgCode;

    /**
     * 修改时间
     */
    private Date updateTime;

    /**
     * 修改人
     */
    private String updateBy;

    /**
     * 版本
     */
    private Integer version;

    @TableField(exist = false)
    private static final long serialVersionUID = 1L;

    @Override
    public boolean equals(Object that) {
        if (this == that) {
            return true;
        }
        if (that == null) {
            return false;
        }
        if (getClass() != that.getClass()) {
            return false;
        }
        FinPayableCheck other = (FinPayableCheck) that;
        return (this.getId() == null ? other.getId() == null : this.getId().equals(other.getId()))
            && (this.getBillNo() == null ? other.getBillNo() == null : this.getBillNo().equals(other.getBillNo()))
            && (this.getBillDate() == null ? other.getBillDate() == null : this.getBillDate().equals(other.getBillDate()))
            && (this.getSrcBillType() == null ? other.getSrcBillType() == null : this.getSrcBillType().equals(other.getSrcBillType()))
            && (this.getSrcBillId() == null ? other.getSrcBillId() == null : this.getSrcBillId().equals(other.getSrcBillId()))
            && (this.getSrcNo() == null ? other.getSrcNo() == null : this.getSrcNo().equals(other.getSrcNo()))
            && (this.getSubject() == null ? other.getSubject() == null : this.getSubject().equals(other.getSubject()))
            && (this.getIsRubric() == null ? other.getIsRubric() == null : this.getIsRubric().equals(other.getIsRubric()))
            && (this.getPayableCheckType() == null ? other.getPayableCheckType() == null : this.getPayableCheckType().equals(other.getPayableCheckType()))
            && (this.getSupplierId() == null ? other.getSupplierId() == null : this.getSupplierId().equals(other.getSupplierId()))
            && (this.getAmt() == null ? other.getAmt() == null : this.getAmt().equals(other.getAmt()))
            && (this.getAttachment() == null ? other.getAttachment() == null : this.getAttachment().equals(other.getAttachment()))
            && (this.getRemark() == null ? other.getRemark() == null : this.getRemark().equals(other.getRemark()))
            && (this.getIsAuto() == null ? other.getIsAuto() == null : this.getIsAuto().equals(other.getIsAuto()))
            && (this.getBillStage() == null ? other.getBillStage() == null : this.getBillStage().equals(other.getBillStage()))
            && (this.getApprover() == null ? other.getApprover() == null : this.getApprover().equals(other.getApprover()))
            && (this.getBpmiInstanceId() == null ? other.getBpmiInstanceId() == null : this.getBpmiInstanceId().equals(other.getBpmiInstanceId()))
            && (this.getApprovalResultType() == null ? other.getApprovalResultType() == null : this.getApprovalResultType().equals(other.getApprovalResultType()))
            && (this.getApprovalRemark() == null ? other.getApprovalRemark() == null : this.getApprovalRemark().equals(other.getApprovalRemark()))
            && (this.getIsEffective() == null ? other.getIsEffective() == null : this.getIsEffective().equals(other.getIsEffective()))
            && (this.getEffectiveTime() == null ? other.getEffectiveTime() == null : this.getEffectiveTime().equals(other.getEffectiveTime()))
            && (this.getIsClosed() == null ? other.getIsClosed() == null : this.getIsClosed().equals(other.getIsClosed()))
            && (this.getIsVoided() == null ? other.getIsVoided() == null : this.getIsVoided().equals(other.getIsVoided()))
            && (this.getCreateTime() == null ? other.getCreateTime() == null : this.getCreateTime().equals(other.getCreateTime()))
            && (this.getCreateBy() == null ? other.getCreateBy() == null : this.getCreateBy().equals(other.getCreateBy()))
            && (this.getSysOrgCode() == null ? other.getSysOrgCode() == null : this.getSysOrgCode().equals(other.getSysOrgCode()))
            && (this.getUpdateTime() == null ? other.getUpdateTime() == null : this.getUpdateTime().equals(other.getUpdateTime()))
            && (this.getUpdateBy() == null ? other.getUpdateBy() == null : this.getUpdateBy().equals(other.getUpdateBy()))
            && (this.getVersion() == null ? other.getVersion() == null : this.getVersion().equals(other.getVersion()));
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + ((getId() == null) ? 0 : getId().hashCode());
        result = prime * result + ((getBillNo() == null) ? 0 : getBillNo().hashCode());
        result = prime * result + ((getBillDate() == null) ? 0 : getBillDate().hashCode());
        result = prime * result + ((getSrcBillType() == null) ? 0 : getSrcBillType().hashCode());
        result = prime * result + ((getSrcBillId() == null) ? 0 : getSrcBillId().hashCode());
        result = prime * result + ((getSrcNo() == null) ? 0 : getSrcNo().hashCode());
        result = prime * result + ((getSubject() == null) ? 0 : getSubject().hashCode());
        result = prime * result + ((getIsRubric() == null) ? 0 : getIsRubric().hashCode());
        result = prime * result + ((getPayableCheckType() == null) ? 0 : getPayableCheckType().hashCode());
        result = prime * result + ((getSupplierId() == null) ? 0 : getSupplierId().hashCode());
        result = prime * result + ((getAmt() == null) ? 0 : getAmt().hashCode());
        result = prime * result + ((getAttachment() == null) ? 0 : getAttachment().hashCode());
        result = prime * result + ((getRemark() == null) ? 0 : getRemark().hashCode());
        result = prime * result + ((getIsAuto() == null) ? 0 : getIsAuto().hashCode());
        result = prime * result + ((getBillStage() == null) ? 0 : getBillStage().hashCode());
        result = prime * result + ((getApprover() == null) ? 0 : getApprover().hashCode());
        result = prime * result + ((getBpmiInstanceId() == null) ? 0 : getBpmiInstanceId().hashCode());
        result = prime * result + ((getApprovalResultType() == null) ? 0 : getApprovalResultType().hashCode());
        result = prime * result + ((getApprovalRemark() == null) ? 0 : getApprovalRemark().hashCode());
        result = prime * result + ((getIsEffective() == null) ? 0 : getIsEffective().hashCode());
        result = prime * result + ((getEffectiveTime() == null) ? 0 : getEffectiveTime().hashCode());
        result = prime * result + ((getIsClosed() == null) ? 0 : getIsClosed().hashCode());
        result = prime * result + ((getIsVoided() == null) ? 0 : getIsVoided().hashCode());
        result = prime * result + ((getCreateTime() == null) ? 0 : getCreateTime().hashCode());
        result = prime * result + ((getCreateBy() == null) ? 0 : getCreateBy().hashCode());
        result = prime * result + ((getSysOrgCode() == null) ? 0 : getSysOrgCode().hashCode());
        result = prime * result + ((getUpdateTime() == null) ? 0 : getUpdateTime().hashCode());
        result = prime * result + ((getUpdateBy() == null) ? 0 : getUpdateBy().hashCode());
        result = prime * result + ((getVersion() == null) ? 0 : getVersion().hashCode());
        return result;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(getClass().getSimpleName());
        sb.append(" [");
        sb.append("Hash = ").append(hashCode());
        sb.append(", id=").append(id);
        sb.append(", billNo=").append(billNo);
        sb.append(", billDate=").append(billDate);
        sb.append(", srcBillType=").append(srcBillType);
        sb.append(", srcBillId=").append(srcBillId);
        sb.append(", srcNo=").append(srcNo);
        sb.append(", subject=").append(subject);
        sb.append(", isRubric=").append(isRubric);
        sb.append(", payableCheckType=").append(payableCheckType);
        sb.append(", supplierId=").append(supplierId);
        sb.append(", amt=").append(amt);
        sb.append(", attachment=").append(attachment);
        sb.append(", remark=").append(remark);
        sb.append(", isAuto=").append(isAuto);
        sb.append(", billStage=").append(billStage);
        sb.append(", approver=").append(approver);
        sb.append(", bpmiInstanceId=").append(bpmiInstanceId);
        sb.append(", approvalResultType=").append(approvalResultType);
        sb.append(", approvalRemark=").append(approvalRemark);
        sb.append(", isEffective=").append(isEffective);
        sb.append(", effectiveTime=").append(effectiveTime);
        sb.append(", isClosed=").append(isClosed);
        sb.append(", isVoided=").append(isVoided);
        sb.append(", createTime=").append(createTime);
        sb.append(", createBy=").append(createBy);
        sb.append(", sysOrgCode=").append(sysOrgCode);
        sb.append(", updateTime=").append(updateTime);
        sb.append(", updateBy=").append(updateBy);
        sb.append(", version=").append(version);
        sb.append(", serialVersionUID=").append(serialVersionUID);
        sb.append("]");
        return sb.toString();
    }
}