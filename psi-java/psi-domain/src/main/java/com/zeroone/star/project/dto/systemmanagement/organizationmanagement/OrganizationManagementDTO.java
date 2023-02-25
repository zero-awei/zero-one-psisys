package com.zeroone.star.project.dto.systemmanagement.organizationmanagement;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.time.LocalDateTime;
import java.util.Date;

/**
 * <p>
 * 描述：组织结构管理传输数据对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author Morrangee
 * @version 1.0.0
 */
@Data
@ApiModel("组织结构管理传输数据对象")
public class OrganizationManagementDTO {

    @ApiModelProperty(value = "地址", example = "北京")
    private String address;

    @ApiModelProperty(value = "创始人", example = "admin")
    private String creatBy;

    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "创建时间", example = "2019-02-20 17:15:34")
    private Date creatTime;

    @ApiModelProperty(value = "删除状态（0，正常，1已删除）", example = "0")
    private String delFlag;

    @ApiModelProperty(value = "机构/部门名称", example = "市场部")
    private String departName;

    @ApiModelProperty(value = "缩写", example = "scb")
    private String departNameAbbr;

    @ApiModelProperty(value = "英文名", example = "marketing")
    private String departNameEn;

    @ApiModelProperty(value = "排序", example = "0")
    private Integer departOrder;

    @ApiModelProperty(value = "描述", example = "很好")
    private String description;

    @ApiModelProperty(value = "传真", example = "556668571234")
    private String fax;

    @ApiModelProperty(value = "ID", example = "4f1765520d6346f9bd9c79e2479e5b12")
    private String id;

    @ApiModelProperty(value = "备注", example = "无")
    private String memo;

    @ApiModelProperty(value = "手机号", example = "12367677878")
    private String mobile;

    @ApiModelProperty(value = "机构类别 1组织机构，2岗位", example = "1")
    private String orgCategory;

    @ApiModelProperty(value = "机构编码", example = "A01A103")
    private String orgCode;

    @ApiModelProperty(value = "机构类型 1一级部门 2子部门", example = "2")
    private String orgType;

    @ApiModelProperty(value = "父机构ID", example = "c6d7cb4deeac411cb3384b1b31278596")
    private String parentId;

    @ApiModelProperty(value = "对接企业微信的ID", example = "wxid_1234567")
    private String qywxIdentifier;

    @ApiModelProperty(value = "状态（1启用，0不启用）", example = "1")
    private String status;

    @ApiModelProperty(value = "更新人", example = "admin")
    private String updateBy;

    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "更新时间", example = "2019-02-26 16:36:18")
    private Date updateTime;

}
