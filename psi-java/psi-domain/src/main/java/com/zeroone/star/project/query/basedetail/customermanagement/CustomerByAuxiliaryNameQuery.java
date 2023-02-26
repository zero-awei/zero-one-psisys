package com.zeroone.star.project.query.basedetail.customermanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：根据辅助名称查询客户信息
 * </p>
 * @auther YinXing
 * @date 2023/2/11 21:32
 */
@Data
@ApiModel("根据辅助名称查询客户信息")
public class CustomerByAuxiliaryNameQuery {
    @ApiModelProperty(value = "辅助名称", example = "百度")
    private String auxiliaryName;
}
