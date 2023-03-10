package com.zeroone.star.project.vo.prepayment;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;
import java.time.LocalDate;
import java.time.LocalDateTime;

@Data
@ApiModel("显示单据列表")
public class FinPaymentVO {
    /**
     * ID
     */
//    @TableId(type = IdType.ASSIGN_ID)
    @ApiModelProperty(value = "id")
    private String id;

    /**
     * 单据编号
     */
    @ApiModelProperty(value = "单据编号")
    private String billNo;

    /**
     * 单据日期
     */
    @ApiModelProperty(value = "单据日期")
    private LocalDate billDate;

    /**
     * 源单类型
     */
    @ApiModelProperty(value = "源单类型")
    private String srcBillType;

    /**
     * 源单id
     */
    @ApiModelProperty(value = "源单id")
    private String srcBillId;

    /**
     * 源单号
     */
    @ApiModelProperty(value = "源单号")
    private String srcNo;

    /**
     * 单据主题
     */
    @ApiModelProperty(value = "单据主题")
    private String subject;

    /**
     * 是否红字
     */
    @ApiModelProperty(value = "是否红字")
    private Integer isRubric;

    /**
     * 付款类型
     */
    @ApiModelProperty(value = "付款类型")
    private String paymentType;

    /**
     * 供应商
     */
    @ApiModelProperty(value = "供应商")
    private String supplierId;

    /**
     * 金额
     */
    @ApiModelProperty(value = "金额")
    private BigDecimal amt;

    /**
     * 已核销金额
     */
    @ApiModelProperty(value = "已核销金额")
    private BigDecimal checkedAmt;

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
     * 是否自动单据
     */
    @ApiModelProperty(value = "是否自动单据")
    private Integer isAuto;

    /**
     * 处理状态
     */
    @ApiModelProperty(value = "处理状态")
    private String billStage;

    /**
     * 审核人
     */
    @ApiModelProperty(value = "审核人")
    private String approver;

    /**
     * 流程
     */
    @ApiModelProperty(value = "流程")
    private String bpmiInstanceId;

    /**
     * 核批结果类型
     */
    @ApiModelProperty(value = "核批结果类型")
    private String approvalResultType;

    /**
     * 核批意见
     */
    @ApiModelProperty(value = "核批意见")
    private String approvalRemark;

    /**
     * 是否通过
     */
    @ApiModelProperty(value = "是否通过")
    private Integer isEffective;

    /**
     * 生效时间
     */
    @ApiModelProperty(value = "生效时间")
    private LocalDateTime effectiveTime;

    /**
     * 已关闭
     */
    @ApiModelProperty(value = "已关闭")
    private Integer isClosed;

    /**
     * 是否作废
     */
    @ApiModelProperty(value = "是否作废")
    private Boolean isVoided;

    /**
     * 创建时间
     */
    @ApiModelProperty(value = "创建时间")
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 创建人
     */
    @ApiModelProperty(value = "创建人")
    private String createBy;

    /**
     * 创建部门
     */
    @ApiModelProperty(value = "创建部门")
    private String sysOrgCode;

    /**
     * 修改时间
     */
    @ApiModelProperty(value = "修改时间")
    private LocalDateTime updateTime;

    /**
     * 修改人
     */
    @ApiModelProperty(value = "修改人")
    private String updateBy;

    /**
     * 版本
     */
    @ApiModelProperty(value = "版本")
    private Integer version;
}
