package com.zeroone.star.project.query.systemmanagement.addressbook;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import javax.validation.constraints.NotBlank;

/**
 * <p>
 * 描述：通讯录查询对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 西柚珍珠蜜
 * @version 1.0.0
 */

@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("通讯录查询对象")  //sys_user   sys_depart   sys_user_depart   departId   userId
public class AddressbookQuery extends PageQuery{


    @ApiModelProperty(value = "姓名",example = "李业武")
    private String realname;

    @ApiModelProperty(value = "工号",example = "11")
    private String workNo;

    @ApiModelProperty(value = "部门",example = "市场部")
    private String departName;


}
