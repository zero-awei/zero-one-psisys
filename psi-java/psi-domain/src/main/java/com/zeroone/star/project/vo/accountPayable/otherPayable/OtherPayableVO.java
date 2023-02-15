package com.zeroone.star.project.vo.accountPayable.otherPayable;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.math.BigDecimal;
import java.util.Date;

/**
 * 描述：示例视图对象
 *
 * @author:G.
 * @date: 2023/2/13 19:46
 */
@Data
@ApiModel("示例显示对象")
public class OtherPayableVO {
    @ApiModelProperty(value = "单据编号", example = "CGAP-221110-001")
    private String bill_no;

    @DateTimeFormat
    @JsonFormat
    @ApiModelProperty(value = "单据日期", example = "2022-01-13 00:00:00")
    private Date billDate;

    @ApiModelProperty(value = "源单类型", example = "StkIo:101")
    private String srcBillType;

    @ApiModelProperty(value = "源单id", example = "1590717667678928898")
    private String srcBillId;

    @ApiModelProperty(value = "源单号", example = "CGRK-221110-001")
    private String srcNo;

    @ApiModelProperty(value = "单据主题", example = "")
    private String subject;

    @ApiModelProperty(value = "红字单据", example = "0")
    private Integer isRubric;

    @ApiModelProperty(value = "应付类型", example = "201")
    private String payableType;

    @ApiModelProperty(value = "供应商", example = "1584950950470164481")
    private String supplierId;

    @ApiModelProperty(value = "业务部门", example = "A01A03")
    private String opDept;

    @ApiModelProperty(value = "业务员", example = "zhagnxiao")
    private String operator;

    @ApiModelProperty(value = "金额", example = "142000.00")
    private BigDecimal amt;

    @ApiModelProperty(value = "已核销金额", example = "142000.00")
    private BigDecimal checkedAmt;

    @ApiModelProperty(value = "附件", example = "")
    private String attachment;

    @ApiModelProperty(value = "备注", example = "")
    private String remark;

    @ApiModelProperty(value = "自动单据", example = "1")
    private Integer isAuto;

    @ApiModelProperty(value = "单据阶段", example = "34")
    private String billStage;

    @ApiModelProperty(value = "核批人", example = "")
    private String approver;

    @ApiModelProperty(value = "审批实例", example = "")
    private String bpmiInstanceId;

    @ApiModelProperty(value = "核批结果", example = "")
    private String approvalResultType;

    @ApiModelProperty(value = "核批意见", example = "")
    private String approvalRemark;

    @ApiModelProperty(value = "已生效", example = "1")
    private Integer isEffective;

    @DateTimeFormat
    @JsonFormat
    @ApiModelProperty(value = "生效时间", example = "2022-11-10 22:47:19")
    private Date effectiveTime;

    @ApiModelProperty(value = "已关闭", example = "1")
    private Integer isClosed;

    @ApiModelProperty(value = "已作废", example = "0")
    private Integer isVoided;

    @ApiModelProperty(value = "制单部门", example = "A01A03")
    private String sysOrgCode;

    @ApiModelProperty(value = "制单人", example = "admin")
    private String createBy;

    @DateTimeFormat
    @JsonFormat
    @ApiModelProperty(value = "制单时间", example = "2022-11-10 22:47:19")
    @TableField(fill = FieldFill.INSERT)
    private Date createTime;

    @ApiModelProperty(value = "修改人", example = "admin")
    private String updateBy;

    @DateTimeFormat
    @JsonFormat
    @ApiModelProperty(value = "修改时间", example = "2022-11-10 23:29:10")
    private Date updateTime;

    @ApiModelProperty(value = "版本", example = "1")
    private Integer version;
}
