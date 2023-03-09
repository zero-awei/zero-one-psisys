package com.zeroone.star.systemmanagement.entity.positionmanagement;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.io.Serializable;
import java.util.Date;

/**
 * @Description
 * @Author mumu
 * @Data 2023-02-12 19:36
 */
@Data
@TableName("sys_position")
public class Position implements Serializable {
    /**
     * 职务对象ID
     */
    private String Id;

    /**
     * 公司ID
     */
    private String companyId;
    /**
     * 职务编码
     */
    private String code;

    /**
     * 职务名称
     */
    private String name;

    /**
     * 职级
     */
    private String postRank;

    /**
     * 创建人
     */
    private String createBy;

    /**
     * 创建时间
     */
    @TableField(fill = FieldFill.INSERT)
    private Date createTime;

    /**
     * 修改人
     */
    private String updateBy;

    /**
     * 修改时间
     */
    @TableField(fill = FieldFill.INSERT_UPDATE)
    private Date updateTime;

    /**
     * 组织机构编码
     */
    private String sysOrgCode;
}
