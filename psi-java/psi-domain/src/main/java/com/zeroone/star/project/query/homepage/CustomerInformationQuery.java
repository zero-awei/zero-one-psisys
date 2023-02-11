package com.zeroone.star.project.query.homepage;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：客户信息概况查询对象
 * </p>
 * @author YinXing
 * @date 2023年02月11日
 */
@Data
@ApiModel("客户信息概况查询对象")
public class CustomerInformationQuery {

    @ApiModelProperty(value = "id", example = "1580740609854935042")
    private String id;
}
