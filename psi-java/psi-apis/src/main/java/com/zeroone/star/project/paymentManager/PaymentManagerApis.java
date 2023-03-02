package com.zeroone.star.project.paymentManager;

import cn.hutool.http.server.HttpServerResponse;
import cn.hutool.json.JSON;
import com.zeroone.star.project.dto.paymentManager.ChosenExportDto;
import com.zeroone.star.project.dto.paymentManager.UpdateBillStageDto;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.paymentManager.ChosenExportVo;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.multipart.MultipartFile;

import javax.servlet.http.HttpServletResponse;
import java.util.List;

public interface PaymentManagerApis {

    JsonVO importAll(MultipartFile file);

    JsonVO updateBillStage(UpdateBillStageDto updateBillStageDto);

    JsonVO chosenExport(ChosenExportDto chosenExportDto, HttpServletResponse httpServletResponse);
}
