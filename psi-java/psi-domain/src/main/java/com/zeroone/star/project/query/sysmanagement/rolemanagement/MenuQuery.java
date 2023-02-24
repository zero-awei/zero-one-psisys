package com.zeroone.star.project.query.sysmanagement.rolemanagement;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.validation.constraints.NotBlank;
import java.time.LocalDateTime;

/**
*
* @Author:阿狸
* @Version:1.1
*/
@ApiModel("编辑菜单对象")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class MenuQuery  {

    /**
     * 菜单id
     */
    @TableId(type = IdType.ASSIGN_UUID)
    @ApiModelProperty(value = "菜单id,不传参")
    private String id;

    /**
     * 父id
     */
    @ApiModelProperty(value = "父id",example = "00a2a0ae65cdca5e93209cdbde97cbe6")
    @NotBlank(message = "父id不能为空")
    private String parentId;

    /**
     * 菜单名
     */
    @ApiModelProperty(value = "菜单名",example = "菜单1")
    @NotBlank(message = "菜单名不能为空")
    private String name;

    /**
     * url
     */
    @ApiModelProperty(value = "url路径",example = "/main/1")
    @NotBlank(message = "菜单url不能为空")
    private String url;

    /**
     * 图标
     */
    @ApiModelProperty(value = "图标")
    private String icon;

    /**
     * 排序
     */
    @ApiModelProperty(value = "排序",example = "1.10")
    private Double sortNo;

    /**
     * 创建时间，不需要传递参数
     */
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @TableField(update = "NOW()")
    @ApiModelProperty(value = "创建时间，不传递参数")
    private LocalDateTime createTime;

    /**
     * 修改时间，不需要传递参数
     */
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @TableField(update = "NOW()")
    @ApiModelProperty(value = "修改时间,不传递参数")
    private LocalDateTime updateTime;
}
