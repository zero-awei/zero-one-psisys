package com.zeroone.star.payablemanagement.service;

import org.springframework.http.ResponseEntity;

/**
 * 专门处理Excel
 *
 * @author iceberg-work
 */
public interface ExcelService {

    /**
     * 下载其他应付EXCEL
     *
     * @author iceberg-work
     * @return 二进制文件流
     */
    ResponseEntity<byte[]> downloadOthersPayable();
}
