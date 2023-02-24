package com.zeroone.star.paymentmanagement.mapper;

import com.zeroone.star.paymentmanagement.entity.FinPayment;
import com.zeroone.star.project.dto.paymentManager.ChosenExportDto;
import com.zeroone.star.project.dto.paymentManager.UpdateBillStageDto;
import com.zeroone.star.project.vo.paymentManager.ChosenExportVo;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;

@Mapper
public interface PaymentManagerMapper {
    List<ChosenExportVo> chosenExport(@Param("dto") ChosenExportDto chosenExportDto);

    void updateBillStage(UpdateBillStageDto updateBillStageDto);

    void insertList(List<FinPayment> finPayments);
}