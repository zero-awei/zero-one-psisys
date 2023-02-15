package com.zeroone.star.payment.controller;

import com.zeroone.star.payment.service.IFinPaymentReqEntryService;
import com.zeroone.star.project.payment.PaymentApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payment.PaymentReqEntryVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;

@RestController
@RequestMapping("/payment")
@Api(tags = "预付款管理")
public class PaymentController implements PaymentApis {
    @Resource
    IFinPaymentReqEntryService iFinPaymentReqEntryService;

    /**
     * 付款申请单分录明细列表查询
     * @param billNo 分录单号
     * @return 分录明细列表
     */
    @GetMapping("/{billNo}")
    @Override
    @ApiOperation("付款申请单分录列表查询")
    public JsonVO<PageVO<PaymentReqEntryVO>> queryAllByBillNo(@PathVariable("billNo") String billNo) {
        return JsonVO.success(iFinPaymentReqEntryService.getByBillNo(billNo));
    }

    /**
     * Excel 表格导入
     * @param file Excel 文件
     * @return 处理结果
     */
    @Override
    @PostMapping("/import")
    @ResponseBody
    @ApiOperation("Excel表格导入")
    public JsonVO<String> excelImport(@RequestParam("file") MultipartFile file) {
        return JsonVO.success("文件上传成功！");
    }
}
