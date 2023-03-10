package com.zeroone.star.project.dto.paymentmanagement;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.math.BigDecimal;
import java.time.LocalDate;
import java.time.LocalDateTime;

/*
    author :achuan
*/
@Data
@ApiModel("查询单据列表DTO")
public class QueryDocumentListDTO  {


    private static final long serialVersionUID = 1L;

    /**
     * ID
     */
    @ApiModelProperty(value="ID")
    private String id;

    /**
     * 单据编号
     */
    @ApiModelProperty(value="单据编号")
    private String billNo;

    /**
     * 单据日期
     */
    @ApiModelProperty(value="单据日期")
    private LocalDate billDate;

    /**
     * 源单类型
     */
    @ApiModelProperty(value="源单类型")
    private String srcBillType;

    /**
     * 源单id
     */
    @ApiModelProperty(value="源单ID")
    private String srcBillId;

    /**
     * 源单号
     */
    @ApiModelProperty(value="源单号")
    private String srcNo;
    @ApiModelProperty(value="单据主题")
    private String subject;

    /**
     * 是否红字
     */
    @ApiModelProperty(value="是否红字")
    private Integer isRubric;

    /**
     * 付款类型
     */
    @ApiModelProperty(value="付款类型")
    private String paymentType;

    /**
     * 供应商
     */
    @ApiModelProperty(value="供应商")
    private String supplierId;

    /**
     * 业务部门
     */
    @ApiModelProperty(value="业务部门")
    private String opDept;

    /**
     * 业务员
     */
    @ApiModelProperty(value="业务员")
    private String operator;

    /**
     * 申请金额
     */
    @ApiModelProperty(value="申请金额")
    private BigDecimal amt;

    /**
     * 已付金额
     */
    @ApiModelProperty(value="已付金额")
    private BigDecimal paidAmt;

    /**
     * 附件
     */
    @ApiModelProperty(value="附件")
    private String attachment;

    /**
     * 备注
     */
    @ApiModelProperty(value="备注")
    private String remark;

    /**
     * 是否自动生成
     */
    @ApiModelProperty(value="是否自动生成")
    private Integer isAuto;

    /**
     * 单据阶段
     */
    @ApiModelProperty(value="单据阶段")
    private String billStage;

    /**
     * 审核人
     */
    @ApiModelProperty(value="审核人")
    private String approver;

    /**
     * 审批实例id
     */
    @ApiModelProperty(value="审批实例id")
    private String bpmiInstanceId;

    /**
     * 核批结果类型
     */
    @ApiModelProperty(value="核批结果类型")
    private String approvalResultType;

    /**
     * 核批意见
     */
    @ApiModelProperty(value="核批意见")
    private String approvalRemark;

    /**
     * 是否生效
     */
    @ApiModelProperty(value="是否生效")
    private Integer isEffective;

    /**
     * 生效时间
     */
    @ApiModelProperty(value="生效时间")
    private LocalDateTime effectiveTime;

    /**
     * 已关闭
     */
    @ApiModelProperty(value="已关闭")
    private Integer isClosed;

    /**
     * 是否作废
     */
    @ApiModelProperty(value="是否作废")
    private Integer isVoided;

    /**
     * 创建部门
     */
    @ApiModelProperty(value="创建部门")
    private String sysOrgCode;

    /**
     * 创建人
     */
    @ApiModelProperty(value="创建人")
    private String createBy;

    /**
     * 创建时间
     */
    @ApiModelProperty(value="创建时间")
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 修改人
     */
    @ApiModelProperty(value="修改人")
    private String updateBy;

    /**
     * 修改时间
     */
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @ApiModelProperty(value="修改时间")
    private LocalDateTime updateTime;

    /**
     * 版本
     */
    @ApiModelProperty(value="版本")
    private Integer version;

}
