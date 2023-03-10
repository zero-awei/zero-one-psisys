package com.zeroone.star.project.query.payablemanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

/**
 * <p>
 * 描述：根据单据编号查询
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author chose1
 * @version 1.0.0
 */
@Data
@ApiModel("根据单据编号查询")
public class PayableBillNoQuery {
    @NotBlank(message = "单据编号不能为空")
    @ApiModelProperty(value = "单据编号", example = "CGAP-221110-001")
    private String billNO;
}
