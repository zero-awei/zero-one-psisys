package com.zeroone.star.project.query.payablemanagement;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

/**
 * @author spk
 * @since 2023-02-13 10:42
 * @description 根据供应商查询应付单，位于新增界面
 */

@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("根据供应商查询应付单列表")
public class PayableBySupplierQuery extends PageQuery {
    @ApiModelProperty(value = "供应商", example = "1584950950470164481")
    private String supplierId;
}
