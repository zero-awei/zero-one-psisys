package com.zeroone.star.project.query.paymentmanagement;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/*
    author :achuan
*/
@Data
@ApiModel("查询单据列表Query")
public class QueryDocumentListQuery extends PageQuery {

    //业峰：
    /*本查询为分页查询，不通过单号、主题进行查询
    @ApiModelProperty(value = "单据编号",example = "CGYF-230208-020")
    private String billNo;

    @ApiModelProperty(value = "单据主题",example = "10")
    private String subject;
     */
}
