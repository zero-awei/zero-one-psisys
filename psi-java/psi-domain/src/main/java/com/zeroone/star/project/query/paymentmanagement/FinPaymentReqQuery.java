package com.zeroone.star.project.query.paymentmanagement;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import java.time.LocalDate;

/**
 * @author 白也
 * @title 付款申请查询
 * @date 2023/2/15 8:22 下午
 */

@Data
@EqualsAndHashCode(callSuper = true)
@ApiModel("单据列表查询对象")
public class FinPaymentReqQuery extends PageQuery {
    /**
     * 单据编号
     */
    @ApiModelProperty(value = "单据编号", example = "CGYFSQ-221120-001")
    private String billNo;
    /**
     * 单据日期
     */
    @ApiModelProperty(value = "单据日期", example = "")
    private LocalDate billDate;

    /**
     * 供应商
     */
    @ApiModelProperty(value = "供应商", example = "中石化")
    private String supplierId;
}
