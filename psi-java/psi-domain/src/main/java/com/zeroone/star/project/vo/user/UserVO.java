package com.zeroone.star.project.vo.user;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;


@Data
@ApiModel("用户管理显示对象")
public class UserVO {
    /**
     * 主键id
     */
    @ApiModelProperty(value = "id", example = "1a2b3")
    private String id;

    /**
     * 登录账号
     */
    @ApiModelProperty(value = "用户名", example = "axin")
    private String username;

    /**
     * 真实姓名
     */
    @ApiModelProperty(value = "真实名字", example = "阿鑫")
    private String realname;

    /**
     * 密码
     */
    @ApiModelProperty(value = "密码", example = "testPassword123456WithoutMD5")
    private String password;


    /**
     * 头像
     */
    @ApiModelProperty(value = "头像", example = "")
    private String avatar;

    /**
     * 生日
     */
    @ApiModelProperty(value = "生日", example = "2003-04-05 00:00:00")
    private LocalDateTime birthday;

    /**
     * 性别(0-默认未知,1-男,2-女)
     */
    @ApiModelProperty(value = "性别", example = "1")
    private Boolean sex;

    /**
     * 电子邮件
     */
    @ApiModelProperty(value = "电子邮件", example = "123@qq.com")
    private String email;

    /**
     * 电话
     */
    @ApiModelProperty(value = "电话", example = "11111111111")
    private String phone;

    /**
     * 登录会话的机构编码
     */
    @ApiModelProperty(value = "登录会话的机构编码", example = "A01A01")
    private String orgCode;

    /**
     * 状态(1-正常,2-冻结)
     */
    @ApiModelProperty(value = "状态", example = "1")
    private Boolean status;

    /**
     * 删除状态(0-正常,1-已删除)
     */
    @ApiModelProperty(value = "删除状态", example = "0")
    private Boolean delFlag;

    /**
     * 同步工作流引擎(1-同步,0-不同步)
     */
    @ApiModelProperty(value = "同步工作流引擎", example = "1")
    private Boolean activitiSync;

    /**
     * 工号，唯一键
     */
    @ApiModelProperty(value = "工号", example = "666")
    private String workNo;

    /**
     * 职务，关联职务表
     */
    @ApiModelProperty(value = "职务", example = "manager")
    private String post;

    /**
     * 座机号
     */
    @ApiModelProperty(value = "座机号", example = "87678999")
    private String telephone;



    /**
     * 更新人
     */
    @ApiModelProperty(value = "更新人", example = "admin")
    private String updateBy;

    /**
     * 更新时间
     */
    @ApiModelProperty(value = "更新时间", example = "2023-02-12 22:18:43")
    private LocalDateTime updateTime;

    /**
     * 身份（1普通成员 2上级）
     */
    @ApiModelProperty(value = "身份", example = "1")
    private Boolean userIdentity;

    /**
     * 负责部门
     */
    @ApiModelProperty(value = "负责部门", example = "6")
    private String departIds;

    /**
     * 多租户标识
     */
    @ApiModelProperty(value = "多租户标识", example = "1")
    private String relTenantIds;

    /**
     * 设备ID
     */
    @ApiModelProperty(value = "设备ID", example = "1")
    private String clientId;

}
