package com.zeroone.star.basedetail.entity.customermanagement;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;

/**
 * @Description
 * @auther j2-yizhiyang
 * @date 2023/2/15 18:58
 */
@Getter
@Setter
@TableName("cus_level")
@Data
public class CusLevel {
    private static final long serialVersionUID = 1L;

    @TableId(value = "id", type = IdType.AUTO)
    @TableField(value = "id")
    private String id;
    @TableField(value = "name")
    private String name;
}
