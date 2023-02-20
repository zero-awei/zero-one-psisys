package com.zeroone.star.project.vo.paymentmanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;
import java.time.LocalDate;
import java.time.LocalDateTime;

/*
    author :achuan
*/
@Data
@ApiModel("查询单据列表VO")
public class QueryDocumentListVO  {
    /**
     * 单据编号
     */
    @ApiModelProperty(value = "单据编号",example = "CGYF-230208-020")
    private String billNo;

    /**
     * 单据日期
     */
    @ApiModelProperty(value = "单据日期",example = "2023-02-08")
    private LocalDate billDate;

    /**
     * 单据主题
     */
    @ApiModelProperty(value = "单据主题",example = "")
    private String subject;

    /**
     * 供应商
     */
    @ApiModelProperty(value = "供应商",example = "")
    private String supplierId;

    /**
     * 金额
     */
    @ApiModelProperty(value = "金额",example = "100.00")
    private BigDecimal amt;


    /**
     * 已核销金额
     */
    @ApiModelProperty(value = "已核销金额",example = "0.00")
    private BigDecimal checkedAmt;


    /**
     * 单据阶段
     */
    @ApiModelProperty(value = "单据阶段",example = "执行中")
    private String billStage;


    /**
     * 已生效
     */
    @ApiModelProperty(value = "已生效",example = "1")
    private Integer isEffective;

    /**
     * 已关闭
     */
    @ApiModelProperty(value = "已关闭",example = "1")
    private Integer isClosed;

    /**
     * 已作废
     */
    @ApiModelProperty(value = "已作废",example = "1")
    private Integer isVoided;

    /**
     * 自动单据 是否？
     */
    @ApiModelProperty(value = "自动单据 ",example = "1")
    private Integer isAuto;

    /**
     * 红字单据  是否？
     */
    @ApiModelProperty(value = "红字单据 ",example = "1")
    private Integer isRubric;

    /**
     * 备注
     */
    @ApiModelProperty(value = "备注",example = "100.00")
    private String remark;

    /**
     * 生效时间
     */
    @ApiModelProperty(value = "生效时间",example = "2012.2.2")
    private LocalDateTime effectiveTime;

    /**
     * 审核人
     */
    @ApiModelProperty(value = "审核人",example = "管理员")
    private String approver;

    /**
     * 制单人
     */
    @ApiModelProperty(value = "制单人",example = "管理员")
    private String createBy;
    /**
     * 制单部门
     */
    @ApiModelProperty(value = "制单部门",example = "弹法")
    private String sysOrgCode;
    /**
     * 修改时间
     */
    @ApiModelProperty(value = "修改时间",example = "2023-02-08")
    private LocalDateTime updateTime;

    /**
     * 修改人
     */
    @ApiModelProperty(value = "修改人",example = "管理员")
    private String updateBy;
}
