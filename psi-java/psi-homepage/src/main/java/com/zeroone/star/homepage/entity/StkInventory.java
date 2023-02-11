package com.zeroone.star.homepage.entity;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.math.BigDecimal;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 实时库存
 * </p>
 *
 * @author yx
 * @since 2023-02-11
 */
@Getter
@Setter
@TableName("stk_inventory")
public class StkInventory implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * ID
     */
    private String id;

    /**
     * 仓库
     */
    private String warehouseId;

    /**
     * 物料
     */
    private String materialId;

    /**
     * 批号
     */
    private String batchNo;

    /**
     * 计量单位
     */
    private String unitId;

    /**
     * 数量
     */
    private BigDecimal qty;

    /**
     * 成本
     */
    private BigDecimal cost;

    /**
     * 单供应商
     */
    private Integer isSingleSupplier;

    /**
     * 最后供应商
     */
    private String supplierId;

    /**
     * 是否关闭
     */
    private Integer isClosed;

    /**
     * 创建部门
     */
    private String sysOrgCode;

    /**
     * 创建人
     */
    private String createBy;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    /**
     * 修改人
     */
    private String updateBy;

    /**
     * 修改时间
     */
    private LocalDateTime updateTime;

    /**
     * 版本
     */
    private Integer version;


}
