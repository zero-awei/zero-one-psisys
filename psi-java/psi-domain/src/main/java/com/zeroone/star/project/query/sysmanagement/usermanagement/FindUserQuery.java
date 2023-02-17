package com.zeroone.star.project.query.sysmanagement.usermanagement;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import javax.validation.constraints.NotBlank;

@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("查询功能对象")
public class FindUserQuery extends PageQuery {
    @NotBlank(message = "查询内容不能为空")
    @ApiModelProperty(value = "name", example = "张三")
    private String name;
}
