package com.zeroone.star.project.vo.systemmanagement.classifieddictionary;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @Description
 * @Author 苏乞儿
 * @Date 2023/2/11
 */
@Data
@ApiModel("分类字典显示对象")
public class ClassifiedDictionaryVO {

    @ApiModelProperty(value = "姓名",example = "张三")
    private String name;
}
