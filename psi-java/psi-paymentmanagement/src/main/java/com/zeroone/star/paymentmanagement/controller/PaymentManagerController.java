package com.zeroone.star.paymentmanagement.controller;

import com.alibaba.excel.EasyExcel;
import com.zeroone.star.paymentmanagement.service.PaymentManagerService;
import com.zeroone.star.project.dto.paymentManager.ChosenExportDto;
import com.zeroone.star.project.dto.paymentManager.UpdateBillStageDto;
import com.zeroone.star.project.paymentManager.PaymentManagerApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.paymentManager.ChosenExportVo;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.var;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;
import java.util.stream.Collectors;

@RestController
@RequestMapping("paymentmanager")
@Api(tags = "应付与付款-付款管理")
@Validated
public class PaymentManagerController implements PaymentManagerApis {
    @Resource
    private PaymentManagerService paymentManagerService;

    @PostMapping("/import")
    @Override
    public JsonVO importAll(MultipartFile file) {
        paymentManagerService.importAll(file);
        return null;
    }

    @Override
    public JsonVO updateBillStage(UpdateBillStageDto updateBillStageDto) {
        paymentManagerService.updateBillStage(updateBillStageDto);
        return null;
    }

    @PostMapping("/export")
    @ApiOperation(value = "选择导出",notes = "选择所需要导出的单据构成一张表导出")
    @Override
    public JsonVO chosenExport(@RequestBody ChosenExportDto chosenExportDto, HttpServletResponse httpServletResponse) {

        List<ChosenExportVo> data= (List<ChosenExportVo>)paymentManagerService.chosenExport(chosenExportDto).getData();
        httpServletResponse.setContentType("application/vnd.ms-excel");
        httpServletResponse.setCharacterEncoding("utf-8");
        httpServletResponse.setHeader("Content-disposition", "attachment;filename=export.xlsx");
        try {
            EasyExcel.write(httpServletResponse.getOutputStream(), ChosenExportVo.class).sheet("表单").doWrite(data);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return JsonVO.success(data);
    }
}
