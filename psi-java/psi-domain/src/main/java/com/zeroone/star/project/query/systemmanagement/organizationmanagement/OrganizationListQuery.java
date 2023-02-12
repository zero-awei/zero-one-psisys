package com.zeroone.star.project.query.systemmanagement.organizationmanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("查询组织列表")
public class OrganizationListQuery {

    @ApiModelProperty(value = "部门名称", example = "市场部")
    private String departName;
}
