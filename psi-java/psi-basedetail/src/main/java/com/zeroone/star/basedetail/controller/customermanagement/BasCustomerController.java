package com.zeroone.star.basedetail.controller.customermanagement;


import cn.hutool.core.date.DateTime;
import com.alibaba.excel.EasyExcel;
import com.alibaba.excel.ExcelReader;
import com.alibaba.excel.context.AnalysisContext;
import com.alibaba.excel.event.AnalysisEventListener;
import com.alibaba.excel.read.metadata.ReadSheet;
import com.zeroone.star.basedetail.entity.BasCustomer;
import com.zeroone.star.basedetail.entity.User;
import com.zeroone.star.basedetail.service.IBasCustomerService;
import com.zeroone.star.basedetail.service.impl.BasCustomerServiceImpl;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.PostConstruct;
import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.io.InputStream;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 客户 前端控制器
 * </p>
 *
 * @author ss
 * @since 2023-02-14
 */
@RestController
@RequestMapping("/basedetail/bas-customer")
@Api(tags = "客户导入导出")
public class BasCustomerController {
    @Autowired
    private BasCustomerServiceImpl basCustomerService;
    @Resource
    EasyExcelComponent excel;
    private List<User> users;

    @PostConstruct
    public void initData() {
        users = new ArrayList<>(50);
        for (int i = 1; i <= 50; i++) {
            User u = new User();
            u.setId(i);
            u.setName("用户" + i);
            u.setPhone("1234567" + i);
            users.add(u);
        }
    }

    @SneakyThrows
    @ApiOperation(value = "获取导出文件")
    @GetMapping(value = "get-file", produces = "application/octet-stream")
    public ResponseEntity<byte[]> download() {
        List<BasCustomer> basCustomers = basCustomerService.listBasCustomer();
        // 导出Excel
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        excel.export("测试", out, BasCustomer.class, basCustomers);
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

    @Resource
    FastDfsClientComponent dfsClient;

    @Value("${fastdfs.nginx-servers}")
    private String serverUrl;

    @SneakyThrows
    @ApiOperation(value = "获取导出链接（返回值data值表示导出链接）")
    @ResponseBody
    @GetMapping("get-url")
    public JsonVO<String> downloadUrl() {
        List<BasCustomer> basCustomers = basCustomerService.listBasCustomer();
        // 导出Excel
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        excel.export("测试", out, BasCustomer.class, basCustomers);
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
    @ApiOperation(value = "文件导入（返回值data值表示导入链接）")
    @ResponseBody
    @PostMapping("upload")
    public JsonVO<String> upload(MultipartFile file) {
        if (file == null) {
            return JsonVO.fail("未上传文件");
        }
        // 获取上传的文件流
        InputStream inputStream = file.getInputStream();
        // 读取Excel
        EasyExcel.read(inputStream, BasCustomer.class,
                new AnalysisEventListener<BasCustomer>() {
                    // 每解析一行数据,该方法会被调用一次
                    @Override
                    public void invoke(BasCustomer basCustomer, AnalysisContext analysisContext) {
                        basCustomerService.insertOne(basCustomer);
                    }
                    // 全部解析完成被调用
                    @Override
                    public void doAfterAllAnalysed(AnalysisContext analysisContext) {
                    }
                }).sheet().doRead();
        return JsonVO.success(file.getName());
    }
}
