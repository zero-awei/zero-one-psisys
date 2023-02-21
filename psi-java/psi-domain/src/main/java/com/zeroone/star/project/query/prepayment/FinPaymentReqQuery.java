package com.zeroone.star.project.query.prepayment;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import javax.validation.constraints.NotBlank;
import java.time.LocalDate;

@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("申请单查询对象")
public class FinPaymentReqQuery extends PageQuery {
    @NotBlank(message = "供应商助记名不能为空")
    @ApiModelProperty(value = "供应商助记名", example = "001 广州xx公司")
    private String auxName;

    @ApiModelProperty(value = "单据编号", example = "CGYFSQ-230210-007")
    private String billNo;

    @ApiModelProperty(value = "开始日期", example = "2023-02-03")
    private LocalDate startDate;

    @ApiModelProperty(value = "结束日期", example = "2023-02-04")
    private LocalDate endDate;
}
