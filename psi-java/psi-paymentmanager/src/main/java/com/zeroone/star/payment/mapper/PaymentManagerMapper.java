package com.zeroone.star.payment.mapper;

import com.zeroone.star.project.dto.paymentManager.ChosenExportDto;
import com.zeroone.star.project.vo.paymentManager.ChosenExportVo;
import org.apache.ibatis.annotations.Param;
import org.springframework.stereotype.Repository;

import java.util.List;
@Repository
public interface PaymentManagerMapper {
    List<ChosenExportVo> chosenExport(@Param("dto") ChosenExportDto chosenExportDto);
}
