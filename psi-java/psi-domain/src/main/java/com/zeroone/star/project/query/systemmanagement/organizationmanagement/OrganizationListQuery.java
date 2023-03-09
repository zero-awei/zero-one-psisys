package com.zeroone.star.project.query.systemmanagement.organizationmanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：查询组织列表
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author Morrangee
 * @version 1.0.0
 */
@Data
@ApiModel("查询组织列表")
public class OrganizationListQuery {

    @ApiModelProperty(value = "部门名称", example = "市场部")
    private String departName;
}
