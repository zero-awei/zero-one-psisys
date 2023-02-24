package com.zeroone.star.project.query.prepayment;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import java.time.LocalDate;

/**
 * <p>
 * 描述：单据列表查询对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author husj
 * @version 1.0.0
 */
@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("单据列表查询对象")
public class DocListQuery extends PageQuery {

    /**
     * 单据编号
     */
    @ApiModelProperty(value = "单据编号",example = "")
    private String billNo;

    /**
     * 开始单据日期
     */
    @ApiModelProperty(value = "单据日期（开始）",example = "")
    private String billDateStart;
    /**
     * 结束单据日期
     */
    @ApiModelProperty(value = "单据日期（结束）",example = "")
    private String billDateEnd;

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
     * 处理状态
     */
    @ApiModelProperty(value = "处理状态",example = "")
    private String billStage;
    /**
     * 是否生效(前台数据 后台没有)
     */
    @ApiModelProperty(value = "是否生效",example = "")
    private Integer isEffective;

    /**
     * 已关闭
     */
    @ApiModelProperty(value = "已关闭",example = "")
    private Integer isClosed;

    /**
     * 是否作废
     */
    @ApiModelProperty(value = "是否作废",example = "")
    private Boolean isVoided;

    /**
     * 付款类型
     */
    @ApiModelProperty(value = "付款类型",example = "2011")
    private String paymentType;
}
