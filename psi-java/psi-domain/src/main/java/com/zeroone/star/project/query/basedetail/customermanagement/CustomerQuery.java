package com.zeroone.star.project.query.basedetail.customermanagement;

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
public class CustomerQuery {

    @ApiModelProperty(value = "客户编码code",example = "001")
    private String code;

    @ApiModelProperty(value = "客户名称name",example = "天津日化公司")
    private String name;

    @ApiModelProperty(value = "客户分类customer_category(传回的时分类的id)",example = "001")
    private String CustomerCategory;

    @ApiModelProperty(value = "客户分类customer_level(传回来的是等级的id)",example = "001")
    private String CustomerLevel;

    @ApiModelProperty(value = "客户纳税规模tax_scale",example = "一般纳税人")
    private String TaxScale;

    @ApiModelProperty(value = "客户所属地区area",example = "110101")
    private String area;

    @ApiModelProperty(value = "业务所属地区area",example = "110101")
    private String bizArea;

    @ApiModelProperty(value = "分页规模PageSize",example = "10")
    private Integer PageSize;

    @ApiModelProperty(value = "当前页面PageNo",example = "1")
    private Integer PageNo;
}
