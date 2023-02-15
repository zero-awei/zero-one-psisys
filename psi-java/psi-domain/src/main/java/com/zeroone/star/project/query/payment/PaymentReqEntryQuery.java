package com.zeroone.star.project.query.payment;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import javax.validation.constraints.NotBlank;

@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("申请单查询对象")
public class PaymentReqEntryQuery extends PageQuery {
    @NotBlank(message = "源单号不能为空")
    @ApiModelProperty(value = "源单号", example = "CGYFSQ-221120-001")
    private String billNo;
}
