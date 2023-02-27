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

    @ApiModelProperty(value = "高级查询语句",example = "[所属地区]等于[110101]and[欠款额度]小于等于[900]")
    private String advencedQuery;

}