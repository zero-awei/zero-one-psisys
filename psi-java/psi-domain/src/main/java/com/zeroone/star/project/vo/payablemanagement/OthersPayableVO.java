package com.zeroone.star.project.vo.payablemanagement;


import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;
import java.util.HashMap;
import java.util.Map;

/**
 * 其他应付导出Excel
 *
 * @author iceberg-work
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
public class OthersPayableVO implements Serializable {

    /**
     * 应付类型
     */
    String payableType_dictText;

    /**
     * 供应商
     */
    String supplierId_dictText;

    /**
     * 业务部门
     */
    String opDept;

    /**
     * 业务员
     */
    String operator;

    /**
     * 金额
     */
    String amt;

    /**
     * 已核销金额
     */
    String checkedAmt;

    /**
     * 备注
     */
    String remark;

    /**
     * 单据编号
     */
    String billNo;

    /**
     * 核批结果类型
     */
    String approvalResultType;

    /**
     * 修改人
     */
    String updateBy_dictText;

    /**
     * 是否生效
     */
    String isEffective_dictText;

    /**
     * 已作废
     */
    String isVoided_dictText;

    /**
     * 核批人
     */
    String approver_dictText;

    /**
     * 单据日期
     */
    Data billDate;

    /**
     * 源单类型
     */
    String srcBillType;

    /**
     * 核批意见
     */
    String approvalRemark;

    /**
     * 源单号
     */
    String srcNo;

    /**
     * 修改时间
     */
    Data updateTime;

    /**
     * 是否自动生成
     */
    String isAuto_dictText;

    /**
     * 是否红字
     */
    String isRubric_dictText;

    /**
     * 制单部门
     */
    String sysOrgCode_dictText;

    /**
     * 制单时间
     */
    Data createTime;

    /**
     * 制单人
     */
    String createBy_dictText;

    /**
     * 源单id
     */
    String srcBillId;

    /**
     * 生效时间
     */
    Data effectiveTime;

    /**
     * 单据阶段
     */
    String billStage_dictText;

    /**
     * 附件
     */
    String attachment;

    /**
     * 单据主题
     */
    String subject;

    /**
     * 已关闭
     */
    String isClosed_dictText;

    /**
     * 审批实例id
     */
    String id;

    public Map<String, Object> getMapForTemplate() {
        Map<String, Object> map = new HashMap<>(1);
        map.put("approver_dictText", approver_dictText);
        return map;
    }
}
