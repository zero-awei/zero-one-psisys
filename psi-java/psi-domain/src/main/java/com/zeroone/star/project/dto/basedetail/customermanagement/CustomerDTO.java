package com.zeroone.star.project.dto.basedetail.customermanagement;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;

/**
 * @Description
 * @Author mumu
 * @Data 2023-02-13 11:36
 */
@Data
@ApiModel("查询客户DTO")
public class CustomerDTO {

    @ApiModelProperty(value = "客户对象编码code", example = "001")
    private String code;

    @ApiModelProperty(value = "客户对象助记名aux_name", example = "北京xx化工")
    private String auxName;

    @ApiModelProperty(value = "客户对象欠款额度creditQuota", example = "900")
    private BigDecimal creditQuota;

    @ApiModelProperty(value = "客户对象客户等级customer_level",example = "1")
    private String customerLevel;

    @ApiModelProperty(value = "启用", example = "1")
    private Integer isEnabled;

    @ApiModelProperty(value = "备注", example = "备注")
    private String remark;


}
