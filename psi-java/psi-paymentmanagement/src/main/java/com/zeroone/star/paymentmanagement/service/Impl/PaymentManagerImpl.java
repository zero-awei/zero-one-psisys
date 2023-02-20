package com.zeroone.star.payment.service.impl;

import com.zeroone.star.paymentmanagement.service.PaymentManagerService;
import org.springframework.stereotype.Service;

import java.util.List;

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
    public JsonVO chosenExport(ChosenExportDto chosenExportDto) {
        List<ChosenExportVo> chosenExportVos = paymentManagerMapper.chosenExport(chosenExportDto);
        return JsonVO.success(chosenExportVos);
    }
}
