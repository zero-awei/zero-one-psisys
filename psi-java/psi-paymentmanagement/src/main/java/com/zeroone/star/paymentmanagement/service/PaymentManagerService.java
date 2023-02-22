package com.zeroone.star.paymentmanagement.service;

import com.zeroone.star.project.dto.paymentManager.ChosenExportDto;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.paymentManager.ChosenExportVo;

import java.util.List;

public interface PaymentManagerService {
    void importAll();

    void updateBillStage(Integer id);

    JsonVO chosenExport(ChosenExportDto chosenExportDto);
}
