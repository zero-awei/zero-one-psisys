package com.zeroone.star.project.vo.sysmanagement.usermanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.util.Date;
import java.util.List;


/**
 * <p>
 * 用户表 用户管理中下拉框部门显示对象
 * </p>
 *
 * @author axin
 * @since 2023-02-18
 */
@Data
@ApiModel("用户管理中下拉框部门显示对象")
public class AddUserVO {
    /**
     * 主键id
     */
    @ApiModelProperty(value = "id", example = "")
    private String id;

    /**
     * 部门列表
     */
    @ApiModelProperty(value = "输入您的用户名", example = "")
    private String username;

    /**
     * 真实姓名
     */
    @ApiModelProperty(value = "输入您的真实名字", example = "")
    private String realname;

    /**
     * 密码
     */
    @ApiModelProperty(value = "输入您的密码", example = "")
    private String password;


    /**
     * 头像
     */
    @ApiModelProperty(value = "选择您的头像", example = "")
    private String avatar;

    /**
     * 生日
     */
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @ApiModelProperty(value = "输入您的生日", example = "")
    private Date birthday;

    /**
     * 性别(0-默认未知,1-男,2-女)
     */
    @ApiModelProperty(value = "选择您的性别，1为男，2为女", example = "")
    private Integer sex;

    /**
     * 电子邮件
     */
    @ApiModelProperty(value = "输入您的电子邮件", example = "")
    private String email;

    /**
     * 电话
     */
    @ApiModelProperty(value = "输入您的电话", example = "")
    private String phone;

    /**
     * 登录会话的机构编码
     */
    @ApiModelProperty(value = "选择您的登录会话的机构编码", example = "")
    private String orgCode;

    /**
     * 状态(1-正常,0-冻结)
     */
    @ApiModelProperty(value = "选择您的状态，1为正常，0为冻结", example = "")
    private Boolean status;


    /**
     * 同步工作流引擎(1-同步,0-不同步)
     */
    @ApiModelProperty(value = "是否同步工作流引擎,1为同步，0为不同步", example = "")
    private Boolean activitiSync;

    /**
     * 工号，唯一键
     */
    @ApiModelProperty(value = "输入您的工号", example = "")
    private String workNo;

    /**
     * 职务，关联职务表
     */
    @ApiModelProperty(value = "输入您的职务", example = "")
    private String post;

    /**
     * 座机号
     */
    @ApiModelProperty(value = "输入您的座机号", example = "")
    private String telephone;


    /**
     * 身份（1普通成员 2上级）
     */
    @ApiModelProperty(value = "选择您的身份", example = "")
    private Integer userIdentity;

    /**
     * 负责部门
     */
    @ApiModelProperty(value = "选择您负责的部门", example = "")
    private String departName;

}