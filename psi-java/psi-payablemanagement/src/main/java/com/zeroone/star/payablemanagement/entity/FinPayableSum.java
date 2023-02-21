package com.zeroone.star.payablemanagement.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.math.BigDecimal;
import lombok.Data;

/**
 * 应付汇总
 * @TableName fin_payable_sum
 */
@TableName(value ="fin_payable_sum")
@Data
public class FinPayableSum implements Serializable {
    /**
     * ID
     */
    @TableId
    private String id;

    /**
     * 业务年度
     */
    private Integer year;

    /**
     * 业务月度
     */
    private Integer month;

    /**
     * 供应商
     */
    private String supplierId;

    /**
     * 期初贷方余额
     */
    private BigDecimal beginCreditBal;

    /**
     * 借方金额
     */
    private BigDecimal debitAmt;

    /**
     * 贷方金额
     */
    private BigDecimal creditAmt;

    /**
     * 期末贷方余额
     */
    private BigDecimal creditBal;

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
        FinPayableSum other = (FinPayableSum) that;
        return (this.getId() == null ? other.getId() == null : this.getId().equals(other.getId()))
                && (this.getYear() == null ? other.getYear() == null : this.getYear().equals(other.getYear()))
                && (this.getMonth() == null ? other.getMonth() == null : this.getMonth().equals(other.getMonth()))
                && (this.getSupplierId() == null ? other.getSupplierId() == null : this.getSupplierId().equals(other.getSupplierId()))
                && (this.getBeginCreditBal() == null ? other.getBeginCreditBal() == null : this.getBeginCreditBal().equals(other.getBeginCreditBal()))
                && (this.getDebitAmt() == null ? other.getDebitAmt() == null : this.getDebitAmt().equals(other.getDebitAmt()))
                && (this.getCreditAmt() == null ? other.getCreditAmt() == null : this.getCreditAmt().equals(other.getCreditAmt()))
                && (this.getCreditBal() == null ? other.getCreditBal() == null : this.getCreditBal().equals(other.getCreditBal()));
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + ((getId() == null) ? 0 : getId().hashCode());
        result = prime * result + ((getYear() == null) ? 0 : getYear().hashCode());
        result = prime * result + ((getMonth() == null) ? 0 : getMonth().hashCode());
        result = prime * result + ((getSupplierId() == null) ? 0 : getSupplierId().hashCode());
        result = prime * result + ((getBeginCreditBal() == null) ? 0 : getBeginCreditBal().hashCode());
        result = prime * result + ((getDebitAmt() == null) ? 0 : getDebitAmt().hashCode());
        result = prime * result + ((getCreditAmt() == null) ? 0 : getCreditAmt().hashCode());
        result = prime * result + ((getCreditBal() == null) ? 0 : getCreditBal().hashCode());
        return result;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(getClass().getSimpleName());
        sb.append(" [");
        sb.append("Hash = ").append(hashCode());
        sb.append(", id=").append(id);
        sb.append(", year=").append(year);
        sb.append(", month=").append(month);
        sb.append(", supplierId=").append(supplierId);
        sb.append(", beginCreditBal=").append(beginCreditBal);
        sb.append(", debitAmt=").append(debitAmt);
        sb.append(", creditAmt=").append(creditAmt);
        sb.append(", creditBal=").append(creditBal);
        sb.append(", serialVersionUID=").append(serialVersionUID);
        sb.append("]");
        return sb.toString();
    }
}