package com.zeroone.star.project.query.paymentmanagement;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

@Data
@ApiModel("查询指点单据信息")
public class ViewSpecifiedDocInfQuery extends PageQuery {
    @ApiModelProperty(value = "单据编号",example = "CGYF-230208-020")
    private String billNo;
}
