package com.zeroone.star.project.dto.prepayment;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;

/**
 * <p>
 * 描述：审核
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author forever爱
 * @version 1.0.0
 */

@Data
@ApiModel("审核功能")
public class AuditDTO {

    @ApiModelProperty(value = "id",example = "1626949545251745795")
    @NotBlank(message = "id不能为空")
    private String id;

    @ApiModelProperty(value = "核批结果类型",example = "1（通过）")
    private String approvalResultType;

    @ApiModelProperty(value = "核批意见",example = "xxx")
    private String approvalRemark;
}
