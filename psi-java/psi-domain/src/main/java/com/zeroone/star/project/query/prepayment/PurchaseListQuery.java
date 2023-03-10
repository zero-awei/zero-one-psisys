package com.zeroone.star.project.query.prepayment;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import lombok.ToString;

/**
 * @Author: Kong
 * @License: (C) Copyright 2005-2019, xxx Corporation Limited.
 * @Contact: xxx@xxx.com
 * @Date: 2023-02-11 20:16
 * @Version: 1.0
 * @Description: 采购清单
 */
@ToString
@Data
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("采购清单查询条件")
public class PurchaseListQuery extends PageQuery {

    @ApiModelProperty(value = "timestamp",example = "1594317750844637186")
    private String _t;

    @ApiModelProperty(value = "付款类型",example = "2011")
    private String self_payment_type;

    @ApiModelProperty(value = "已关闭",example = "1")
    private Integer self_is_closed;

    @ApiModelProperty(value = "供应商id",example = "1584950950470164481")
    private String self_supplier_id;

}
