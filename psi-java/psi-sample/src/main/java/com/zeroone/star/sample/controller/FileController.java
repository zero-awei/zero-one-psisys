package com.zeroone.star.sample.controller;

import cn.hutool.core.date.DateTime;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.nio.charset.StandardCharsets;

/**
 * <p>
 * 描述：演示文件上传和下载
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Controller
@RequestMapping("file")
@Api(tags = "文件操作")
public class FileController {
    @Resource
    FastDfsClientComponent dfsClient;

    @Value("${fastdfs.nginx-servers}")
    private String serverUrl;

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

    @SneakyThrows
    @ApiOperation(value = "文件下载")
    @GetMapping(value = "download", produces = "image/jpeg")
    public ResponseEntity<byte[]> download(String group, String storageId) {
        // 进行下载
        byte[] bytes = dfsClient.downloadFile(FastDfsFileInfo.builder().storageId(storageId).group(group).build());
        // 创建响应头
        HttpHeaders headers = new HttpHeaders();
        // 构建一个下载的文件名称
        String fileName = "img-" + DateTime.now().toString("yyyyMMddHHmmssS") + ".jpg";
        fileName = new String(fileName.getBytes(StandardCharsets.UTF_8),StandardCharsets.ISO_8859_1);
        headers.setContentDispositionFormData("attachment", fileName);
        headers.setContentType(MediaType.IMAGE_JPEG);
        return new ResponseEntity<>(bytes, headers, HttpStatus.CREATED);
    }

    @SneakyThrows
    @ApiOperation(value = "删除文件")
    @ResponseBody
    @DeleteMapping(value = "delete")
    public JsonVO<Integer> deleteFile(String group, String storageId) {
        int res = dfsClient.deleteFile(FastDfsFileInfo.builder().group(group).storageId(storageId).build());
        if (res == 0) {
            return JsonVO.success(res);
        }
        return JsonVO.fail(res);
    }
}
