package com.zeroone.star.payment.controller;

import com.zeroone.star.project.payment.ExcelApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.multipart.MultipartFile;

@Controller
@RequestMapping("/payment/fin-payment-req-excel")
@Api(tags = "数据导入与导出")
public class ExcelController implements ExcelApis {

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
