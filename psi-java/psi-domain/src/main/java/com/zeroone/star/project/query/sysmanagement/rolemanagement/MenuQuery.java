package com.zeroone.star.project.query.sysmanagement.rolemanagement;

import com.baomidou.mybatisplus.annotation.TableField;
import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;
import java.util.Date;

@ApiModel("编辑菜单对象")
@Data
@AllArgsConstructor
@NoArgsConstructor
public class MenuQuery  {

    @ApiModelProperty(value = "菜单id",example = "020b06793e4de2eee0007f603000c769")
    private String id; // 菜单id

    @ApiModelProperty(value = "父id",example = "00a2a0ae65cdca5e93209cdbde97cbe6")
    private String ParentId;

    @ApiModelProperty(value = "菜单名",example = "菜单1")
    private String Name; // 菜单名

    @ApiModelProperty(value = "url路径",example = "/main/1")
    private String Url; // url

//    @TableField(update = "😀")
    @ApiModelProperty(value = "图标")
    private String Icon; // 图标

//    @TableField(update = "1.00")
    @ApiModelProperty(value = "排序，不需要传参",example = "1.10")
    private Double sortNo; // 排序

//    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
//    @TableField(update = "NOW()")
    @ApiModelProperty(value = "创建时间，不传参",example = "2023-02-14 19:57:33")
    private Date createTime; // 创建时间

//    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
//    @TableField(update = "NOW()")
    @ApiModelProperty(value = "修改时间，不传参",example = "2023-02-14 19:57:33")
    private Date updateTime; // 修改时间
}
