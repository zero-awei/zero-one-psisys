package com.zeroone.star.prepayment.entity;

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
 * 银行账户
 * </p>
 *
 * @author Kong
 * @since 2023-02-17
 */
@Getter
@Setter
@TableName("bas_bank_account")
public class BasBankAccount implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * ID
     */
    private String id;

    /**
     * 账号
     */
    private String accountNo;

    /**
     * 账户名称
     */
    private String name;

    /**
     * 币种
     */
    private String currency;

    /**
     * 初始余额
     */
    private BigDecimal initBal;

    /**
     * 行号
     */
    private String bankNo;

    /**
     * 银行地址
     */
    private String bankAddress;

    /**
     * 账户管理员
     */
    private String manager;

    /**
     * 备注
     */
    private String remark;

    /**
     * 附件
     */
    private String attachment;

    /**
     * 是否启用
     */
    private Integer isEnabled;

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
