package com.zeroone.star.project.dto.payment;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

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

    @ApiModelProperty(value = "id",example = "id")
    private String id;

    @ApiModelProperty(value = "核批结果类型",example = "1（通过）")
    private String approvalResultType;

    @ApiModelProperty(value = "核批意见",example = "xxx")
    private String approvalRemark;

    //TODO 是否增加核批人、修改时间、修改人等参数？？？？
}
