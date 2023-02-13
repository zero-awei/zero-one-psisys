package com.zeroone.star.project.dto.payablemanagement;


import com.alibaba.excel.annotation.ExcelProperty;
import com.alibaba.excel.annotation.format.DateTimeFormat;
import com.baomidou.mybatisplus.annotation.TableField;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;

/**
 * 其他应付导入Excel
 *
 * @author iceberg-work
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
public class OthersPayableDTO implements Serializable {

    @TableField(exist = false)
    private static final long serialVersionUID = 1L;

    // value表示该属性对应的表头名称， index表示该属性所处的列的位置
    /**
     * 应付类型
     */
    @ExcelProperty(value = "应付类型", index = 0)
    String payableType_dictText;

    /**
     * 供应商
     */
    @ExcelProperty(value = "供应商", index = 1)
    String supplierId_dictText;

    /**
     * 业务部门
     */
    @ExcelProperty(value = "业务部门", index = 2)
    String opDept;

    /**
     * 业务员
     */
    @ExcelProperty(value = "业务员", index = 3)
    String operator;

    /**
     * 金额
     */
    @ExcelProperty(value = "金额", index = 4)
    String amt;

    /**
     * 已核销金额
     */
    @ExcelProperty(value = "已核销金额", index = 5)
    String checkedAmt;

    /**
     * 备注
     */
    @ExcelProperty(value = "备注", index = 6)
    String remark;

    /**
     * 单据编号
     */
    @ExcelProperty(value = "单据编号", index = 7)
    String billNo;

    /**
     * 核批结果类型
     */
    @ExcelProperty(value = "核批结果类型", index = 8)
    String approvalResultType;

    /**
     * 修改人
     */
    @ExcelProperty(value = "修改人", index = 9)
    String updateBy_dictText;

    /**
     * 是否生效
     */
    @ExcelProperty(value = "是否生效", index = 10)
    String isEffective_dictText;

    /**
     * 已作废
     */
    @ExcelProperty(value = "已作废", index = 11)
    String isVoided_dictText;

    /**
     * 核批人
     */
    @ExcelProperty(value = "核批人", index = 12)
    String approver_dictText;

    /**
     * 单据日期
     */
    @ExcelProperty(value = "单据日期", index = 13)
    @DateTimeFormat("yyyy-MM-dd")
    String billDate;

    /**
     * 源单类型
     */
    @ExcelProperty(value = "源单类型", index = 14)
    String srcBillType;

    /**
     * 核批意见
     */
    @ExcelProperty(value = "核批意见", index = 15)
    String approvalRemark;

    /**
     * 源单号
     */
    @ExcelProperty(value = "源单号", index = 16)
    String srcNo;

    /**
     * 修改时间
     */
    @ExcelProperty(value = "修改时间", index = 17)
    @DateTimeFormat("yyyy-MM-dd HH:mm:ss")
    String updateTime;

    /**
     * 是否自动生成
     */
    @ExcelProperty(value = "是否自动生成", index = 18)
    String isAuto_dictText;

    /**
     * 是否红字
     */
    @ExcelProperty(value = "是否红字", index = 19)
    String isRubric_dictText;

    /**
     * 制单部门
     */
    @ExcelProperty(value = "制单部门", index = 20)
    String sysOrgCode_dictText;

    /**
     * 制单时间
     */
    @ExcelProperty(value = "制单时间", index = 21)
    @DateTimeFormat("yyyy-MM-dd HH:mm:ss")
    String createTime;

    /**
     * 制单人
     */
    @ExcelProperty(value = "制单人", index = 22)
    String createBy_dictText;

    /**
     * 源单id
     */
    @ExcelProperty(value = "源单id", index = 23)
    String srcBillId;

    /**
     * 生效时间
     */
    @ExcelProperty(value = "生效时间", index = 24)
    @DateTimeFormat("yyyy-MM-dd HH:mm:ss")
    String effectiveTime;

    /**
     * 单据阶段
     */
    @ExcelProperty(value = "单据阶段", index = 25)
    String billStage_dictText;

    /**
     * 附件
     */
    @ExcelProperty(value = "附件", index = 26)
    String attachment;

    /**
     * 单据主题
     */
    @ExcelProperty(value = "单据主题", index = 27)
    String subject;

    /**
     * 已关闭
     */
    @ExcelProperty(value = "已关闭", index = 28)
    String isClosed_dictText;

    /**
     * 审批实例id
     */
    @ExcelProperty(value = "审批实例id", index = 29)
    String id;
}
