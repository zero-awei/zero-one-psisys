package com.zeroone.star.project.query.sysmanagement.usermanagement;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import javax.validation.constraints.NotBlank;

@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("用户管理的查询对象")
public class UserQuery extends PageQuery {
    @NotBlank(message = "id不能为空")
    @ApiModelProperty(value = "id", example = "1a2b3")
    private String id;
}
