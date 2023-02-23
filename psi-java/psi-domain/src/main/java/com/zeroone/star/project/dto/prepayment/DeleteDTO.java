package com.zeroone.star.project.dto.prepayment;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：删除数据传输对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 出运费
 * @version 1.0.0
 */
@Data
@ApiModel("删除数据传输对象")
public class DeleteDTO {
    @ApiModelProperty(value = "id", example = "10086")
    private String id;
}
