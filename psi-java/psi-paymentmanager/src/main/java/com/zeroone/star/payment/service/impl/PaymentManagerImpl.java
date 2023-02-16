package com.zeroone.star.payment.service.impl;

import com.zeroone.star.payment.mapper.PaymentManagerMapper;
import com.zeroone.star.payment.service.PaymentManagerService;
import com.zeroone.star.project.dto.paymentManager.ChosenExportDto;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.paymentManager.ChosenExportVo;
import org.springframework.beans.factory.annotation.Autowired;
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
