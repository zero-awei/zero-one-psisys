package com.zeroone.star.project.query.homepage;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：采购概况查询对象
 * </p>
 * @author YinXing
 * @date 2023年02月11日
 */
@Data
@ApiModel("采购概况查询对象")
public class PurchaseInformationQuery {

    @ApiModelProperty(value = "id", example = "1579760837406494722")
    private String id;
}
