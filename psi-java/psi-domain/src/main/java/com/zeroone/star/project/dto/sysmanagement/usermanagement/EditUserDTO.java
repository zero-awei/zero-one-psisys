package com.zeroone.star.project.dto.sysmanagement.usermanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.time.LocalDateTime;
import java.util.Date;

@Data
@ApiModel("用户管理中编辑的数据传输对象")
public class EditUserDTO {
    /**
     * 主键id
     */
    @ApiModelProperty(value = "id", example = "f0019fdebedb443c98dcb17d88222c38")
    private String id;

    /**
     * 登录账号
     */
    @ApiModelProperty(value = "用户名", example = "zhagnxiao")
    private String username;

    /**
     * 真实姓名
     */
    @ApiModelProperty(value = "真实名字", example = "张小红")
    private String realname;

    /**
     * 密码
     */
    @ApiModelProperty(value = "密码", example = "f898134e5e52ae11a2ffb2c3b57a4e90")
    private String password;

    /**
     * 头像
     */
    @ApiModelProperty(value = "头像", example = "user/20190401/20180607175028Fn1Lq7zw_1554118444672.png")
    private String avatar;

    /**
     * 生日
     */
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @ApiModelProperty(value = "生日", example = "2019-04-01 00:00:00")
    private Date birthday;

    /**
     * 性别(0-默认未知,1-男,2-女)
     */
    @ApiModelProperty(value = "性别", example = "2")
    private Integer sex;

    /**
     * 电子邮件
     */
    @ApiModelProperty(value = "电子邮件", example = "123@qq.com")
    private String email;

    /**
     * 电话
     */
    @ApiModelProperty(value = "电话", example = "18611783333")
    private String phone;

    /**
     * 登录会话的机构编码
     */
    @ApiModelProperty(value = "登录会话的机构编码", example = "A01A01")
    private String orgCode;

    /**
     * 同步工作流引擎(1-同步,0-不同步)
     */
    @ApiModelProperty(value = "同步工作流引擎", example = "1")
    private Integer activitiSync;

    /**
     * 工号，唯一键
     */
    @ApiModelProperty(value = "工号", example = "3")
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
     * 身份（1普通成员 2上级）
     */
    @ApiModelProperty(value = "身份", example = "1")
    private Integer userIdentity;

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