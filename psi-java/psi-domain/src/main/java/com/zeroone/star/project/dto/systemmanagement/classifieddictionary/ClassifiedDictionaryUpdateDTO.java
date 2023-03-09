package com.zeroone.star.project.dto.systemmanagement.classifieddictionary;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @Description
 * @Author 苏乞儿
 * @Date 2023/2/19
 */

@Data
@ApiModel("分类字典修改传输数据对象")
public class ClassifiedDictionaryUpdateDTO {

    @ApiModelProperty(value = "id",example = "1623318140959367170")
    private String id;

    @ApiModelProperty(value = "类型名称",example = "人员")
    private String name;
}
