package com.zeroone.star.project.vo.prepayment;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;

/**
 * @Author: Kong
 * @License: (C) Copyright 2005-2019, xxx Corporation Limited.
 * @Contact: xxx@xxx.com
 * @Date: 2023-02-15 11:19
 * @Version: 1.0
 * @Description: 用户表 字典
 */
@Data
@AllArgsConstructor
@ApiModel("系统用户显示对象")
public class SysUserVO {
    /**
     * 登录账号
     */
    @ApiModelProperty(value = "用户名",example = "liyewu")
    private String value;

    /**
     * 真实姓名
     */
    @ApiModelProperty(value = "真实姓名",example = "李业武")
    private String text;
    /**
     * 真实姓名
     */
    @ApiModelProperty(value = "真实姓名",example = "李业武")
    private String label;
    /**
     * 真实姓名
     */
    @ApiModelProperty(value = "真实姓名",example = "李业武")
    private String title;

}