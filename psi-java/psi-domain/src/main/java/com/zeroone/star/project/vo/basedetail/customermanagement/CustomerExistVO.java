package com.zeroone.star.project.vo.basedetail.customermanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @Description 判断客户是否存在
 * @author YinXing
 * @date 2023年02月21日
 */
@Data
@ApiModel("判断客户是否存在")
public class CustomerExistVO {

    @ApiModelProperty(value = "客户是否存在", example = "true")
    private Boolean isExist;
}
