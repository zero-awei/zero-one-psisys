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
 * 描述：示例查询对象
 *
 * @author:G.
 * @date: 2023/2/13 19:39
 */
@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("示例查询对象")
public class PayableQuery extends PageQuery {
    @ApiModelProperty(value = "单据编号", example = "CGAP-221110-001")
    private String bill_no;

    @JsonFormat
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "单据开始日期", example = "2022-01-13 00:00:00")
    private Date billDate_begin;

    @JsonFormat
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "单据结束日期", example = "2022-01-13 00:00:00")
    private Date billDate_end;

    @ApiModelProperty(value = "单据主题", example = "")
    private String subject;

    @ApiModelProperty(value = "供应商", example = "1584950950470164481")
    private String supplierId;

    @ApiModelProperty(value = "单据阶段", example = "34")
    private String billStage;

    @ApiModelProperty(value = "已生效", example = "1")
    private Integer isEffective;

    @ApiModelProperty(value = "已关闭", example = "1")
    private Integer isClosed;

    @ApiModelProperty(value = "已作废", example = "0")
    private Integer isVoided;
}