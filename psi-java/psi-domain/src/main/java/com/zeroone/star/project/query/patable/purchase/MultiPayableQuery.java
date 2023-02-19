package com.zeroone.star.project.query.patable.purchase;

import com.zeroone.star.project.dto.payable.purchase.FinPayableDTO;
import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import javax.validation.constraints.NotBlank;

/**
 * <p>
 * 描述：分页查询应付对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author chose1
 * @version 1.0.0
 */
@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("分页查询应付对象")
public class MultiPayableQuery extends PageQuery {
    @NotBlank(message = "不能为空")
    @ApiModelProperty(value = "应付对象", example = "张三")
    private FinPayableDTO data;
}
