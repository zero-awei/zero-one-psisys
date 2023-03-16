package com.zeroone.star.project.query.sysmanagement.usermanagement;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import javax.validation.constraints.NotBlank;

/**
 * <p>
 * 用户表 用户管理的查询对象
 * </p>
 *
 * @author  axin
 * @since 2023-02-18
 */
@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("用户管理的查询对象")
public class UserQuery extends PageQuery {

    @ApiModelProperty(value = "id", example = "e9ca23d68d884d4ebb19d07889727dae")
    private String id;
}
