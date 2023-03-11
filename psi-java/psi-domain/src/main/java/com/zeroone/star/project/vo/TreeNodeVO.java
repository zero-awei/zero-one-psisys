package com.zeroone.star.project.vo;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.util.List;

/**
 * <p>
 * 描述：用来定义一个树形节点的数据
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
@Data
public class TreeNodeVO<T> implements Serializable {
    @ApiModelProperty(value = "唯一ID", example = "1")
    private String id;
    @ApiModelProperty(value = "节点文本描述", example = "会员管理")
    private String text;
    @ApiModelProperty(value = "节点对应图标", example = "fa-user-md")
    private String icon;
    @ApiModelProperty(value = "节点链接地址", example = "menuManagement")
    private String href;
    @ApiModelProperty(value = "节点父节点ID", example = "null")
    private String pid;
    @ApiModelProperty(value = "节点深度", example = "0")
    private Integer depth;
    @ApiModelProperty(value = "是否展开", example = "false")
    private Boolean expanded;
    @ApiModelProperty(value = "是否选中", example = "false")
    private Boolean checked;
    @ApiModelProperty(value = "节点包含的子节点")
    private List<TreeNodeVO<T>> children;
    @ApiModelProperty(value = "节点源数据对象")
    private T raw;
}
