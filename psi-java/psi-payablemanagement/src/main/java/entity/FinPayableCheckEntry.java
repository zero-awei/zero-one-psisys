package entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.math.BigDecimal;
import lombok.Data;

/**
 * 应付核销明细
 * @TableName fin_payable_check_entry
 */
@TableName(value ="fin_payable_check_entry")
@Data
public class FinPayableCheckEntry implements Serializable {
    /**
     * ID
     */
    @TableId
    private String id;

    /**
     * 主表
     */
    private String mid;

    /**
     * 单据编号
     */
    private String billNo;

    /**
     * 分录号
     */
    private Integer entryNo;

    /**
     * 源单类型
     */
    private String srcBillType;

    /**
     * 源单id
     */
    private String srcBillId;

    /**
     * 源单分录id
     */
    private String srcEntryId;

    /**
     * 源单号
     */
    private String srcNo;

    /**
     * 核销方向
     */
    private String checkSide;

    /**
     * 核销金额
     */
    private BigDecimal amt;

    /**
     * 备注
     */
    private String remark;

    /**
     * 自定义1
     */
    private String custom1;

    /**
     * 自定义2
     */
    private String custom2;

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
        FinPayableCheckEntry other = (FinPayableCheckEntry) that;
        return (this.getId() == null ? other.getId() == null : this.getId().equals(other.getId()))
            && (this.getMid() == null ? other.getMid() == null : this.getMid().equals(other.getMid()))
            && (this.getBillNo() == null ? other.getBillNo() == null : this.getBillNo().equals(other.getBillNo()))
            && (this.getEntryNo() == null ? other.getEntryNo() == null : this.getEntryNo().equals(other.getEntryNo()))
            && (this.getSrcBillType() == null ? other.getSrcBillType() == null : this.getSrcBillType().equals(other.getSrcBillType()))
            && (this.getSrcBillId() == null ? other.getSrcBillId() == null : this.getSrcBillId().equals(other.getSrcBillId()))
            && (this.getSrcEntryId() == null ? other.getSrcEntryId() == null : this.getSrcEntryId().equals(other.getSrcEntryId()))
            && (this.getSrcNo() == null ? other.getSrcNo() == null : this.getSrcNo().equals(other.getSrcNo()))
            && (this.getCheckSide() == null ? other.getCheckSide() == null : this.getCheckSide().equals(other.getCheckSide()))
            && (this.getAmt() == null ? other.getAmt() == null : this.getAmt().equals(other.getAmt()))
            && (this.getRemark() == null ? other.getRemark() == null : this.getRemark().equals(other.getRemark()))
            && (this.getCustom1() == null ? other.getCustom1() == null : this.getCustom1().equals(other.getCustom1()))
            && (this.getCustom2() == null ? other.getCustom2() == null : this.getCustom2().equals(other.getCustom2()))
            && (this.getVersion() == null ? other.getVersion() == null : this.getVersion().equals(other.getVersion()));
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + ((getId() == null) ? 0 : getId().hashCode());
        result = prime * result + ((getMid() == null) ? 0 : getMid().hashCode());
        result = prime * result + ((getBillNo() == null) ? 0 : getBillNo().hashCode());
        result = prime * result + ((getEntryNo() == null) ? 0 : getEntryNo().hashCode());
        result = prime * result + ((getSrcBillType() == null) ? 0 : getSrcBillType().hashCode());
        result = prime * result + ((getSrcBillId() == null) ? 0 : getSrcBillId().hashCode());
        result = prime * result + ((getSrcEntryId() == null) ? 0 : getSrcEntryId().hashCode());
        result = prime * result + ((getSrcNo() == null) ? 0 : getSrcNo().hashCode());
        result = prime * result + ((getCheckSide() == null) ? 0 : getCheckSide().hashCode());
        result = prime * result + ((getAmt() == null) ? 0 : getAmt().hashCode());
        result = prime * result + ((getRemark() == null) ? 0 : getRemark().hashCode());
        result = prime * result + ((getCustom1() == null) ? 0 : getCustom1().hashCode());
        result = prime * result + ((getCustom2() == null) ? 0 : getCustom2().hashCode());
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
        sb.append(", mid=").append(mid);
        sb.append(", billNo=").append(billNo);
        sb.append(", entryNo=").append(entryNo);
        sb.append(", srcBillType=").append(srcBillType);
        sb.append(", srcBillId=").append(srcBillId);
        sb.append(", srcEntryId=").append(srcEntryId);
        sb.append(", srcNo=").append(srcNo);
        sb.append(", checkSide=").append(checkSide);
        sb.append(", amt=").append(amt);
        sb.append(", remark=").append(remark);
        sb.append(", custom1=").append(custom1);
        sb.append(", custom2=").append(custom2);
        sb.append(", version=").append(version);
        sb.append(", serialVersionUID=").append(serialVersionUID);
        sb.append("]");
        return sb.toString();
    }
}