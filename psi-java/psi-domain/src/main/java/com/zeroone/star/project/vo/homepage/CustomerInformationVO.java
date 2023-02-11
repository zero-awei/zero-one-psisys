package com.zeroone.star.project.vo.homepage;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：客户信息概况显示对象
 * </p>
 * @author YinXing
 * @date 2023年02月11日
 */
@Data
@ApiModel("客户信息概况显示对象")
public class CustomerInformationVO {

    @ApiModelProperty(value = "类型", example = "今日客户")
    private String label;

    @ApiModelProperty(value = "客户数量", example = "1")
    private Integer value;
}
