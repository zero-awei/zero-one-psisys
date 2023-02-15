package com.zeroone.star.role.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import lombok.ToString;

import java.io.Serializable;
import java.util.Date;

@ToString
@Data
@ApiModel("编辑菜单对象")
@NoArgsConstructor
@AllArgsConstructor
public class SysMenu implements Serializable {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "菜单id",example = "1")
    private String id; // 菜单id

    @ApiModelProperty(value = "父id",example = "1")
    private String ParentId;

    @ApiModelProperty(value = "菜单名",example = "销售管理")
    private String Name; // 菜单名

    @ApiModelProperty(value = "url",example = "本菜单的访问路径")
    private String Url; // url

    @TableField(update = "😀")
    @ApiModelProperty(value = "图标，不传参",example = "😀")
    private String Icon; // 图标

    @TableField(update = "1.00") // 升序
    @ApiModelProperty(value = "排序",example = "1.00")
    private Double sortNo; // 排序

    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @TableField(update = "NOW()")
    @ApiModelProperty(value = "创建时间，不传参",example = "2000-01-01 10:10:10")
    private Date createTime; // 创建时间

    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @TableField(update = "NOW()")
    @ApiModelProperty(value = "修改时间，不传参",example = "2000-01-01 10:10:10")
    private Date updateTime; // 修改时间

}
