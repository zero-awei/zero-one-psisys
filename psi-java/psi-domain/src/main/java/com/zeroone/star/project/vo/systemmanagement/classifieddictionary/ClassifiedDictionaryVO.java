package com.zeroone.star.project.vo.systemmanagement.classifieddictionary;

import com.zeroone.star.project.query.PageQuery;
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

    @ApiModelProperty(value = "名称",example = "物料")
    private String name;

    @ApiModelProperty(value = "编码",example = "A01")
    private String code;

    @ApiModelProperty(value = "是否有子节点",example = "1")
    private String hasChild;

    @ApiModelProperty(value = "id",example = "1230769769930592257")
    private String id;
}
