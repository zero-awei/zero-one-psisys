package com.zeroone.star.payment.service;

import com.zeroone.star.project.dto.paymentManager.ChosenExportDto;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.paymentManager.ChosenExportVo;

public interface PaymentManagerService {
    void importAll();

    void updateBillStage(Integer id);

    JsonVO chosenExport(ChosenExportDto chosenExportDto);
}
