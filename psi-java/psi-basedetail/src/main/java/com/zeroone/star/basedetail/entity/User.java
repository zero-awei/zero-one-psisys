package com.zeroone.star.basedetail.entity;


import com.alibaba.excel.annotation.ExcelProperty;
import lombok.Data;

/**
 * @author Third uncle
 * @date 2023/2/14 - 22:03
 */
@Data
public class User {
    /** value表示该属性对应的表头名称， index表示该属性所处的列的位置 */
    @ExcelProperty(value = "编号", index = 0)
    private Integer id;
    @ExcelProperty(value = "姓名", index = 1)
    private String name;
    @ExcelProperty(value = "电话", index = 2)
    private String phone;
}
