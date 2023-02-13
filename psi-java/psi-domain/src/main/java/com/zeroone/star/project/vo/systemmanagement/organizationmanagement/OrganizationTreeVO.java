package com.zeroone.star.project.vo.systemmanagement.organizationmanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：展示查询组织列表
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author Morrangee
 * @version 1.0.0
 */
@Data
@ApiModel("展示查询组织列表")
public class OrganizationTreeVO {

    @ApiModelProperty(name = "机构/部门名称", example = "市场部")
    private String departName;

    @ApiModelProperty(name = "父机构ID", example = "c6d7cb4d411cb3384b1b31278596")
    private String parentId;
}
