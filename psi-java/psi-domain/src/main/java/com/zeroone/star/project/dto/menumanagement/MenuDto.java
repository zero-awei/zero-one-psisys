package com.zeroone.star.project.dto.menumanagement;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * <p>
 * 描述：菜单信息封装
 * </p>
 *
 * @author 归
 * @version 1.0.0
 */

@ApiModel("上传数据对象")
@Data
@NoArgsConstructor
@AllArgsConstructor
public class MenuDto {
    @ApiModelProperty(value = "序号",example = "1")
    private Integer id;
    @ApiModelProperty(value = "菜单名称",example ="获取菜单" )
    private String name;
    @ApiModelProperty(value = "路由地址",example = "")
    private String path;
    @ApiModelProperty(value ="xx.jpg" ,example ="" )
    private String icon;
    @ApiModelProperty(value = "父级",example ="" )
    private Integer parentMenuId;
}
