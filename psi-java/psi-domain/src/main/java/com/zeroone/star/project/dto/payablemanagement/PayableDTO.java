package com.zeroone.star.project.dto.payablemanagement;

import com.fasterxml.jackson.annotation.JsonFormat;
import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.format.annotation.DateTimeFormat;

import java.math.BigDecimal;
import java.time.LocalDateTime;
import java.util.Date;

/**
 * <p>
 * 描述：采购应付数据传输对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author chose1, spk
 * @version 1.0.0
 * @description merged，包括采购和其他
 */
@Data
@ApiModel("应付数据传输对象")
@AllArgsConstructor
@NoArgsConstructor
public class PayableDTO {

    // 
    // /**
    //  * 单据起始日期
    //  */
    // @DateTimeFormat(pattern = "yyyy-MM-dd")
    // @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss",timezone="GMT+8")
    // @ApiModelProperty(value = "单据起始日期", example = "2023-02-16")
    // private Date billDateBegin;

    // /**
    //  * 单据终止日期
    //  * billDate_end
    //  */
    // @DateTimeFormat(pattern = "yyyy-MM-dd")
    // @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss",timezone="GMT+8")
    // @ApiModelProperty(value = "单据终止日期", example = "2023-02-16")
    // private Date billDateEnd;

    /*
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
    @ApiModelProperty(value = "单据主题", example = "123")
    private String subject;

    /**
     * 供应商
     */
    @ApiModelProperty(value = "供应商", example = "1584950950470164481")
    private String supplierId;

    /**
     * 单据阶段
     */
    @ApiModelProperty(value = "单据阶段", example = "34")
    private String billStage;

    /**
     * 已生效
     */
    @ApiModelProperty(value = "已生效", example = "1")
    private Integer isEffective;

    /**
     * 是否红字
     */
    @ApiModelProperty(value = "是否红字", example = "1")
    private Integer isRubric;

    /**
     * 应付类型
     */
    @ApiModelProperty(value = "应付类型", example = "201")
    private String payableType;


    @ApiModelProperty(value = "业务部门", example = "A01")
    private String opDept;

    /**
     * 业务员
     */
    @ApiModelProperty(value = "业务员", example = "jeecg")
    private String operator;

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

    /**
     * 审核人
     */
    @ApiModelProperty(value = "审核人", example = "psi")
    private String approver;

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

    /**
     * 核批意见
     */
    @ApiModelProperty(value = "核批意见")
    private String approvalRemark;

    /**
     * 生效时间
     */
    @ApiModelProperty(value = "生效时间")
    private LocalDateTime effectiveTime;

    /**
     * 已关闭
     */
    @ApiModelProperty(value = "已关闭", example = "1")
    private Integer isClosed;


    /**
     * 已作废
     */
    @ApiModelProperty(value = "已作废", example = "0")
    private Integer isVoided;


    /**
     * 创建部门
     */
    @ApiModelProperty(value = "创建部门", example = "A01A05")
    private String sysOrgCode;

    /**
     * 创建人
     */
    @ApiModelProperty(value = "创建人", example = "psi")
    private String createBy;

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
