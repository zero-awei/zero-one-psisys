package com.zeroone.star.project.query.systemmanagement.classifieddictionary;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.*;
import org.springframework.format.annotation.DateTimeFormat;

import java.time.LocalDateTime;
import java.util.Date;

/**
 * <p>
 * 描述：分类字典查询对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author suqier
 * @version 1.0.0
 */


@Data
@ApiModel("分类字典查询对象")
public class ClassifiedDictionaryQuery {

    @ApiModelProperty(value = "排序方式",example = "desc")
    private String order;

    @ApiModelProperty(value = "id",example = "desc")
    private String id;

    @ApiModelProperty(value = "类型名称",example = "desc")
    private String name;

    @ApiModelProperty(value = "类型编码",example = "desc")
    private String code;

    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "创建日期",example = "2023-02-08 21:49:39")
    private Date createTime;
}
