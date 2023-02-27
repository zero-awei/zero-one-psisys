package com.zeroone.star.project.query.payablemanagement;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;

/**
 * @author spk
 * @since 2023-02-15
 * @description 根据Id查询应付核销单据详细信息
 */
@Data
@ApiModel("应付核销单据查询")
public class CheckPayableEntryQuery {

    @NotBlank(message = "单据ID不能为空")
    @ApiModelProperty(value = "单据ID", example = "1590728272959815682")
    private String mainId;
}
