package com.zeroone.star.project.vo.payablemanagement;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;
import java.time.LocalDateTime;

/**
 * <p>
 * 描述：采购应付显示对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author chose1, spk
 * @version 1.0.0
 */
@ApiModel("应付显示对象")
@Data
public class PayableVO {

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
    @ApiModelProperty(value = "源单类型", example = "采购退货出库")
    private String srcBillTypeDictText;

    /**
     * 源单号
     */
    @ApiModelProperty(value = "源单号", example = "CGRK-230212-007")
    private String srcNo;

    /**
     * 单据主题
     */
    @ApiModelProperty(value = "单据主题", example = "tittle123")
    private String subject;

    /**
     * 是否红字
     */
    @ApiModelProperty(value = "是否红字", example = "1")
    private String isRubric;
    @ApiModelProperty(value = "是否红字", example = "是")
    private String isRubricDictText;

    /**
     * 供应商
     */
    @ApiModelProperty(value = "供应商", example = "01教育")
    private String supplierIdDicText;

    /**
     * 业务部门
     */
    @ApiModelProperty(value = "业务部门", example = "北京 F 公司")
    private String opDeptDictText;

    /**
     * 业务员
     */
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
    private String isAuto;
    @ApiModelProperty(value = "是否自动生成", example = "是")
    private String isAutoDictText;

    /**
     * 处理状态
     */
    @ApiModelProperty(value = "处理状态", example = "执行中")
    private String billStageDictText;

    /**
     * 审核人
     */
    @ApiModelProperty(value = "审核人", example = "管理员")
    private String approverDictText;

    /**
     * 是否通过
     */
    @ApiModelProperty(value = "是否通过", example = "1")
    private String isEffective;
    @ApiModelProperty(value = "是否通过", example = "是")
    private String isEffectiveDictText;

    /**
     * 核批结果类型
     */
    @ApiModelProperty(value = "核批结果类型")
    private String approvalResultType;
    private String approvalResultTypeDictText;

    /**
     * 核批意见
     */
    @ApiModelProperty(value = "核批意见")
    private String approvalRemark;

    /**
     * 生效时间
     */
    @ApiModelProperty(value = "生效时间", example = "2022-11-10 22:47:19")
    private LocalDateTime effectiveTime;

    /**
     * 已关闭
     */
    @ApiModelProperty(value = "已关闭", example = "0")
    private String isClosed;
    @ApiModelProperty(value = "已关闭", example = "否")
    private String isClosedDictText;

    /**
     * 是否作废
     */
    @ApiModelProperty(value = "是否作废", example = "0")
    private String isVoided;
    @ApiModelProperty(value = "是否作废", example = "否")
    private String isVoidedDictText;

    /**
     * 创建部门
     */
    @ApiModelProperty(value = "创建部门", example = "研发部")
    private String sysOrgCodeDictText;

    /**
     * 创建人
     */
    @ApiModelProperty(value = "创建人", example = "管理员")
    private String createByDictText;

    /**
     * 创建时间
     */
    @ApiModelProperty(value = "创建时间", example = "2022-11-10 22:47:19")
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 修改人
     */
    @ApiModelProperty(value = "修改人", example = "管理员")
    private String updateByDictText;

    /**
     * 修改时间
     */
    @ApiModelProperty(value = "修改时间", example = "2022-11-10 23:29:10")
    private LocalDateTime updateTime;

}
