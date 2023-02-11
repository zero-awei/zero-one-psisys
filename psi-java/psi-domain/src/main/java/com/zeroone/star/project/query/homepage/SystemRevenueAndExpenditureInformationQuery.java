package com.zeroone.star.project.query.homepage;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

/**
 * <p>
 * 描述：系统收支概况查询对象
 * </p>
 * @author YinXing
 * @date 2023年02月11日
 */
@Data
@ApiModel("系统收支概况查询对象")
public class SystemRevenueAndExpenditureInformationQuery {

    @ApiModelProperty(value = "id", example = "1579848144423751681")
    private String id;
}
