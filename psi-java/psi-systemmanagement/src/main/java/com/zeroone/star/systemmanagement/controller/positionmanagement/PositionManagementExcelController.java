package com.zeroone.star.systemmanagement.controller.positionmanagement;

import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.PostConstruct;
import javax.annotation.Resource;

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
@Api(tags = "部门管理导出导入")
public class PositionManagementExcelController {
    @Resource
    EasyExcelComponent excel;

    @PostConstruct
    public void initData() {
    }

    @SneakyThrows
    @ApiOperation(value = "获取导出文件")
    @GetMapping(value = "get-file", produces = "application/octet-stream")
    public ResponseEntity<byte[]> download() {
        return null;
    }


    @Resource
    FastDfsClientComponent dfsClient;

    @Value("${fastdfs.nginx-servers}")
    private String serverUrl;

    @SneakyThrows
    @ApiOperation(value = "获取导出链接（返回值data值表示导出链接）")
    @ResponseBody
    @GetMapping("get-downloadurl")
    public JsonVO<String> downloadUrl() {
        return null;
    }

    @SneakyThrows
    @ApiOperation(value = "获取导入链接（返回值data值表示导入链接）")
    @ResponseBody
    @GetMapping("get-uploadurl")
    public JsonVO<String> uploadUrl(MultipartFile file) {
        return null;
    }
}