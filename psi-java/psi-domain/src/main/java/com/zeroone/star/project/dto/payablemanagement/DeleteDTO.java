package com.zeroone.star.project.dto.payablemanagement;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@ApiModel("删除应付数据传输对象")
@AllArgsConstructor
@NoArgsConstructor
public class DeleteDTO {
    @ApiModelProperty(value = "ID", example = "1590717742358511617")
    private String id;

    @ApiModelProperty(value = "单据编号", example = "QTAP-230213-007")
    private String billNo;
}
