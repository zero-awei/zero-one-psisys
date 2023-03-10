package com.zeroone.star.project.dto.prepayment;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;
import org.springframework.validation.annotation.Validated;

import javax.validation.Valid;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;
import java.math.BigDecimal;
import java.util.Date;
import java.util.List;

/**
 * <p>
 * 描述：修改采购预付单功能——有申请和无申请
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author forever爱
 * @version 1.0.0
 */
@Data
@ApiModel("修改采购预付单功能")
public class ModifyDTO {
    @ApiModelProperty(value = "id",example = "1626949545251745795")
    private String id;

//    @ApiModelProperty(value = "金额",example = "1000.00")
//    private BigDecimal amt;

    @ApiModelProperty(value = "单据日期",example = "2022-01-14")
    @NotNull(message = "单据日期不能为空")
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    private Date billDate;

    @ApiModelProperty(value = "单据编号",example = "TEST-202302-002")
    @NotBlank(message = "单据编号不能为空")
    private String billNo;

    @ApiModelProperty(value = "备注",example = "测试用")
    private String remark;

//    @ApiModelProperty(value = "源单类型",example = "FinPaymentReq:2011")
//    private String srcBillType;
//
//    @ApiModelProperty(value = "源单id",example = "1594317750844637186")
//    private String srcBillId;
//
//    @ApiModelProperty(value = "源单号",example = "TESTSQ-202302-002")
//    private String srcNo;

    @ApiModelProperty(value = "单据主题",example = "tittle")
    private String subject;

    @ApiModelProperty(value = "供应商",example = "1584950950470164481")
    @NotBlank(message = "供应商不能为空")
    private String supplierId;

    @ApiModelProperty(value = "附件",example = "")
    private String attachment;

    @ApiModelProperty(value = "版本",example = "")
    private Integer version;

    @ApiModelProperty(value = "采购单明细",example = "")
    @Valid
    private List<FinPaymentEntryDTO> entryDTOList;

}
