package com.zeroone.star.project.vo.prepayment;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.List;

/**
 * @ClassName DetHavVO
 * @Description 查询订单详情-有申请
 * @Author HZP
 * @Date 2023/2/12 11:30
 * @Version 1.0
 **/
@Data
@ApiModel("有申请显示对象")
public class DetHavVO {

    /**
     * 单据编号
     */
    @ApiModelProperty(value = "单据编号",example = "CGFK-221110-001")
    private String billNo;

    /**
     * 单据日期
     */
    @ApiModelProperty(value = "单据日期",example = "2022-11-11")
    private LocalDate billDate;

    /**
     * 单据主题
     */
    @ApiModelProperty(value = "单据主题",example = "")
    private String subject;

    /**
     * 是否红字
     */
    @ApiModelProperty(value = "红字单据",example = "1")
    private Integer isRubric;

    /**
     * 供应商
     */
    @ApiModelProperty(value = "供应商",example = "光缆厂家1")
    private String supplierId;

    /**
     * 已核销金额
     */
    @ApiModelProperty(value = "已核销金额",example = "0")
    private BigDecimal checkedAmt;

    /**
     * 附件
     */
    @ApiModelProperty(value = "附件",example = "--")
    private String attachment;

    /**
     * 备注
     */
    @ApiModelProperty(value = "备注",example = "")
    private String remark;

    /**
     * 是否自动单据
     */
    @ApiModelProperty(value = "自动单据",example = "1")
    private Integer isAuto;

    /**
     * 审批实例
     */
    @ApiModelProperty(value = "审批实例",example = "")
    private String bpmiInstance;

    /**
     * 审核人
     */
    @ApiModelProperty(value = "核批人",example = "")
    private String approver;

    /**
     * 核批结果类型
     */
    @ApiModelProperty(value = "核批结果",example = "")
    private String approvalResultType;

    /**
     * 核批意见
     */
    @ApiModelProperty(value = "核批意见",example = "")
    private String approvalRemark;

    /**
     * 是否通过
     */
    @ApiModelProperty(value = "已生效",example = "1")
    private Integer isEffective;

    /**
     * 生效时间
     */
    @ApiModelProperty(value = "生效时间",example = "2022-11-12")
    private LocalDateTime effectiveTime;

    /**
     * 已关闭
     */
    @ApiModelProperty(value = "已关闭",example = "1")
    private Integer isClosed;

    /**
     * 是否作废
     */
    @ApiModelProperty(value = "已作废",example = "false")
    private Boolean isVoided;

    /**
     * 创建时间
     */
    @ApiModelProperty(value = "制单时间",example = "")
    private LocalDateTime createTime;

    /**
     * 创建人
     */
    @ApiModelProperty(value = "制单人",example = "管理员")
    private String createBy;

    /**
     * 创建部门
     */
    @ApiModelProperty(value = "制单部门",example = "研发部")
    private String sysOrgCode;

    /**
     * 修改时间
     */
    @ApiModelProperty(value = "修改时间",example = "")
    private LocalDateTime updateTime;

    /**
     * 修改人
     */
    @ApiModelProperty(value = "修改人",example = "")
    private String updateBy;

    @ApiModelProperty(value = "明细",example = "")
    private List<FinPaymentEntryVO> listDetail;

    @ApiModelProperty(value = "采购预付申请单",example = "")
    private  FinPaymentReqVO req;
}
