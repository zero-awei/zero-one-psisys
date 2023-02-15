package com.zeroone.star.project.query.user;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import javax.validation.constraints.NotBlank;

@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("用户管理中编辑的查询对象")
public class EditUserQuery extends PageQuery {
    @NotBlank(message = "id不能为空")
    @ApiModelProperty(value = "id", example = "1a2b3")
    private String id;
}
