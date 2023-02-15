package com.zeroone.star.project.paymentManager;

import cn.hutool.json.JSON;
import com.zeroone.star.project.dto.paymentManager.ChosenExportDto;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

public interface PaymentManagerApis {

    JsonVO importAll(MultipartFile file);

    JsonVO updateBillStage(Integer id);

    void chosenExport(@RequestBody ChosenExportDto chosenExportDto);
}
