package com.zeroone.star.project.query.basedetail.customermanagement;

import com.zeroone.star.project.query.PageQuery;
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
public class CustomerCdvancedQuery extends PageQuery {

    @ApiModelProperty(value = "高级查询语句",example = "[地区]等于[00101](and)[欠款]小于等于[900](and)[业务地区]在之中[00101,00102]")
    private String advencedQuery;

}