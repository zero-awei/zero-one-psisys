package com.zeroone.star.project.vo.paymentmanagement;

import com.zeroone.star.paymentmanagement.entity.FinPaymentReqEntry;
import io.swagger.annotations.ApiModel;
import lombok.Data;

@Data
@ApiModel("查询指点单据信息")
public class ViewSpecifiedDocInfVO extends FinPaymentReqEntry {
}
