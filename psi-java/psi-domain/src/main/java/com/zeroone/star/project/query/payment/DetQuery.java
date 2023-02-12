package com.zeroone.star.project.query.payment;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import javax.validation.constraints.NotBlank;

/**
 * @ClassName DetQuery
 * @Description 根据单据编号查询
 * @Author HZP
 * @Date 2023/2/12 14:15
 * @Version 1.0
 **/
@EqualsAndHashCode(callSuper = false)
@Data
@ApiModel("单据编号查询")
public class DetQuery {
    @NotBlank(message = "单据编号不能为空")
    @ApiModelProperty(value = "单据编号",example = "CGYF-230211-022")
    private String billNo;
}