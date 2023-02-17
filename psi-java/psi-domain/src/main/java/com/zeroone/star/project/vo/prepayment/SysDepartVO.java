package com.zeroone.star.project.vo.payment;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @Author: Kong
 * @License: (C) Copyright 2005-2019, xxx Corporation Limited.
 * @Contact: xxx@xxx.com
 * @Date: 2023-02-15 11:27
 * @Version: 1.0
 * @Description: 组织机构表 字典
 */
@Data
@ApiModel("组织机构显示对象")
public class SysDepartVO {
    /**
     * 机构编码
     */
    @ApiModelProperty(value = "机构编码",example = "A01A03")
    private String value;

    /**
     * 机构/部门名称
     */
    @ApiModelProperty(value = "机构/部门名称",example = "市场部")
    private String text;
    /**
     * 机构/部门名称
     */
    @ApiModelProperty(value = "机构/部门名称",example = "市场部")
    private String label;
    /**
     * 机构/部门名称
     */
    @ApiModelProperty(value = "机构/部门名称",example = "市场部")
    private String title;
}