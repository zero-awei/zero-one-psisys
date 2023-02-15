package com.zeroone.star.project.dto.systemmanagement.customermanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @Description
 * @Author mumu
 * @Data 2023-02-13 11:38
 */
@Data
@ApiModel("查询客户分类DTO")
public class CustomerCategoryDTO {
    @ApiModelProperty(value = "客户分类对象ID",example = "000001")
    private String id;
    @ApiModelProperty(value = "客户分类对象名称name",example = "VIP")
    private String name;
}
