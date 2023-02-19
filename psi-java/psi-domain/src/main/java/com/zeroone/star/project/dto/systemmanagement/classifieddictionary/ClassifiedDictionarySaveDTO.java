package com.zeroone.star.project.dto.systemmanagement.classifieddictionary;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

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
@ApiModel("分类字典新增传输数据对象")
public class ClassifiedDictionarySaveDTO {


    @ApiModelProperty(value = "父级节点", example = "0")
    private String pid;


    @ApiModelProperty(value = "类型名称", example = "人员")
    private String name;


}
//参数传递、参数校验