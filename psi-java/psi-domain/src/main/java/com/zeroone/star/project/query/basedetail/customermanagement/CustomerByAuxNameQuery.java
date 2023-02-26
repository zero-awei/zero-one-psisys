package com.zeroone.star.project.query.basedetail.customermanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：根据助记名查询客户信息
 * </p>
 * @auther YinXing
 * @date 2023/2/11 21:32
 */
@Data
@ApiModel("根据助记名查询客户信息")
public class CustomerByAuxNameQuery {
    @ApiModelProperty(value = "助记名", example = "微软")
    private String auxName;
}
