package com.zeroone.star.payablemanagement;


import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.payablemanagement.entity.FinPayable;
import com.zeroone.star.payablemanagement.mapper.FinPayableMapper;
import com.zeroone.star.payablemanagement.service.impl.FinPayableServiceImpl;
import com.zeroone.star.payablemanagement.utils.SnowFlakeShortUrl;
import com.zeroone.star.payablemanagement.utils.TransformationUtils;
import com.zeroone.star.project.dto.payablemanagement.PayableDTO;
import com.zeroone.star.project.dto.payablemanagement.PayableStatusDTO;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.stereotype.Component;

import java.math.BigDecimal;
import java.time.LocalDateTime;

@SpringBootTest
@Component
public class PayableTest {
    @Autowired
    FinPayableMapper finPayableMapper;
    @Autowired
    FinPayableServiceImpl service;
    @Test
    public void payableConvertTest(){
        PayableDTO payableDTO = new PayableDTO();
        FinPayable entity = new FinPayable();
        payableDTO.setApprovalRemark("pass");
        payableDTO.setBillNo("114514");
        payableDTO.setIsAuto(1);
        payableDTO.setIsClosed(0);
        try {
            entity = TransformationUtils.convert(payableDTO,FinPayable.class);
//            entity = TransformationUtils.transmissionCreateDTO(payableDTO);
        } catch (IllegalAccessException e) {
            throw new RuntimeException(e);
        }
        System.out.println(entity);
    }

    @Test
    public void payableServiceTest(){

        FinPayable entity = new FinPayable();
        PayableDTO payableDTO = new PayableDTO();
        payableDTO.setId("1114445551919810");
        payableDTO.setBillNo("7777777");
//        payableDTO.setBillDate(LocalDateTime.now());
//        payableDTO.setIsRubric(0);
//        payableDTO.setPayableType("已处理订单");
//        payableDTO.setSupplierId("1584951160223113218");
//        payableDTO.setAmt(BigDecimal.valueOf(800));
//        payableDTO.setCheckedAmt(BigDecimal.valueOf(400));
//        payableDTO.setIsAuto(1);
//        payableDTO.setBillStage("54");
//        payableDTO.setIsEffective(1);
//        payableDTO.setIsClosed(0);
//        payableDTO.setIsVoided(0);
//        System.out.println(service.addOtherPayable(payableDTO));
        QueryWrapper<FinPayable> wrapper = new QueryWrapper<>();
        wrapper.eq("bill_no", payableDTO.getBillNo());

        //与传入payableStatus相同BillNo的数据库中的实体类
        FinPayable finPayableDB = finPayableMapper.selectOne(wrapper);
        System.out.println(finPayableDB);
    }

    @Test
    public void mapperTest(){

        FinPayable entity = new FinPayable();
        PayableStatusDTO statusDTO = new PayableStatusDTO();
        statusDTO.setId("1114445551919810");
        statusDTO.setBillNo("7777777");
        statusDTO.setIsVoided(0);
        statusDTO.setIsClosed(1);
        try {
            entity= TransformationUtils.convert(statusDTO,FinPayable.class);
        } catch (IllegalAccessException e) {
            throw new RuntimeException(e);
        }
        System.out.println(finPayableMapper.updateById(entity));
//        entity.setCreateBy("venti");
//        entity.setCreateBy("xxq");
//
//        entity.setId("1114445551919");
//        entity.setBillNo("1919810");
//        entity.setBillDate(LocalDateTime.now());
//        entity.setIsRubric(0);
//        entity.setPayableType("已处理订单");
//        entity.setSupplierId("1584951160223113218");
//        entity.setAmt(BigDecimal.valueOf(100));
//        entity.setCheckedAmt(BigDecimal.valueOf(200));
//        entity.setIsAuto(1);
//        entity.setBillStage("55");
//        entity.setIsEffective(1);
//        entity.setIsClosed(0);
//        entity.setIsVoided(0);
//        System.out.println(finPayableMapper.insert(entity));
    }

    @Test
    public void generateIdTest(){
        SnowFlakeShortUrl snowFlakeShortUrl = new SnowFlakeShortUrl(5,3);
        System.out.println(snowFlakeShortUrl.nextId());
    }
}
