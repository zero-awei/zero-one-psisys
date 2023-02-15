package com.zeroone.star.project.query.homepage;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import javax.validation.constraints.NotBlank;

/**
 * @author Third uncle
 * @date 2023/2/11 - 23:18
 */
@Data
@ApiModel("示例查询对象")
public class HomeDoingBillQuery extends PageQuery {
    @ApiModelProperty(value = "姓名", example = "张三")
    private String name;
}
