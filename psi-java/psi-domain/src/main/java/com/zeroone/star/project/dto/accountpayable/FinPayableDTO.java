package com.zeroone.star.project.dto.accountpayable;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.math.BigDecimal;
import java.time.LocalDateTime;

/**
 * @author chosen1
 * @author spk copied from chosen1
 * @since 2023-02-15
 * @description 应付单DTO
 * 应付核销-新增-根据供应商查询应付单 使用到的采购应付传输数据对象
 * checkAmt不在后端返回对象中，但是猜测uncheckedAmt = amt - checkAmt，所以保留
 * 增加字段：approverDictText
 * approvalResultTypeDictText
 */
@Data
@ApiModel("应付传输数据对象")
@AllArgsConstructor
@NoArgsConstructor
public class FinPayableDTO {

    /**
     * ID
     */
    @ApiModelProperty(value = "ID", example = "1590717742358511617")
    private String id;

    /**
     * 单据编号
     */
    @ApiModelProperty(value = "单据编号", example = "CGAP-221110-001")
    private String billNo;

    /**
     * 单据日期
     */
    @ApiModelProperty(value = "单据日期", example = "2022-01-13")
    private LocalDateTime billDate;

    /**
     * 源单类型
     */
    @ApiModelProperty(value = "源单类型", example = "StkIo:1011")
    private String srcBillType;

    @ApiModelProperty(value = "源单类型",example = "采购退货出库")
    private String srcBillTypeDictText;

    /**
     * 源单id
     */
    @ApiModelProperty(value = "源单id", example = "1624656178553593858")
    private String srcBillId;

    /**
     * 源单号
     */
    @ApiModelProperty(value = "源单号", example = "CGRK-230212-007")
    private String srcNo;

    /**
     * 单据主题
     */
    @ApiModelProperty(value = "单据主题")
    private String subject;

    /**
     * 是否红字
     */
    @ApiModelProperty(value = "是否红字", example = "1")
    private Integer isRubric;

    @ApiModelProperty(value = "是否红字", example = "是")
    private String isRubricDictText;

    /**
     * 应付类型
     */
    @ApiModelProperty(value = "应付类型", example = "201")
    private String payableType;

    @ApiModelProperty(value = "应付类型", example = "采购应付")
    private String payableTypeDictText;

    /**
     * 供应商
     */
    @ApiModelProperty(value = "供应商", example = "1623237590441566210")
    private String supplierId;

    @ApiModelProperty(value = "供应商", example = "01教育")
    private String supplierIdDicText;

    @ApiModelProperty(value = "业务部门", example = "A01")
    private String opDept;

    @ApiModelProperty(value = "业务部门", example = "北京 F 公司")
    private String opDeptDictText;

    /**
     * 业务员
     */
    @ApiModelProperty(value = "业务员", example = "jeecg")
    private String operator;

    @ApiModelProperty(value = "业务员", example = "jeecg")
    private String operatorDictText;

    /**
     * 金额
     */
    @ApiModelProperty(value = "金额", example = "0")
    private BigDecimal amt;

    /**
     * 已核销金额
     */
    @ApiModelProperty(value = "已核销金额", example = "0")
    private BigDecimal checkedAmt;

    @ApiModelProperty(value = "未核销金额", example = "0")
    private BigDecimal uncheckedAmt;

    /**
     * 附件
     */
    @ApiModelProperty(value = "附件")
    private String attachment;

    /**
     * 备注
     */
    @ApiModelProperty(value = "备注")
    private String remark;

    /**
     * 是否自动生成
     */
    @ApiModelProperty(value = "是否自动生成", example = "1")
    private Integer isAuto;

    @ApiModelProperty(value = "是否自动生成", example = "是")
    private String isAutoDictText;

    /**
     * 处理状态
     */
    @ApiModelProperty(value = "处理状态", example = "32")
    private String billStage;

    @ApiModelProperty(value = "处理状态", example = "执行中")
    private String billStageDictText;

    /**
     * 审核人
     */
    @ApiModelProperty(value = "审核人", example = "psi")
    private String approver;

    @ApiModelProperty(value = "审核人", example = "管理员")
    private String approverDictText;

    /**
     * 流程id
     */
    @ApiModelProperty(value = "流程id")
    private String bpmiInstanceId;

    /**
     * 核批结果类型
     */
    @ApiModelProperty(value = "核批结果类型", example = "")
    private String approvalResultType;

    @ApiModelProperty(value = "核批结果类型", example = "")
    private String approvalResultTypeDictText;

    /**
     * 核批意见
     */
    @ApiModelProperty(value = "核批意见")
    private String approvalRemark;

    /**
     * 是否通过
     */
    @ApiModelProperty(value = "是否通过", example = "1")
    private Integer isEffective;

    @ApiModelProperty(value = "是否通过", example = "是")
    private String isEffectiveDictText;

    /**
     * 生效时间
     */
    @ApiModelProperty(value = "生效时间")
    private LocalDateTime effectiveTime;

    /**
     * 已关闭
     */
    @ApiModelProperty(value = "已关闭", example = "0")
    private Integer isClosed;

    @ApiModelProperty(value = "已关闭", example = "否")
    private String isClosedDictText;

    /**
     * 是否作废
     */
    @ApiModelProperty(value = "是否作废", example = "0")
    private Integer isVoided;

    @ApiModelProperty(value = "是否作废", example = "否")
    private String isVoidedDictText;

    /**
     * 创建部门
     */
    @ApiModelProperty(value = "创建部门", example = "A01A05")
    private String sysOrgCode;

    @ApiModelProperty(value = "创建部门", example = "研发部")
    private String sysOrgCodeDictText;

    /**
     * 创建人
     */
    @ApiModelProperty(value = "创建人", example = "psi")
    private String createBy;

    @ApiModelProperty(value = "创建人", example = "管理员")
    private String createByDictText;

    /**
     * 创建时间
     */
    @ApiModelProperty(value = "创建时间")
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 修改人
     */
    @ApiModelProperty(value = "修改人", example = "psi")
    private String updateBy;

    @ApiModelProperty(value = "修改人", example = "管理员")
    private String updateByDictText;

    /**
     * 修改时间
     */
    @ApiModelProperty(value = "修改时间")
    private LocalDateTime updateTime;

    /**
     * 版本
     */
    @ApiModelProperty(value = "版本")
    private Integer version;
}
