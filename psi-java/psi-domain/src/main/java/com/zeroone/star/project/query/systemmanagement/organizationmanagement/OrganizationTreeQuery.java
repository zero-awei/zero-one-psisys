package com.zeroone.star.project.query.systemmanagement.organizationmanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("查询指定组织结构树")
public class OrganizationTreeQuery {

    @ApiModelProperty(name = "部门名称", example = "市场部")
    private String departName;

    @ApiModelProperty(name = "部门父机构ID", example = "北京F公司")
    private String parent_id;
}
