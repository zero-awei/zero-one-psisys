package com.zeroone.star.project.query.payablemanagement;


import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

/**
 * @author spk
 * @since 2023-02-15
 * @description 根据Id查询应付核销单据详细信息
 */
@Data
@ApiModel("应付核销单据查询")
public class CheckPayableEntryQuery {


    @ApiModelProperty(value = "单据ID", example = "1623386325943361538")
    private String Id;
}
