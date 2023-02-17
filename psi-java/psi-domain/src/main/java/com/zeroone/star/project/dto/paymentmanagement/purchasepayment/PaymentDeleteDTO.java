package com.zeroone.star.project.dto.paymentmanagement.purchasepayment;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author Tomcat
 * @Date 2023/2/15 13:32
 */
@Data
@ApiModel("删除采购付款的数据传输对象")
public class PaymentDeleteDTO {
    @ApiModelProperty(value = "单据id",example = "1625823227778736130")
    private int id;
}
