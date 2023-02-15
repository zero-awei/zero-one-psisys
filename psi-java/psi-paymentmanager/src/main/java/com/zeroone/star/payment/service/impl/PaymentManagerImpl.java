package com.zeroone.star.payment.service.impl;

import com.zeroone.star.payment.mapper.PaymentManagerMapper;
import com.zeroone.star.payment.service.PaymentManagerService;
import com.zeroone.star.project.dto.paymentManager.ChosenExportDto;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class PaymentManagerImpl implements PaymentManagerService {

    @Autowired
    PaymentManagerMapper paymentManagerMapper;

    @Override
    public void importAll() {

    }

    @Override
    public void updateBillStage(Integer id) {

    }

    @Override
    public void chosenExport(ChosenExportDto chosenExportDto) {
         paymentManagerMapper.chosenExport(chosenExportDto);
    }
}
