package com.zeroone.star.project.dto.payablespayment;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import java.time.LocalDateTime;

/**
 * @Description 修改采购付款示例数据传输对象
 * @Author 业峰
 * @Date 2023/2/15
 */
@Data
@ApiModel("修改采购付款示例数据传输对象")
public class UpdatePurchasePaymentDto {
    @NotBlank(message = "单据编号不能为空")
    @ApiModelProperty(value = "单据编号", example = "CGFK-230215-005")
    private String dillId;
    @NotBlank(message = "单据日期不能为空")
    @ApiModelProperty(value = "单据日期", example = "2023-02-15")
    private LocalDateTime dillDate;
    @ApiModelProperty(value = "主题", example = "01星球")
    private String theme;
    @NotBlank(message = "供应商不能为空")
    @ApiModelProperty(value = "供应商", example = "01星球")
    private String supplier;
    @ApiModelProperty(value = "备注", example = "01星球")
    private String remark;
}
