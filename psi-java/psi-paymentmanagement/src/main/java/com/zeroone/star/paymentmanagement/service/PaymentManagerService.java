package com.zeroone.star.paymentmanagement.service;

import com.zeroone.star.project.dto.paymentManager.ChosenExportDto;
import com.zeroone.star.project.dto.paymentManager.UpdateBillStageDto;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.paymentManager.ChosenExportVo;
import org.springframework.web.multipart.MultipartFile;

public interface PaymentManagerService {
    void importAll(MultipartFile file);

    JsonVO updateBillStage(UpdateBillStageDto updateBillStageDto);

    JsonVO chosenExport(ChosenExportDto chosenExportDto);

    void importReq(MultipartFile file);

    void updateBillStageReq(UpdateBillStageDto updateBillStageDto);
}
