package com.zeroone.star.project.vo.basedetail.customermanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @Description 查询客户的编码、名称、助记名、辅助名称
 * @author YinXing
 * @date 2023年02月20日
 */
@Data
@ApiModel("查询客户的编码、名称、助记名、辅助名称")
public class CustomerBaseInfoVO {
    @ApiModelProperty(value = "客户编码",example = "003")
    private String code;

    @ApiModelProperty(value = "客户名称",example = "Microsoft Corporation")
    private String name;

    @ApiModelProperty(value = "助记名", example = "微软")
    private String auxName;

    @ApiModelProperty(value = "辅助名称", example = "百度")
    private String auxiliaryName;

    @ApiModelProperty(value = "启用", example = "1")
    private Integer isEnabled;
}
