package com.zeroone.star.project.vo.paymentManager;

import com.alibaba.excel.annotation.ExcelProperty;
import com.alibaba.excel.annotation.write.style.ColumnWidth;
import com.alibaba.excel.annotation.write.style.ContentRowHeight;
import com.alibaba.excel.annotation.write.style.HeadRowHeight;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;
import java.time.LocalDate;
import java.time.LocalDateTime;

@Data
@ContentRowHeight(15)
@HeadRowHeight(20)
@ColumnWidth(25)
public class ChosenExportVo {

    @ExcelProperty(value = "单据编号")
    private String billNo;

    @ExcelProperty(value = "单据日期")
    private LocalDate billDate;

    @ExcelProperty("源单类型")
    private String srcBillType;

    @ExcelProperty(value = "单据主题")
    private String subject;

    @ExcelProperty(value = "供应商")
    private String supplierId;

    @ExcelProperty(value = "金额")
    private BigDecimal amt;

    @ExcelProperty(value = "已核销金额")
    private BigDecimal checkedAmt;

    @ExcelProperty(value = "单据阶段")
    private String billStage;

    @ExcelProperty(value = "已生效")
    private Integer isEffective;

    @ExcelProperty(value = "已关闭")
    private Integer isClosed;

    @ExcelProperty(value = "已作废")
    private Integer isVoided;

    @ExcelProperty(value = "自动单据 ")
    private Integer isAuto;

    @ExcelProperty(value = "红字单据 ")
    private Integer isRubric;

    @ExcelProperty(value = "备注")
    private String remark;

    @ExcelProperty(value = "生效时间")
    private LocalDateTime effectiveTime;

    @ExcelProperty(value = "审核人")
    private String approver;

    @ExcelProperty(value = "制单人")
    private String createBy;

    @ExcelProperty(value = "制单部门")
    private String sysOrgCode;

    @ExcelProperty(value = "修改时间")
    private LocalDateTime updateTime;

    @ExcelProperty(value = "修改人")
    private String updateBy;
}
