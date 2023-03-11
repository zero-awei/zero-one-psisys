package com.zeroone.star.project.query.prepayment;

import com.alibaba.excel.annotation.ExcelIgnore;
import com.alibaba.excel.annotation.ExcelProperty;
import com.alibaba.excel.annotation.write.style.ColumnWidth;
import com.alibaba.excel.annotation.write.style.ContentStyle;
import com.alibaba.excel.annotation.write.style.HeadStyle;
import com.alibaba.excel.enums.poi.HorizontalAlignmentEnum;
import com.baomidou.mybatisplus.annotation.FieldFill;
import com.baomidou.mybatisplus.annotation.TableField;

import com.zeroone.star.project.components.easyexcel.LocalDateStringConverter;
import com.zeroone.star.project.components.easyexcel.LocalDateTimeStringConverter;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.math.BigDecimal;
import java.time.LocalDate;
import java.time.LocalDateTime;

@Data
@HeadStyle(horizontalAlignment = HorizontalAlignmentEnum.CENTER)//表头样式
@ContentStyle(horizontalAlignment = HorizontalAlignmentEnum.CENTER)//内容样式
@ColumnWidth(20)//表头宽度
public class FinPaymentExportQuery {

    @ApiModelProperty(value = "付款类型",example = "采购预付(无申请)")
    @ExcelProperty(value = {"付款单信息","付款类型"}, index = 0)
    private String isRequested;

    // 需要结合供应商表查询名称
    @ApiModelProperty(value = "供应商",example = "1584950950470164481")
    @ExcelProperty(value = {"付款单信息","供应商"}, index = 1)
    private String supplierId;

    @ApiModelProperty(value = "金额",example = "666.00")
    @ExcelProperty(value = {"付款单信息","金额"}, index = 2)
    private BigDecimal amt;

    @ApiModelProperty(value = "已核销金额",example = "0.00")
    @ExcelProperty(value = {"付款单信息","已核销金额"}, index = 3)
    private BigDecimal checkedAmt;

    // 以下为-明细表数据

    @ApiModelProperty(value = "结算方式",example = "31(银行代扣)")
    @ExcelProperty(value = {"付款单信息","付款明细","结算方式"}, index = 4)
    private String settleMethod;

    @ApiModelProperty(value = "资金账户",example = "1584913699556106242")
    @ExcelProperty(value = {"付款单信息","付款明细","资金账户"}, index = 5)
    private String bankAccountId;

    @ApiModelProperty(value = "金额",example = "142000.00")
    @ExcelProperty(value = {"付款单信息","付款明细","金额"}, index = 6)
    private BigDecimal eAmt;

    @ApiModelProperty(value = "自定义1",example = "this is custom1 information")
    @ExcelProperty(value = {"付款单信息","付款明细","自定义1"}, index = 7)
    private String custom1;

    @ApiModelProperty(value = "源单分录号",example = "CGRK-221110-001")
    @ExcelProperty(value = {"付款单信息","付款明细","源单分录号"}, index = 8)
    private String eSrcNo;

    @ApiModelProperty(value = "分录号",example = "10")
    @ExcelProperty(value = {"付款单信息","付款明细","分录号"}, index = 9)
    private Integer entryNo;

    @ApiModelProperty(value = "自定义2",example = "this is custom2 information")
    @ExcelProperty(value = {"付款单信息","付款明细","自定义2"}, index = 10)
    private String custom2;

    @ApiModelProperty(value = "源单分录id",example = "404")
    @ExcelProperty(value = {"付款单信息","付款明细","源单分录id"}, index = 11)
    private String srcEntryId;

    @ApiModelProperty(value = "源单类型",example = "StkIo:101")
    @ExcelProperty(value = {"付款单信息","付款明细","源单类型"}, index = 12)
    private String eSrcBillType;

    @ApiModelProperty(value = "备注",example = "备注")
    @ExcelProperty(value = {"付款单信息","付款明细","备注"}, index = 13)
    private String eRemark;

    @ApiModelProperty(value = "单据编号",example = "CGFK-221110-001")
    @ExcelProperty(value = {"付款单信息","付款明细","单据编号"}, index = 14)
    private String eBillNo;

    @ApiModelProperty(value = "源单id",example = "1590717667678928898")
    @ExcelProperty(value = {"付款单信息","付款明细","源单id"}, index = 15)
    private String eSrcBillId;

    // 以上为-明细表数据

    @ApiModelProperty(value = "是否生效",example = "1")
    @ExcelProperty(value = {"付款单信息","是否生效"}, index = 16)
    private String isEffective;

    @ApiModelProperty(value = "附件",example = "http://1.15.240.108:8888/group1/M00/00/01/AQ_wbGP2I02AJZgOAAeNLGKTjJk029.png?token=d7f2325f52092f4f07de04093d7f0036&ts=1677075275")
    @ExcelProperty(value = {"付款单信息","附件"}, index = 17)
    private String attachment;

    @ApiModelProperty(value = "源单id",example = "1594317750844637186")
    @ExcelProperty(value = {"付款单信息","源单id"}, index = 18)
    private String srcBillId;

    @ApiModelProperty(value = "单据主题",example = "tittle")
    @ExcelProperty(value = {"付款单信息","单据主题"}, index = 19)
    private String subject;

    @ApiModelProperty(value = "单据阶段",example = "11")
    @ExcelProperty(value = {"付款单信息","单据阶段"}, index = 20)
    private String billStage;

    @ApiModelProperty(value = "源单号",example = "CGYFSQ-221120-001")
    @ExcelProperty(value = {"付款单信息","源单号"}, index = 21)
    private String srcNo;

    @ApiModelProperty(value = "是否自动单据",example = "0")
    @ExcelProperty(value = {"付款单信息","是否自动单据"}, index = 22)
    private String isAuto;

    @ApiModelProperty(value = "备注",example = "remark..")
    @ExcelProperty(value = {"付款单信息","备注"}, index = 23)
    private String remark;

    @ApiModelProperty(value = "审批实例id",example = "dingtalk:Bgd6Yqw2Sw-XE8KYVI2fgA02311668951176")
    @ExcelProperty(value = {"付款单信息","审批实例id"}, index = 24)
    private String bpmiInstanceId;

    @ApiModelProperty(value = "已作废",example = "0")
    @ExcelProperty(value = {"付款单信息","已作废"}, index = 25)
    private String isVoided;

    @ApiModelProperty(value = "单据编号",example = "CGFK-221110-001")
    @ExcelProperty(value = {"付款单信息","单据编号"}, index = 26)
    private String billNo;

    @ApiModelProperty(value = "是否红字",example = "0")
    @ExcelProperty(value = {"付款单信息","是否红字"}, index = 27)
    private String isRubric;

    @ApiModelProperty(value = "源单类型",example = "FinPaymentReq:2011")
    @ExcelProperty(value = {"付款单信息","源单类型"}, index = 28)
    private String srcBillType;

    @ApiModelProperty(value = "制单时间",example = "2023-02-22 23:04:27")
    @ExcelProperty(value = {"付款单信息","制单时间"}, index = 29, converter = LocalDateTimeStringConverter.class)
    @TableField(fill = FieldFill.INSERT)
    private LocalDateTime createTime;

    @ApiModelProperty(value = "生效时间",example = "2023-02-22 23:04:27")
    @ExcelProperty(value = {"付款单信息","生效时间"}, index = 30, converter = LocalDateTimeStringConverter.class)
    private LocalDateTime effectiveTime;

    @ApiModelProperty(value = "核批人",example = "admin")
    @ExcelProperty(value = {"付款单信息","核批人"}, index = 31)
    private String approver;

    @ApiModelProperty(value = "修改人",example = "admin")
    @ExcelProperty(value = {"付款单信息","修改人"}, index = 32)
    private String updateBy;

    @ApiModelProperty(value = "制单部门",example = "A01A03")
    @ExcelProperty(value = {"付款单信息","制单部门"}, index = 33)
    private String sysOrgCode;

    @ApiModelProperty(value = "已关闭",example = "0")
    @ExcelProperty(value = {"付款单信息","已关闭"}, index = 34)
    private String isClosed;

    @ApiModelProperty(value = "核批结果类型",example = "1")
    @ExcelProperty(value = {"付款单信息","核批结果类型"}, index = 35)
    private String approvalResultType;

    @ApiModelProperty(value = "单据日期",example = "2022-01-14")
    @ExcelProperty(value = {"付款单信息","单据日期"}, index = 36, converter = LocalDateStringConverter.class)
    private LocalDate billDate;

    @ApiModelProperty(value = "制单人",example = "admin")
    @ExcelProperty(value = {"付款单信息","制单人"}, index = 37)
    private String createBy;

    @ApiModelProperty(value = "核批意见",example = "通过")
    @ExcelProperty(value = {"付款单信息","核批意见"}, index = 38)
    private String approvalRemark;


    // 以下为非表显内容,不导出到Excel
    @ApiModelProperty(value = "id",example = "1590727821862420481")
    @ExcelIgnore
    private String id;

    @ApiModelProperty(value = "付款类型",example = "2011")
    @ExcelIgnore
    private String paymentType; //该字段来自实体类，名称存疑，暂时舍弃

    @ApiModelProperty(value = "修改时间",example = "2022-11-21 08:56:09")
    @ExcelIgnore
    private LocalDateTime updateTime;

    @ApiModelProperty(value = "版本",example = "1.0")
    @ExcelIgnore
    private Integer version;

    // 以下为明细表的字段
    @ApiModelProperty(value = "eID",example = "1590727821900169217")
    @ExcelIgnore
    private String eid;

    @ApiModelProperty(value = "主表",example = "1590727821862420481")
    @ExcelIgnore
    private String mid;

    @ApiModelProperty(value = "版本",example = "1.0")
    @ExcelIgnore
    private Integer eVersion;
}
