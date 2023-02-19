package com.zeroone.star.project.query.basedetail.customermanagement;

import io.swagger.annotations.Api;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigInteger;

/**
 * @Description 添加customer
 * @author YinXing
 * @date 2023年02月19日
 */
@Data
@ApiModel("添加客户")
public class CustomerAdd {
    @ApiModelProperty(value = "客户编码",example = "003")
    private String code;

    @ApiModelProperty(value = "客户名称",example = "Microsoft Corporation")
    private String name;

    @ApiModelProperty(value = "助记名", example = "微软")
    private String auxName;

    @ApiModelProperty(value = "客户分类",example = "001")
    private String customerCategory;

    @ApiModelProperty(value = "客户分类",example = "001")   //?
    private String customerLevel;

    @ApiModelProperty(value = "客户纳税规模",example = "一般纳税人")
    private String taxScale;

    @ApiModelProperty(value = "欠款额度",example = "100000")
    private BigInteger creditQuota;

    @ApiModelProperty(value = "启用", example = "1")
    private Integer isEnabled;

    @ApiModelProperty(value = "备注", example = "欠款未还")
    private String remark;
}
