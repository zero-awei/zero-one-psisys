package com.zeroone.star.project.dto.sysmanagement.usermanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;
import java.util.Date;
import java.util.List;


/**
 * <p>
 * 用户管理中添加的显示对象
 * </p>
 *
 * @author axin
 * @since 2023-02-19
 */
@Data
@ApiModel("用户管理中添加的显示对象")
public class AddUserDTO {
    /**
     * 主键id
     */

    @NotBlank
    @ApiModelProperty(value = "id", example = "")
    private String id;

    /**
     * 登录账号
     */
    @NotBlank
    @ApiModelProperty(value = "输入您的用户名", example = "")
    private String username;

    /**
     * 真实姓名
     */
    @NotBlank
    @ApiModelProperty(value = "输入您的真实名字", example = "")
    private String realname;

    /**
     * 密码
     */
    @NotBlank
    @ApiModelProperty(value = "输入您的密码", example = "")
    private String password;


    /**
     * 头像
     */
    @NotBlank
    @ApiModelProperty(value = "选择您的头像", example = "")
    private String avatar;

    /**
     * 生日
     */
    @NotBlank
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @ApiModelProperty(value = "输入您的生日", example = "")
    private Date birthday;

    /**
     * 性别(0-默认未知,1-男,2-女)
     */
    @NotNull
    @ApiModelProperty(value = "选择您的性别，1为男，2为女", example = "")
    private Integer sex;

    /**
     * 电子邮件
     */
    @NotBlank
    @ApiModelProperty(value = "输入您的电子邮件", example = "")
    private String email;

    /**
     * 电话
     */
    @NotBlank
    @ApiModelProperty(value = "输入您的电话", example = "")
    private String phone;

    /**
     * 登录会话的机构编码
     */
    @NotBlank
    @ApiModelProperty(value = "选择您的登录会话的机构编码", example = "")
    private String orgCode;

    /**
     * 状态(1-正常,0-冻结)
     */
    @NotBlank
    @ApiModelProperty(value = "选择您的状态，1为正常，0为冻结", example = "")
    private Boolean status;


    /**
     * 同步工作流引擎(1-同步,0-不同步)
     */
    @NotBlank
    @ApiModelProperty(value = "选择是否同步工作流引擎，1为同步，0为不同步", example = "")
    private Boolean activitiSync;

    /**
     * 工号，唯一键
     */
    @NotBlank
    @ApiModelProperty(value = "输入您的工号", example = "")
    private String workNo;

    /**
     * 职务，关联职务表
     */
    @NotBlank
    @ApiModelProperty(value = "输入您的职务", example = "")
    private String post;

    /**
     * 座机号
     */
    @NotBlank
    @ApiModelProperty(value = "输入您的座机号", example = "")
    private String telephone;


    /**
     * 身份（1普通成员 2上级）
     */
    @NotNull
    @ApiModelProperty(value = "选择您的身份，1为普通成员，2为上级", example = "")
    private Integer userIdentity;

    /**
     * 负责部门
     */
    @NotBlank
    @ApiModelProperty(value = "选择您负责的部门", example = "")
    private String departName;

    /**
     * 多租户标识
     */
    @NotBlank
    @ApiModelProperty(value = "是否为多租户", example = "")
    private String relTenantIds;

    /**
     * 设备ID
     */
    @NotBlank
    @ApiModelProperty(value = "输入您的设备ID", example = "")
    private String clientId;

}