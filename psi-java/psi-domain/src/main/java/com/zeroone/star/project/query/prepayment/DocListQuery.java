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
    @ApiModelProperty(value = "单据编号")
    private String billNo;

    /**
     * 开始单据日期
     */
    @ApiModelProperty(value = "单据日期（开始）")
    private String billDateStart;
    /**
     * 结束单据日期
     */
    @ApiModelProperty(value = "单据日期（结束）")
    private String billDateEnd;

    /**
     * 单据主题
     */
    @ApiModelProperty(value = "单据主题")
    private String subject;
    /**
     * 供应商
     */
    @ApiModelProperty(value = "供应商")
    private String supplierId;
    /**
     * 处理状态
     */
    @ApiModelProperty(value = "处理状态")
    private String billStage;
    /**
     * 是否生效(前台数据 后台没有)
     */
    @ApiModelProperty(value = "是否生效")
    private Integer isEffective;

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
     * 付款类型
     */
    @ApiModelProperty(value = "付款类型")
    private String paymentType;
}
