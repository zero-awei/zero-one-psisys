package com.zeroone.star.project.vo.prepayment;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import java.util.List;

/**
 * @Author: Kong
 * @License: (C) Copyright 2005-2019, xxx Corporation Limited.
 * @Contact: xxx@xxx.com
 * @Date: 2023-02-18 11:31
 * @Version: 1.0
 * @Description: 采购列表
 */
@Data
@AllArgsConstructor
@ApiModel("采购列表显示对象")
public class OrderListVO {

    @ApiModelProperty(value = "记录列表",example = "")
    private List<Object> records;

    @ApiModelProperty(value = "记录数",example = "10")
    private Integer total;

}