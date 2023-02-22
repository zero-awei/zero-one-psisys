package com.zeroone.star.project.vo.sysmanagement.usermanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import io.swagger.models.auth.In;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.time.LocalDateTime;
import java.util.Date;
import java.util.List;
/**
 * <p>
 * 描述：用户编辑的显示对象
 * </p>
 *
 * @author dan
 */
@Data
@ApiModel("用户管理中编辑的显示对象")
public class EditUserVO {
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
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @ApiModelProperty(value = "生日", example = "2003-04-05 00:00:00")
    private Date birthday;

    /**
     * 性别(0-默认未知,1-男,2-女)
     */
    @ApiModelProperty(value = "性别", example = "1")
    private Integer sex;

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
     * 同步工作流引擎(1-同步,0-不同步)
     */
    @ApiModelProperty(value = "同步工作流引擎，1为同步，0为不同步", example = "1")
    private Integer activitiSync;

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
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    @ApiModelProperty(value = "更新时间", example = "2023-02-12 22:18:43")
    private Date updateTime;

    /**
     * 身份（1普通成员 2上级）
     */
    @ApiModelProperty(value = "身份", example = "1")
    private Integer userIdentity;

    /**
     * 部门编号
     */
    @ApiModelProperty(value = "负责的部门", example = "4f1765520d6346f9bd9c79e2479e5b12")
    private String departIds;

    /**
     * 负责部门
     */
    @ApiModelProperty(value = "负责的部门", example = "市场部")
    private String departName;

    /**
     * 部门列表
     */
    @ApiModelProperty(value = "部门列表", example = "市场部")
    private List<String> departments;


    /**
     * 多租户标识
     */
    @ApiModelProperty(value = "是否为多租户", example = "1")
    private String relTenantIds;

    /**
     * 设备ID
     */
    @ApiModelProperty(value = "设备ID", example = "1")
    private String clientId;

}
