package com.zeroone.star.project.vo.systemmanagement.addressbook;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：组织列表显示对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 西柚珍珠蜜
 * @version 1.0.0
 */

@Data
@ApiModel("组织列表显示对象")
public class OrganizationVO {

    @ApiModelProperty(value = "机构名称",example = "北京 F 公司")
    private String departName;


}
