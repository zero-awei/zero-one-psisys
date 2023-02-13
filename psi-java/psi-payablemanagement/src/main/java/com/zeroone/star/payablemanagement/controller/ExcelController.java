package com.zeroone.star.payablemanagement.controller;

import com.zeroone.star.payablemanagement.service.ExcelService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import javax.validation.constraints.NotNull;

/**
 * Excel导出、导入
 *
 * @author iceberg-work
 */
@Controller
@RequestMapping("excel")
@Api(tags = "Excel")
@RestController
public class ExcelController {

    @Resource
    ExcelService excelService;

    @ApiOperation("模板导出其他应付Excel")
    @PostMapping(value = "importOthersPayableExcelAsTemplate", produces = "application/octet-stream")
    public ResponseEntity<byte[]> importOthersPayableExcelAsTemplate() {
        return excelService.downloadOthersPayableAsTemplate();
    }

    @ApiOperation("导入其他应付Excel")
    @PostMapping(value = "importOthersPayable")
    @Transactional(rollbackFor = Exception.class)
    public Boolean importOthersPayableExcel(@RequestParam("file") @NotNull MultipartFile file) {
        return excelService.importOthersPayableExcel(file);
    }
}
