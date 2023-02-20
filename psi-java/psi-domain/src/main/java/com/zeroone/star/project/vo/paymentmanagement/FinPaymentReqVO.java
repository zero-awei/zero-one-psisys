package com.zeroone.star.project.vo.paymentmanagement;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import lombok.Data;

import java.math.BigDecimal;
import java.time.LocalDate;

/**
 * @author 白也
 * @title 付款申请单据列表
 * @date 2023/2/15 8:22 下午
 */

@Data
@ApiModel("单据列表查询对象")
public class FinPaymentReqVO extends PageQuery {
    /**
     * 单据编号
     */
    private String billNo;
    /**
     * 单据日期
     */
    private LocalDate billDate;
    /**
     * 单据主题
     */
    private String subject;
    /**
     * 付款类型
     */
    private String paymentType;
    /**
     * 供应商
     */
    private String supplierId;
    /**
     * 业务部门
     */
    private String opDept;
    /**
     * 业务员
     */
    private String operator;
    /**
     * 申请金额
     */
    private BigDecimal amt;
    /**
     * 已付金额
     */
    private BigDecimal paidAmt;
    /**
     * 备注
     */
    private String remark;
    /**
     * 已关闭
     */
    private Integer isClosed;
}
