package com.zeroone.star.project.vo.systemmanagement.organizationmanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("展示查询组织列表")
public class OrganizationTreeVO {

    @ApiModelProperty(name = "机构/部门名称", example = "市场部")
    private String depart_name;

    @ApiModelProperty(name = "父机构ID", example = "c6d7cb4d411cb3384b1b31278596")
    private String parent_id;
}
