package com.zeroone.star.project.query.sysmanagement.rolemanagement;

import com.baomidou.mybatisplus.annotation.TableField;
import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.Date;


@ApiModel("编辑权限对象")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class PermissionQuery {
    @ApiModelProperty(value = "权限id",example = "1")
    private String id; // 权限id

    @ApiModelProperty(value = "父id",example = "1")
    private String ParentId;

    @ApiModelProperty(value = "权限名",example = "销售管理")
    private String Name; // 权限名

    @ApiModelProperty(value = "url",example = "本权限的访问路径")
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
