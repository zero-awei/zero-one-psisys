package com.zeroone.star.project.query.homepage;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：销售概况查询对象
 * </p>
 * @author YinXing
 * @date 2023年02月11日
 */
@Data
@ApiModel("销售概况查询对象")
public class SaleInformationQuery {

    @ApiModelProperty(value = "id", example = "1579758928603910145")
    private String id;
}
