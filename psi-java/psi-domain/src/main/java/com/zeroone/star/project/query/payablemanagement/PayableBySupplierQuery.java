package com.zeroone.star.project.query.payablemanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author spk
 * @since 2023-02-13 10:42
 * @description 根据供应商查询应付单，位于新增界面
 */

@Data
@ApiModel("根据供应商查询应付单列表")
public class PayableBySupplierQuery {
    @ApiModelProperty(value = "供应商", example = "1623284221748748290")
    private String supplierId;
}