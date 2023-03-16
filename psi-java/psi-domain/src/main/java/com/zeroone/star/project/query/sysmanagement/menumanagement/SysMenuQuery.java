package com.zeroone.star.project.query.sysmanagement.menumanagement;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.fasterxml.jackson.annotation.JsonFormat;
import com.zeroone.star.project.query.PageQuery;
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
public class SysMenuQuery extends PageQuery {

    @TableId(type = IdType.ASSIGN_UUID)
    @ApiModelProperty(value = "菜单id", example = "2")
    private String id; // 菜单id

    @ApiModelProperty(value = "父id",example = "1")
    private String parentId;

    @ApiModelProperty(value = "菜单名",example = "菜单1")
    @NotBlank(message = "菜单名不能为空")
    private String name; // 菜单名

}
