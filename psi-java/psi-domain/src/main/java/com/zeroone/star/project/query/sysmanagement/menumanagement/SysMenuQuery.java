package com.zeroone.star.project.query.sysmanagement.menumanagement;

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
 * @author gui & mid9dreamer
 * @version 1.0
 */
@ApiModel("查询菜单对象")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class SysMenuQuery {

    @TableId(type = IdType.ASSIGN_UUID)
    @ApiModelProperty(value = "菜单id,不传参")
    private String id; // 菜单id

    @ApiModelProperty(value = "父id",example = "00a2a0ae65cdca5e93209cdbde97cbe6")
    @NotBlank(message = "父id不能为空")
    private String parentId;

    @ApiModelProperty(value = "菜单名",example = "菜单1")
    @NotBlank(message = "菜单名不能为空")
    private String name; // 菜单名

    @ApiModelProperty(value = "url路径",example = "/main/1")
    @NotBlank(message = "菜单url不能为空")
    private String url; // url

    @ApiModelProperty(value = "图标")
    private String icon; // 图标

    @ApiModelProperty(value = "排序",example = "1.10")
    private Double sortNo; // 排序

    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @TableField(update = "NOW()")
    @ApiModelProperty(value = "创建时间，不传递参数")
    private LocalDateTime createTime; // 创建时间

    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @TableField(update = "NOW()")
    @ApiModelProperty(value = "修改时间,不传递参数")
    private LocalDateTime updateTime; // 修改时间
}
