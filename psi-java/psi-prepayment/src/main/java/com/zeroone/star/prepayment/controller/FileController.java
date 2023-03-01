package com.zeroone.star.prepayment.controller;

import com.zeroone.star.prepayment.service.IFinPaymentService;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;

@Controller
@RequestMapping("file")
@Api(tags = "文件操作")
public class FileController {
    @Resource
    FastDfsClientComponent dfsClient;

    @Value("${fastdfs.nginx-servers}")
    private String serverUrl;

    @Resource
    IFinPaymentService paymentService;
    /**
     * 上传附件
     * author forever爱、KONG
     */
    @SneakyThrows
    @ApiOperation(value = "文件上传")
    @ResponseBody
    @PostMapping("upload")
    public JsonVO<String> upload(MultipartFile file) {
        // 获取文件名
        String filename = file.getOriginalFilename();
        if (filename == null) {
            return JsonVO.fail("文件名为空");
        }
        // 获取文件的后缀
        String suffix = filename.substring(filename.lastIndexOf(".") + 1);
        // 上传文件到FastDFS
        FastDfsFileInfo result = dfsClient.uploadFile(file.getBytes(), suffix);
        if (result == null) {
            return JsonVO.fail("文件上传失败");
        }
        // 拼接文件下载地址
        String downloadUrl = dfsClient.fetchUrl(result, serverUrl, true);
        return JsonVO.success(downloadUrl);
    }

    /**
     * 导出功能实现
     * author 明破
     * since 2023-02-13
     */
    @GetMapping("export")
    @ApiOperation(value = "导出功能")
    public ResponseEntity<byte[]> download() {
        return null;
    }

    @ApiOperation(value = "获取导出链接")
    public JsonVO<String> downloadUrl() {
        return null;
    }

    /**
     * Excel 表格导入
     * param file Excel 文件
     * return 处理结果
     * author 内鬼
     */
    @PostMapping("import-payments-excel")
    @ResponseBody
    @ApiOperation("导入功能（返回值data值表示导入成功与否）")
    public JsonVO<String> excelImport(@RequestParam("file") MultipartFile file) {
        try {
            paymentService.importExcelOfPayment(file);
        } catch (Exception e) {
            e.printStackTrace();
            return JsonVO.fail("文件导入失败");
        }
        return JsonVO.success("文件导入成功！");
    }
}
