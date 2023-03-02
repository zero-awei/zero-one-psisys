package com.zeroone.star.paymentmanagement.service.impl;

import cn.hutool.poi.excel.ExcelReader;
import cn.hutool.poi.excel.ExcelUtil;
import com.zeroone.star.paymentmanagement.entity.FinPayment;
import com.zeroone.star.paymentmanagement.exception.BaseException;
import com.zeroone.star.paymentmanagement.mapper.PaymentManagerMapper;
import com.zeroone.star.paymentmanagement.service.PaymentManagerService;
import com.zeroone.star.project.dto.paymentManager.ChosenExportDto;
import com.zeroone.star.project.dto.paymentManager.UpdateBillStageDto;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.paymentManager.ChosenExportVo;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.util.StringUtils;
import org.springframework.web.multipart.MultipartFile;

import java.io.IOException;
import java.io.InputStream;
import java.util.List;

@Service
public class PaymentManagerImpl implements PaymentManagerService {

    @Autowired
    PaymentManagerMapper paymentManagerMapper;

    @Override
    public void importAll(MultipartFile file) {
        try {
            InputStream inputStream = file.getInputStream();
            ExcelReader reader = ExcelUtil.getReader(inputStream);
            List<FinPayment> finPayments = reader.readAll(FinPayment.class);
            paymentManagerMapper.insertList(finPayments);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Override
    public JsonVO updateBillStage(UpdateBillStageDto updateBillStageDto) {
        if (StringUtils.isEmpty(updateBillStageDto.getBillStage())||updateBillStageDto.getId()==null){
            Object[] args={updateBillStageDto.getBillStage(),updateBillStageDto.getId()};
            throw  new BaseException("PaymentManager",String.valueOf(ResultStatus.PARAM_NULL.getCode()),args,ResultStatus.PARAM_NULL.getMessage());
        }
        paymentManagerMapper.updateBillStage(updateBillStageDto);
        return JsonVO.success(null);
    }

    @Override
    public JsonVO chosenExport(ChosenExportDto chosenExportDto) {
//        List<ChosenExportVo> chosenExportVos = paymentManagerMapper.chosenExport(chosenExportDto);
//        return JsonVO.success(chosenExportVos);
        return null;
    }
}
