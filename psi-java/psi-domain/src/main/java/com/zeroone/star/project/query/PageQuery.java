package com.zeroone.star.project.query;

import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.validation.constraints.Min;

/**
 * <p>
 * 描述：分页查询父类对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
@Getter
@Setter
@ToString
public class PageQuery {
    @ApiModelProperty(hidden = true)
    @Min(value = 1, message = "页码最小值为1")
    private long pageIndex;
    @ApiModelProperty(hidden = true)
    @Min(value = 1, message = "条数最小值为1")
    private long pageSize;
}
