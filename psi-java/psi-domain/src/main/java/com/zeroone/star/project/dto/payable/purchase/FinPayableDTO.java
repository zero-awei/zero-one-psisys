package com.zeroone.star.project.dto.payable.purchase;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.fasterxml.jackson.annotation.JsonFormat;
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
 * 描述：采购应付传输数据对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author chose1
 * @version 1.0.0
 */
@Data
@ApiModel("采购应付传输数据对象")
@AllArgsConstructor
@NoArgsConstructor
public class FinPayableDTO {

    /**
     * 单据编号
     */
    @ApiModelProperty(value = "单据编号", example = "CGAP-230218-001")
    private String billNo;

    /**
     * 单据起始日期
     */
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss",timezone="GMT+8")
    @ApiModelProperty(value = "单据起始日期", example = "2023-02-16")
    private Date billDateBegin;

    /**
     * 单据终止日期
     * billDate_end
     */
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss",timezone="GMT+8")
    @ApiModelProperty(value = "单据终止日期", example = "2023-02-16")
    private Date billDateEnd;


    // ---展开后---

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
