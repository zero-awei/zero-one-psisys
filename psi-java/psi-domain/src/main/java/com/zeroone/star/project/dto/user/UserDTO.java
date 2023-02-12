package com.zeroone.star.project.dto.user;

import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

@Data
@ApiModel("用户管理数据传输对象")
public class UserDTO {
    /**
     * 主键id
     */
    @ApiModelProperty(value = "id", example = "e9ca23d68d884d4ebb19d07889727dae")
    private String id;

    /**
     * 登录账号
     */
    @ApiModelProperty(value = "用户名", example = "张三")
    private String username;

    /**
     * 真实姓名
     */
    private String realname;

    /**
     * 密码
     */
    private String password;

    /**
     * md5密码盐
     */
    private String salt;

    /**
     * 头像
     */
    private String avatar;

    /**
     * 生日
     */
    private LocalDateTime birthday;

    /**
     * 性别(0-默认未知,1-男,2-女)
     */
    private Boolean sex;

    /**
     * 电子邮件
     */
    private String email;

    /**
     * 电话
     */
    private String phone;

    /**
     * 登录会话的机构编码
     */
    private String orgCode;

    /**
     * 性别(1-正常,2-冻结)
     */
    private Boolean status;

    /**
     * 删除状态(0-正常,1-已删除)
     */
    private Boolean delFlag;

    /**
     * 同步工作流引擎(1-同步,0-不同步)
     */
    private Boolean activitiSync;

    /**
     * 工号，唯一键
     */
    private String workNo;

    /**
     * 职务，关联职务表
     */
    private String post;

    /**
     * 座机号
     */
    private String telephone;



    /**
     * 更新人
     */
    private String updateBy;

    /**
     * 更新时间
     */
    private LocalDateTime updateTime;

    /**
     * 身份（1普通成员 2上级）
     */
    private Boolean userIdentity;

    /**
     * 负责部门
     */
    private String departIds;

    /**
     * 多租户标识
     */
    private String relTenantIds;

    /**
     * 设备ID
     */
    private String clientId;


}
