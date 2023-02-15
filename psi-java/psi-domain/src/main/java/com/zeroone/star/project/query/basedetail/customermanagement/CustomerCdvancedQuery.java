package com.zeroone.star.project.query.basedetail.customermanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @Description
 * @auther j2-yizhiyang
 * @date 2023/2/11 22:16
 */
@Data
@ApiModel("高级查询客户Query")
public class CustomerCdvancedQuery {

    @ApiModelProperty(value = "高级查询语句",example = "[地区]等于[00101]and[欠款]小于等于[900]")
    private String advencedQuery;

    @ApiModelProperty(value = "分页规模PageSize",example = "10")
    private Integer PageSize;

    @ApiModelProperty(value = "当前页面PageNo",example = "1")
    private Integer PageNo;
}