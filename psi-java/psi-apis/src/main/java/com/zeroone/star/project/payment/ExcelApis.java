package com.zeroone.star.project.payment;

import com.zeroone.star.project.vo.JsonVO;
import org.springframework.web.multipart.MultipartFile;

public interface ExcelApis {
    JsonVO<String> excelImport(MultipartFile file);
}
