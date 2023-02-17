package com.zeroone.star.project.vo.prepayment;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @Author: Kong
 * @License: (C) Copyright 2005-2019, xxx Corporation Limited.
 * @Contact: xxx@xxx.com
 * @Date: 2023-02-15 11:30
 * @Version: 1.0
 * @Description: 银行账户 字典
 */
@Data
@ApiModel("银行账户显示对象")
public class BasBankAccountVO {
    /**
     * id
     */
    @ApiModelProperty(value = "id",example = "1584915128429649922")
    private String value;

    /**
     * 账号
     */
    @ApiModelProperty(value = "账号",example = "22345678901234567890")
    private String text;
    /**
     * 账号
     */
    @ApiModelProperty(value = "账号",example = "22345678901234567890")
    private String label;
    /**
     * 账号
     */
    @ApiModelProperty(value = "账号",example = "22345678901234567890")
    private String title;
}