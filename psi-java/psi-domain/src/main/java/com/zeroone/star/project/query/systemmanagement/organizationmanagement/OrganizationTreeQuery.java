package com.zeroone.star.project.query.systemmanagement.organizationmanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：查询指定组织结构树
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author Morrangee
 * @version 1.0.0
 */
@Data
@ApiModel("查询指定组织结构树")
public class OrganizationTreeQuery {

    @ApiModelProperty(value = "部门名称", example = "市场部")
    private String departName;

    @ApiModelProperty(value = "部门父机构ID", example = "北京F公司")
    private String parent_id;
}
