package com.zeroone.star.systemmanagement.entity.addressbook;

import com.alibaba.excel.annotation.ExcelProperty;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;


/**
 * <p>
 * 描述：测试EasyExcel用户类
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 西柚珍珠蜜
 * @version 1.0.0
 */
@Data
public class User {
    /** value表示该属性对应的表头名称， index表示该属性所处的列的位置 */

    @ExcelProperty(value = "姓名",index = 0)
    private String realname;

    @ExcelProperty(value = "工号",index = 1)
    private String workNo;

    @ExcelProperty(value = "部门",index = 2)
    private String departName;

    @ExcelProperty(value = "职务",index = 3)
    private String post;

    @ExcelProperty(value = "手机",index = 4)
    private String phone;

    @ExcelProperty(value = "公司邮箱",index = 5)
    private String email;
}
