package com.zeroone.star.project.query.basedetail.customermanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：根据name查询客户信息
 * </p>
 * @auther YinXing
 * @date 2023/2/11 21:32
 */
@Data
@ApiModel("根据名称查询客户信息")
public class CustomerByNameQuery {

    @ApiModelProperty(value = "客户名称",example = "Microsoft Corporation")
    private String name;
}
