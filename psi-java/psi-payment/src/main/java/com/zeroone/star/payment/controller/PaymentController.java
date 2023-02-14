package com.zeroone.star.payment.controller;

import com.zeroone.star.project.dto.payment.DeleteDTO;
import com.zeroone.star.project.payment.PaymentApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/finPayment")
@ApiOperation(value = "预付接口")
public class PaymentController implements PaymentApis {
    @DeleteMapping("delete")
    @ApiOperation(value = "删除信息")
    @Override
    public JsonVO<String> deleteById(DeleteDTO deleteDTO) {
        return JsonVO.success("删除成功");

    }
}
