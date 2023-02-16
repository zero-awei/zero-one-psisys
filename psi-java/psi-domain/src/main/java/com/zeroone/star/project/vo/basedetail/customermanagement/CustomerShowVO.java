package com.zeroone.star.project.vo.basedetail.customermanagement;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.math.BigDecimal;
import java.time.LocalDateTime;

/**
 * @Description
 * @auther j2-yizhiyang
 * @date 2023/2/15 22:41
 */
@Data
@ApiModel("查询客户VO")
public class CustomerShowVO {
    @ApiModelProperty(value = "客户对象编码code",example = "001")
    private  String code;

    @ApiModelProperty(value = "客户对象名称name",example = "北京xx化学工业公司")
    private  String name;

    @ApiModelProperty(value = "客户对象分类名称customer_category_name",example = "一级")
    private  String customerCategory;

    @ApiModelProperty(value = "客户等级分类名称customer_level_name",example = "高级客户")
    private String customerLevel;

    @ApiModelProperty(value = "客户对象业务区域bizArea", example = "0101")
    private String bizArea;

    @ApiModelProperty(value = "客户对象助记名aux_name", example = "001 北京xx化工")
    private String auxName;

    @ApiModelProperty(value = "客户对象所属地区area",example = "110101")
    private String area;

    @ApiModelProperty (value = "客户对象纳税规模tax_scale", example = "一般纳税人")
    private String taxScale;

    @ApiModelProperty(value = "客户对象欠款额度creditQuota", example = "900.00")
    private BigDecimal creditQuota;

    @ApiModelProperty("客户对象所属总公司headquarters")
    private String headquarters;

    @ApiModelProperty("客户对象地址address")
    private String address;

    @ApiModelProperty("客户对象网址website")
    private String website;

    @ApiModelProperty(value ="启用",example = "1")
    private Integer isEnabled;

    @ApiModelProperty(value ="创建人",example = "admin")
    private String createBy;

    @ApiModelProperty("客户备注remark")
    private String remark;

    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value ="创建时间",example =  "2022-10-26T00:00:00")
    private LocalDateTime createTime;

    @ApiModelProperty(value ="修改人",example = "admin")
    private String updateBy;

    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value ="修改时间",example = "2022-11-27T10:24:43")
    private LocalDateTime updateTime;
}
