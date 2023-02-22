package com.zeroone.star.project.vo.sysmanagement.usermanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.validation.constraints.NotBlank;

/**
 * @ClassName DepartVO
 * @Description 部门列表
 * @Author dan
 * @DATE 2023/2/23 0:15
 * @Version 1.0
 */

@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("用户管理中下拉框部门显示对象")
public class DepartVO {
    /**
     * 主键id
     */
    @NotBlank
    @ApiModelProperty(value = "id", example = "")
    private String id;

    /**
     * 部门名称
     */
    @NotBlank
    @ApiModelProperty(value = "部门名称", example = "市场部")
    private String departName;
}
