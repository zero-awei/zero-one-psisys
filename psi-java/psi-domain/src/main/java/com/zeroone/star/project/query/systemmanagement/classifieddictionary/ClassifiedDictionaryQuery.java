package com.zeroone.star.project.query.systemmanagement.classifieddictionary;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.*;

import java.time.LocalDateTime;

/**
 * @Description
 * @Author 苏乞儿
 * @Date 2023/2/11
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

    @ApiModelProperty(value = "创建日期",example = "desc")
    private LocalDateTime createTime;
}
