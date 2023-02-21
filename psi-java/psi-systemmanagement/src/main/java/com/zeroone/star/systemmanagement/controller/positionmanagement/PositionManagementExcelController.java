package com.zeroone.star.systemmanagement.controller.positionmanagement;

import cn.hutool.core.date.DateTime;
import com.alibaba.excel.EasyExcel;
import com.alibaba.excel.context.AnalysisContext;
import com.alibaba.excel.event.AnalysisEventListener;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.systemmanagement.entity.addressbook.User;
import com.zeroone.star.systemmanagement.entity.positionmanagement.Position;
import com.zeroone.star.systemmanagement.service.positionmanagement.IPositionService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.PostConstruct;
import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.nio.charset.StandardCharsets;
import java.util.List;

/**
 * <p>
 * 职务表的导入导出
 * </p>
 *
 * @author mumu
 * @since 2023-02-14
 */
@Controller
@RequestMapping("excel-positionmanagement")
@Api(tags = "职务信息导出导入")
public class PositionManagementExcelController {
    @Resource
    EasyExcelComponent excel;
    @Resource
    FastDfsClientComponent dfsClient;
    @Resource
    IPositionService positionService;
    /*
    职务信息导出
     */
    @SneakyThrows
    @ApiOperation(value = "获取导出文件")
    @GetMapping(value = "get-file", produces = "application/octet-stream")
    public ResponseEntity<byte[]> download() {
        List<Position> positions = positionService.listPosition();
        // 导出Excel
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        excel.export("测试", out, Position.class, positions);
        // 创建响应头
        HttpHeaders headers = new HttpHeaders();
        // 构建一个下载的文件名称
        String fileName = "test-" + DateTime.now().toString("yyyyMMddHHmmssS") + ".xlsx";
        fileName = new String(fileName.getBytes(StandardCharsets.UTF_8), StandardCharsets.ISO_8859_1);
        headers.setContentDispositionFormData("attachment", fileName);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        ResponseEntity<byte[]> result = new ResponseEntity<>(out.toByteArray(), headers, HttpStatus.CREATED);
        out.close();
        return result;
    }


    @Value("${fastdfs.nginx-servers}")
    private String serverUrl;

    @SneakyThrows
    @ApiOperation(value = "获取导出链接（返回值data值表示导出链接）")
    @ResponseBody
    @GetMapping("get-downloadurl")
    public JsonVO<String> downloadUrl() {
        List<Position> positions = positionService.listPosition();
        // 导出Excel
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        excel.export("测试", out, Position.class, positions);
        // 上传到fastdfs
        String suffix = "xlsx";
        FastDfsFileInfo result = dfsClient.uploadFile(out.toByteArray(), suffix);
        // 关闭输出流
        out.close();
        // 处理传递结果
        if (result == null) {
            return JsonVO.fail("文件上传失败");
        }
        // 拼接文件下载地址
        String downloadUrl = dfsClient.fetchUrl(result, serverUrl, true);
        return JsonVO.success(downloadUrl);
    }

    @SneakyThrows
    @ApiOperation(value = "文件导入")
    @ResponseBody
    @PostMapping("upload")
    public JsonVO<String> uploadUrl(MultipartFile file) throws IOException {
        if (file == null) {
            return JsonVO.fail("未上传文件");
        }
        // 获取上传的文件流
        InputStream inputStream = file.getInputStream();
        // 读取Excel
        EasyExcel.read(inputStream, Position.class,
                new AnalysisEventListener<Position>() {
                    // 每解析一行数据,该方法会被调用一次
                    @Override
                    public void invoke(Position position, AnalysisContext analysisContext) {
                        positionService.insertOne(position);
                    }
                    // 全部解析完成被调用
                    @Override
                    public void doAfterAllAnalysed(AnalysisContext analysisContext) {
                    }
                }).sheet().doRead();
        return JsonVO.success(file.getName());
    }
}