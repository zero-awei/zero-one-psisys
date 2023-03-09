package com.zeroone.star.project.query.basedetail.customermanagement;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @Description 客户普通查询Query
 * @auther j2-yizhiyang
 * @date 2023/2/11 21:32
 */

@Data
@ApiModel("查询客户Query")
public class CustomerQuery extends PageQuery {

    @ApiModelProperty(value = "客户编码code",example = "001")
    private String code;

    @ApiModelProperty(value = "客户名称name",example = "天津日化公司")
    private String name;

    @ApiModelProperty(value = "客户分类customer_category(传回的时分类的id)",example = "001")

    private String customerCategory;

    @ApiModelProperty(value = "客户分类customer_level(传回来的是等级的id)",example = "001")
    private String customerLevel;

    @ApiModelProperty(value = "客户纳税规模tax_scale",example = "一般纳税人")
    private String taxScale;

    @ApiModelProperty(value = "客户所属地区area",example = "110101")
    private String area;

    @ApiModelProperty(value = "业务所属地区area",example = "110101")
    private String bizArea;

}
