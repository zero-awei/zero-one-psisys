package com.zeroone.star.project.vo.systemmanagement.classifieddictionary;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：分类字典视图对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author suqier
 * @version 1.0.0
 */
@Data
@ApiModel("分类字典显示对象")
public class ClassifiedDictionaryVO {

    @ApiModelProperty(value = "姓名",example = "张三")
    private String name;
}
