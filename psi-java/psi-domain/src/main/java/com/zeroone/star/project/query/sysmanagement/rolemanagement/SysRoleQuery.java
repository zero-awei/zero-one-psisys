package com.zeroone.star.project.query.sysmanagement.rolemanagement;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import java.time.LocalDateTime;

/**
 * @author Gerins
 * @version 1.0.0
 */
@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("角色查询对象")
public class SysRoleQuery extends PageQuery {

    @ApiModelProperty(value = "角色名称", example = "第三方登录角色")
    private String roleName;
    @ApiModelProperty(value = "角色编码", example = "third_role")
    private String roleCode;

}
