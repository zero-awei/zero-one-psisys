package com.zeroone.star.project.dto.basedetail.customermanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @Description
 * @Author mumu
 * @Data 2023-02-13 11:38
 */
@Data
@ApiModel("查询客户等级DTO")
public class CustomerLevelDTO {
    @ApiModelProperty(value = "客户等级对象ID",example = "000001")
    private String id;
    @ApiModelProperty(value = "客户等级对象名称name",example = "一级")
    private String name;
}