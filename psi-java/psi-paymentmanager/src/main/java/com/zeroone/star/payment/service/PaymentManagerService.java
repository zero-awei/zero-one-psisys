package com.zeroone.star.payment.service;

import com.zeroone.star.project.dto.paymentManager.ChosenExportDto;

public interface PaymentManagerService {
    void importAll();

    void updateBillStage(Integer id);

    void chosenExport(ChosenExportDto chosenExportDto);
}
