package com.zeroone.star.project.dto.paymentmanagement.yf;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 /**
 * @Description 采购付款增删改表现层
 * @Author 业峰
 * @Date 2023/2/20
 */
@Data
@ApiModel("付款删除")
public class PurchasePaymentDeleteYfDto {
    @ApiModelProperty(value = "单据编号",example = "CGFK-230215-110")
    String billNo;
}
