package com.zeroone.star.project.query.payablemanagement;

import com.fasterxml.jackson.annotation.JsonFormat;
import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;
import org.springframework.format.annotation.DateTimeFormat;

import java.util.Date;

/**
 * <p>
 * 描述：分页查询应付对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author chose1
 * @version 1.0.0
 */
@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("分页查询应付对象")
public class PayableQuery extends PageQuery {

    /**
     * 单据编号
     */
    @ApiModelProperty(value = "单据编号", example = "CGAP-221121-001")
    private String billNo;

    /**
     * 单据起始日期
     */
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @JsonFormat
    @ApiModelProperty(value = "单据起始日期", example = "2020-02-13 00:00:00")
    private Date billDateBegin;

    /**
     * 单据终止日期
     * billDate_end
     */
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @JsonFormat
    @ApiModelProperty(value = "单据终止日期", example = "2023-02-13 00:00:00")
    private Date billDateEnd;

    // @JsonFormat
    // @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    // @ApiModelProperty(value = "单据开始日期", example = "2022-01-13 00:00:00")
    // private Date billDate_begin;

    // @JsonFormat
    // @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    // @ApiModelProperty(value = "单据结束日期", example = "2022-01-13 00:00:00")
    // private Date billDate_end;


    // ---展开后---

    /**
     * 单据主题
     */
    @ApiModelProperty(value = "单据主题")
    private String subject;

    /**
     * 供应商
     */
    @ApiModelProperty(value = "供应商", example = "天津化工贸易公司")
    private String supplierId;

    /**
     * 单据阶段
     */
    @ApiModelProperty(value = "单据阶段", example = "执行完")
    private String billStage;

    /**
     * 已生效
     */
    @ApiModelProperty(value = "已生效", example = "1")
    private Integer isEffective;


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
}
