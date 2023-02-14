package com.zeroone.star.project.dto.systemmanagement.classifieddictionary;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.time.LocalDateTime;
import java.util.Date;

/**
 * <p>
 * 描述：分类字典数据传输对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author suqier
 * @version 1.0.0
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

    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "创建日期", example = "2023-02-08 21:49:39")
    private Date createTime;

    @ApiModelProperty(value = "更新人", example = "psi")
    private String updateBy;

    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "更新日期", example = "2023-02-11 16:06:49")
    private Date updateTime;

    @ApiModelProperty(value = "所属部门", example = "A01A05")
    private String sysOrgCode;

    @ApiModelProperty(value = "是否有子节点", example = "1")
    private String hasChild;

}
