package com.zeroone.star.project.dto.homepage;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author Third uncle
 * @date 2023/2/11 - 23:16
 */
@Data
@ApiModel("传输数据对象")
public class HomeDoingBillDTO {
    @ApiModelProperty(value = "名字",example = "销售报价")
    private String name;
    @ApiModelProperty(value = "编制中",example = "0")
    private Integer edit;
    @ApiModelProperty(value = "待核批",example = "0")
    private Integer appr;
    @ApiModelProperty(value = "执行中",example = "0")
    private Integer exec;
}
