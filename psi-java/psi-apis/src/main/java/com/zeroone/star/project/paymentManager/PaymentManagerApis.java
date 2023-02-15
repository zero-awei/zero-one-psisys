package com.zeroone.star.project.paymentManager;

import com.zeroone.star.project.vo.JsonVO;
import org.springframework.web.multipart.MultipartFile;

public interface PaymentManagerApis {

    JsonVO importAll(MultipartFile file);

    JsonVO updateBillStage(Integer id);
}
