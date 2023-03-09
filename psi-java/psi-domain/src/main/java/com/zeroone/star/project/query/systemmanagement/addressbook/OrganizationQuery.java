package com.zeroone.star.project.query.systemmanagement.addressbook;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import javax.validation.constraints.NotBlank;

/**
 * <p>
 * 描述：组织列表查询对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 西柚珍珠蜜
 * @version 1.0.0
 */

@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("组织列表查询对象")
public class OrganizationQuery extends PageQuery {

    @NotBlank(message = "机构编码")
    @ApiModelProperty(value = "机构编码",example = "A01")
    private String orgCode;


}
