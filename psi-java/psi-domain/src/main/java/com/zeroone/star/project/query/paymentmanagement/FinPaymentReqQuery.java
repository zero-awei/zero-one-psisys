package com.zeroone.star.project.query.paymentmanagement;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import lombok.Data;
import java.time.LocalDate;

/**
 * @author 白也
 * @title 付款申请查询
 * @date 2023/2/15 8:22 下午
 */

@Data
@ApiModel("单据列表查询对象")
public class FinPaymentReqQuery extends PageQuery {
    /**
     * 单据编号
     */
    private String billNo;
    /**
     * 单据日期
     */
    private LocalDate billDate;
}
