package com.zeroone.star.project.query.patable.purchase;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

/**
 * @author chosen1
 */
@Data
@ApiModel("根据单据编号查询")
public class PayableQuery {
    @NotBlank(message = "单据编号不能为空")
    @ApiModelProperty(value = "单据编号", example = "CGAP-221110-001")
    private String billNO;
}
