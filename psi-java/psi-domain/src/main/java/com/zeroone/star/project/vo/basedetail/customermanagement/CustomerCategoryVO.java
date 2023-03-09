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
@ApiModel("查询客户分类的VO")
public class CustomerCategoryVO {

    @ApiModelProperty(value = "客户分类对象ID",example = "000001")
    private String id;
    @ApiModelProperty(value = "客户分类对象名称name",example = "VIP")
    private String name;
}
