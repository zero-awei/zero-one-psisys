package com.zeroone.star.project.dto.payablemanagement;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：其他应付单单据状态传输对象
 * </p>
 *
 * @author 孤独的意识
 * @version 1.0.0
 */

@Data
@ApiModel("其他应付单单据状态传输对象")
public class PayableStatusDTO {
    /**
     * 单据编号
     */
    @ApiModelProperty(value = "单据编号", example = "QTAP-230213-007")
    private String billNo;

    /**
     * 是否关闭，1代表已关闭，0代表未关闭
     */
    @ApiModelProperty(value = "是否关闭", example = "1")
    private Integer isClosed;

    /**
     * 是否作废，1代表已作废，0代表未作废
     */
    @ApiModelProperty(value = "是否作废", example = "1")
    private Integer isVoided;
}
