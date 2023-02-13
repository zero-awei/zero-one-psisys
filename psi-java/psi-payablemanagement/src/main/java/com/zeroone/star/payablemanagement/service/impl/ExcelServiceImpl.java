package com.zeroone.star.payablemanagement.service.impl;

import com.zeroone.star.payablemanagement.service.ExcelService;
import com.zeroone.star.project.utils.easyexcel.EasyExcelUtils;
import com.zeroone.star.project.vo.payablemanagement.OthersPayableVO;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;

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
     * @return
     */
    @Override
    public ResponseEntity<byte[]> downloadOthersPayable() {
        // TODO 装填list、map
        List<OthersPayableVO> list = null;
        Map<String, Object> map = null;

        return EasyExcelUtils.downloadsAsTemplate(othersPayableExcelName, list, map);
    }
}
