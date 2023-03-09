package com.zeroone.star.systemmanagement.entity.addressbook;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;


/**
 * <p>
 * 描述：Addressbook实体类
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 西柚珍珠蜜
 * @version 1.0.0
 */

@Data
@Getter
@Setter
public class Addressbook {

    @ApiModelProperty(value = "姓名",example = "张三")
    private String realname;

    @ApiModelProperty(value = "工号",example = "10")
    private String workNo;

    @ApiModelProperty(value = "部门",example = "研发部")
    private String departName;

    @ApiModelProperty(value = "职务",example = "技术官")
    private String post;

    @ApiModelProperty(value = "手机",example = "13814389438")
    private String phone;

    @ApiModelProperty(value = "公司邮箱",example = "110@fuck.com")
    private String email;

}
