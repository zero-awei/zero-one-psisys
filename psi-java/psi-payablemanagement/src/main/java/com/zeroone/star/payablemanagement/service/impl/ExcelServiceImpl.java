package com.zeroone.star.payablemanagement.service.impl;

import com.zeroone.star.payablemanagement.service.ExcelService;
import com.zeroone.star.project.dto.payablemanagement.OthersPayableDTO;
import com.zeroone.star.project.utils.easyexcel.EasyExcelUtils;
import com.zeroone.star.project.vo.payablemanagement.OthersPayableVO;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;
import java.util.Map;

/**
 * {@inheritDoc}
 *
 * @author iceberg-work
 */
@Service
public class ExcelServiceImpl implements ExcelService {

    @Value("${customization.name.OthersPayable}")
    String othersPayableExcelName;

    /**
     * {@inheritDoc}
     */
    @Override
    public ResponseEntity<byte[]> downloadOthersPayableAsTemplate() {
        // TODO 装填list、map
        List<OthersPayableVO> list = null;
        Map<String, Object> map = null;

        return EasyExcelUtils.downloadsAsTemplate(othersPayableExcelName, list, map);
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public Boolean importOthersPayableExcel(MultipartFile file) {
        List<OthersPayableDTO> list = EasyExcelUtils.imports(file, OthersPayableDTO.class);
        System.out.println("list = " + list);
        // TODO 将列表数据按照特定映射存入数据库
        return Boolean.TRUE;
    }
}
