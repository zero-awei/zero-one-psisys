package com.zeroone.star.project.query.paymentmanagement;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDate;

/**
 * @author 白也
 * @title
 * @date 2023/2/24 6:02 下午
 */
@ApiModel(description = "")
@Data
public class StkIoQuery extends PageQuery {
    /**
     * 单据编号
     */
    @ApiModelProperty("单据编号")
    private String billNo;
    /**
     * 单据日期
     */
    @ApiModelProperty("单据日期")
    private LocalDate billDate;

    /**
     * 供应商
     */
    @ApiModelProperty("供应商")
    private String supplierId;
}
