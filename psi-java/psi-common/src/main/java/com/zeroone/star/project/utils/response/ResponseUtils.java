package com.zeroone.star.project.utils.response;

import cn.hutool.core.date.DateTime;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;

import java.nio.charset.StandardCharsets;

/**
 * 响应工具类
 *
 * @author iceberg-work
 */
public class ResponseUtils {

    private ResponseUtils() {}

    /**
     * 生成响应体，Content-type为image/jpeg
     *
     * @param bytes 二进制流
     * @return 介质类型为JPG类型的HTTP响应体
     */
    public static ResponseEntity<byte[]> bytes2Jpg(byte[] bytes) {
        // 构建一个下载的文件名称
        String fileName = "img-" + DateTime.now().toString("yyyyMMddHHmmssS") + ".jpg";
        return makeBytesResponseEntity(bytes, fileName, MediaType.IMAGE_JPEG);
    }

    /**
     * 生成响应体，Content-type为application/octet-stream
     *
     * @param bytes 二进制流
     * @return 介质类型为JPG类型的HTTP响应体
     */
    public static ResponseEntity<byte[]> bytes2Xlsx(byte[] bytes, String sheetName) {
        // 构建一个下载的文件名称
        String fileName = sheetName + "-" + DateTime.now().toString("yyyyMMddHHmmssS") + ".xlsx";
        return makeBytesResponseEntity(bytes, fileName, MediaType.APPLICATION_OCTET_STREAM);
    }

    /**
     * 生成响应体
     *
     * @param bytes 二进制流
     * @param fileName 文件名
     * @param mediaType 介质类型
     * @return HTTP响应体
     */
    private static ResponseEntity<byte[]> makeBytesResponseEntity(byte[] bytes,
                                                                  String fileName,
                                                                  MediaType mediaType) {
        // 创建响应头
        HttpHeaders headers = new HttpHeaders();
        fileName = new String(fileName.getBytes(StandardCharsets.UTF_8), StandardCharsets.ISO_8859_1);
        headers.setContentDispositionFormData("attachment", fileName);
        headers.setContentType(mediaType);
        return new ResponseEntity<>(bytes, headers, HttpStatus.CREATED);
    }
}
