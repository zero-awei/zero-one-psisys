package com.zeroone.star.prepayment.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.prepayment.entity.FinPayment;
import com.zeroone.star.prepayment.entity.FinPaymentEntry;
import com.zeroone.star.prepayment.mapper.FinPaymentMapper;
import com.zeroone.star.prepayment.service.IFinPaymentEntryService;
import com.zeroone.star.prepayment.service.IFinPaymentService;
import com.zeroone.star.project.dto.prepayment.FinPaymentEntryDTO;
import com.zeroone.star.project.dto.prepayment.PrepaymentDTO;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.Random;


@Service
public class FinPaymentServiceImpl extends ServiceImpl<FinPaymentMapper, FinPayment> implements IFinPaymentService {

    @Autowired
    FinPaymentMapper finPaymentMapper;
    @Autowired
    IFinPaymentEntryService finPaymentEntryService;

//    public int insert(PrepaymentDTO prepaymentDTO) {
//        //生成19位id
//        long timestamp = System.currentTimeMillis(); // 毫秒级时间戳
//        int randNum = new Random().nextInt(1000000000); // 生成9位随机数
//        String uniqueId = timestamp + String.format("%09d", randNum); // 将时间戳和随机数拼接起来
//        String id = uniqueId.substring(0, 19);// 截取前19位作为最终的唯一ID
//        FinPayment finPayment = new FinPayment();
//        BeanUtils.copyProperties(prepaymentDTO,finPayment);
//        finPayment.setId(id);
//        System.out.println(finPayment.getAmt());
//        System.out.println(finPayment.getBillDate());
//        int res = finPaymentMapper.insert(finPayment);
//        return res;
//    }

    /**
     * 添加采购预付单
     * Author: Kong
     */
    @Override
    @Transactional
    public int prepay(PrepaymentDTO prepaymentDTO){
        //生成19位id
        long timestamp1 = System.currentTimeMillis(); // 毫秒级时间戳
        int randNum1 = new Random().nextInt(1000000000); // 生成9位随机数
        String uniqueId1 = timestamp1 + String.format("%09d", randNum1); // 将时间戳和随机数拼接起来
        String id1 = uniqueId1.substring(0, 19);// 截取前19位作为最终的唯一ID
        FinPayment finPayment = new FinPayment();
        BeanUtils.copyProperties(prepaymentDTO,finPayment);
        finPayment.setId(id1);
        System.out.println(finPayment.getAmt());
        System.out.println(finPayment.getBillDate());
        int res = finPaymentMapper.insert(finPayment);
        int count=0;
        for (FinPaymentEntryDTO finPaymentEntryDTO:prepaymentDTO.getFinPaymentEntryList()){
            //生成19位id
            long timestamp2 = System.currentTimeMillis(); // 毫秒级时间戳
            int randNum2 = new Random().nextInt(1000000000); // 生成9位随机数
            String uniqueId2 = timestamp2 + String.format("%09d", randNum2); // 将时间戳和随机数拼接起来
            String id2 = uniqueId2.substring(0, 19);// 截取前19位作为最终的唯一ID
            FinPaymentEntry finPaymentEntry = new FinPaymentEntry();
            BeanUtils.copyProperties(finPaymentEntryDTO,finPaymentEntry);
            finPaymentEntry.setId(id2);
            finPaymentEntry.setMid(id1);
            finPaymentEntry.setBillNo(prepaymentDTO.getBillNo());//获取单号
            int i = finPaymentEntryService.insert(finPaymentEntry);
            if(i==1) count++;
        }
        if (res!=1 || count!=prepaymentDTO.getFinPaymentEntryList().size()) return 0;
        return 1;
    }
}
