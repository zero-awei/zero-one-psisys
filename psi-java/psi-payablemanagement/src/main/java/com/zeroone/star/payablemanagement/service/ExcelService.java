package com.zeroone.star.payablemanagement.service;

import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.multipart.MultipartFile;

import javax.validation.constraints.NotNull;

/**
 * 专门处理Excel
 *
 * @author iceberg-work
 */
public interface ExcelService {

    /**
     * 下载按照模板其他应付Excel
     *
     * @author iceberg-work
     * @return 二进制文件流
     */
    ResponseEntity<byte[]> downloadOthersPayableAsTemplate();

    /**
     * 导入其他应付Excel
     *
     * @author iceberg-work
     * @param file 二进制文件流
     * @return 成功与否
     */
    Boolean importOthersPayableExcel(MultipartFile file);
}
