package com.zeroone.star.project.dto.systemmanagement.classifieddictionary;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * @Description
 * @Author 苏乞儿
 * @Date 2023/2/11
 */

@Data
@ApiModel("分类字典传输数据对象")
public class ClassifiedDictionaryDTO {

    @ApiModelProperty(value = "id", example = "1623318140959367170")
    private String id;

    @ApiModelProperty(value = "父级节点", example = "0")
    private String pid;

    @ApiModelProperty(value = "类型名称", example = "人员")
    private String name;

    @ApiModelProperty(value = "类型编码", example = "A02")
    private String code;

    @ApiModelProperty(value = "创建人", example = "psi")
    private String createBy;

    @ApiModelProperty(value = "创建日期", example = "2023-02-08 21:49:39")
    private LocalDateTime createTime;

    @ApiModelProperty(value = "更新人", example = "psi")
    private String updateBy;

    @ApiModelProperty(value = "更新日期", example = "2023-02-11 16:06:49")
    private LocalDateTime updateTime;

    @ApiModelProperty(value = "所属部门", example = "A01A05")
    private String sysOrgCode;

    @ApiModelProperty(value = "是否有子节点", example = "1")
    private String hasChild;

}
