package com.zeroone.star.titlepage.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 
 * </p>
 *
 * @author yx
 * @since 2023-02-11
 */
@Getter
@Setter
@TableName("onl_cgreport_head")
public class OnlCgreportHead implements Serializable {

    private static final long serialVersionUID = 1L;

    private String id;

    /**
     * 报表编码
     */
    private String code;

    /**
     * 报表名字
     */
    private String name;

    /**
     * 报表SQL
     */
    private String cgrSql;

    /**
     * 返回值字段
     */
    private String returnValField;

    /**
     * 返回文本字段
     */
    private String returnTxtField;

    /**
     * 返回类型，单选或多选
     */
    private String returnType;

    /**
     * 动态数据源
     */
    private String dbSource;

    /**
     * 描述
     */
    private String content;

    /**
     * 关联的应用ID
     */
    private String lowAppId;

    /**
     * 修改时间
     */
    private LocalDateTime updateTime;

    /**
     * 修改人id
     */
    private String updateBy;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 创建人id
     */
    private String createBy;


}
