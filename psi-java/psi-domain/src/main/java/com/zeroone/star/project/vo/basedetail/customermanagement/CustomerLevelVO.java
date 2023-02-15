package com.zeroone.star.project.vo.basedetail.customermanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @Description
 * @auther j2-yizhiyang
 * @date 2023/2/11 22:12
 */
@Data
@ApiModel("查询客户等级的DTO")
public class CustomerLevelVO {
    @ApiModelProperty(value = "客户等级对象ID",example = "000001")
    private String id;
    @ApiModelProperty(value = "客户等级对象名称name",example = "一级")
    private String name;
}
