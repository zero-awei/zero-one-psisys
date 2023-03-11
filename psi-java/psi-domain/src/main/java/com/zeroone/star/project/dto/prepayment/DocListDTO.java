package com.zeroone.star.project.dto.prepayment;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;
import java.time.LocalDate;
import java.time.LocalDateTime;

/**
 * <p>
 * 描述：单据查询传输对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author husj
 * @version 1.0.0
 */
@Data
@ApiModel("单据查询传输对象")
public class DocListDTO {
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
     * 是否红字
     */
    @ApiModelProperty(value = "是否红字",example = "1")
    private Integer isRubric;
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
     * 备注
     */
    @ApiModelProperty(value = "备注",example = "100.00")
    private String remark;

    /**
     * 是否自动单据
     */
    @ApiModelProperty(value = "是否自动单据",example = "")
    private Integer isAuto;

    /**
     * 处理状态
     */
    @ApiModelProperty(value = "处理状态",example = "执行中")
    private String billStage;

    /**
     * 审核人
     */
    @ApiModelProperty(value = "审核人",example = "管理员")
    private String approver;


    /**
     * 生效时间
     */
    @ApiModelProperty(value = "生效日期",example = "2023-02-08")
    private LocalDateTime effectiveTime;

    /**
     * 已关闭
     */
    @ApiModelProperty(value = "已关闭",example = "1")
    private Integer isClosed;

    /**
     * 是否作废
     */
    @ApiModelProperty(value = "是否作废",example = "")
    private Boolean isVoided;

    /**
     * 创建时间
     */
    @ApiModelProperty(value = "创建时间",example = "2023-02-08")
    private LocalDateTime createTime;

    /**
     * 创建人
     */
    @ApiModelProperty(value = "创建人",example = "管理员")
    private String createBy;

    /**
     * 创建部门
     */
    @ApiModelProperty(value = "创建部门",example = "市场部")
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
