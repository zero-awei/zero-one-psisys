package com.zeroone.star.titlepage.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 供应商
 * </p>
 *
 * @author ss
 * @since 2023-02-12
 */
@Getter
@Setter
@TableName("bas_supplier")
public class BasSupplier implements Serializable {

    private static final long serialVersionUID = 1L;
    private String label;
    private String value;
    private String width;

}
