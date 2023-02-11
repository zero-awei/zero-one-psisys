package com.zeroone.star.project.vo.systemmanagement.positionmanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.time.LocalDateTime;

/**
 * @Description position select returned  VO
 * @Author mumu
 * @Data 2023-02-11 16:32
 */
@Data
@ApiModel("职务查询返回对象VO")
public class PositionVO {

    @ApiModelProperty(value = "职务对象ID",example = "1624315388342083586")
    private Integer Id;

    @ApiModelProperty(value = "公司ID",example = "null")
    private Integer companyId;

    @ApiModelProperty(value = "职务编码", example = "devleader")
    private Integer code;

    @ApiModelProperty(value = "职务名称", example = "研发部经理")
    private String name;

    @ApiModelProperty(value = "职级", example = "2")
    private String postRank;

    @ApiModelProperty(value = "职务名称", example = "研发部经理")
    private String postRankDictText;

    @ApiModelProperty(value = "创建人", example = "张三")
    private String createBy;

    @ApiModelProperty(value = "创建时间", example = "2023-10-01 09:00:00")
    private LocalDateTime createTime;

    @ApiModelProperty(value = "修改人", example = "张三")
    private String updateBy;

    @ApiModelProperty(value = "修改时间", example = "2023-10-01 09:00:00")
    private LocalDateTime updateTime;

    @ApiModelProperty(value = "组织机构编码", example = "A01")
    private String sysOrgCode;
}
