package com.zeroone.star.prepayment.service.impl;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.prepayment.entity.FinPaymentEntry;
import com.zeroone.star.prepayment.mapper.FinPaymentEntryMapper;
import com.zeroone.star.prepayment.service.IFinPaymentEntryService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.prepayment.FinPaymentEntryDTO;
import com.zeroone.star.project.dto.prepayment.ModifyDTO;
import com.zeroone.star.project.dto.prepayment.PrepaymentDTO;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;
import java.util.List;
import java.util.Random;
import java.util.stream.Collectors;

/**
 * <p>
 * 付款单明细 服务实现类
 * </p>
 *
 * @author zhd
 * @since 2023-02-18
 */
@Service
public class FinPaymentEntryServiceImpl extends ServiceImpl<FinPaymentEntryMapper, FinPaymentEntry> implements IFinPaymentEntryService {


    /**
     * 保存付款单明细
     * author forever爱
     */
    @Override
    public boolean saveByBillNo(ModifyDTO modifyDTO) {
        QueryWrapper<FinPaymentEntry> queryWrapper = new QueryWrapper<>();
        queryWrapper.eq("bill_no", modifyDTO.getBillNo());
        baseMapper.delete(queryWrapper);
        List<FinPaymentEntryDTO> entryDTOList = modifyDTO.getEntryDTOList();
        List<FinPaymentEntry> finPaymentEntryList = entryDTOList.stream().map(
                dto -> {
                    FinPaymentEntry entity = new FinPaymentEntry();
                    BeanUtils.copyProperties(dto, entity);
                    return entity;
                }
        ).collect(Collectors.toList());
        return saveBatch(finPaymentEntryList);
    }

    /**
     * 添加
     * Author: Kong
     */
    @Override
    public int insert(PrepaymentDTO prepaymentDTO) {
        //获取主表id TODO MP自动生成的ID如何获取
        String id1 = prepaymentDTO.getId();
        int res = 0;
        for (FinPaymentEntryDTO finPaymentEntryDTO:prepaymentDTO.getFinPaymentEntryList()){
            //生成明细表id
//            long timestamp2 = System.currentTimeMillis(); // 毫秒级时间戳
//            int randNum2 = new Random().nextInt(1000000000); // 生成9位随机数
//            String uniqueId2 = timestamp2 + String.format("%09d", randNum2); // 将时间戳和随机数拼接起来
//            String id2 = uniqueId2.substring(0, 19);// 截取前19位作为最终的唯一ID
            FinPaymentEntry finPaymentEntry = new FinPaymentEntry();
            BeanUtils.copyProperties(finPaymentEntryDTO,finPaymentEntry);
//            finPaymentEntry.setId(id2);
            finPaymentEntry.setMid(id1);//将主表id放入mid
            finPaymentEntry.setBillNo(prepaymentDTO.getBillNo());//获取单号
            res = baseMapper.insert(finPaymentEntry);
        }
        return res;
    }
    @Override
    public List<FinPaymentEntry> listByMid(String mid, String srcBillType) {
        QueryWrapper<FinPaymentEntry> FinEntryQueryWrapper = new QueryWrapper<>();
        FinEntryQueryWrapper.eq("mid",mid);
        FinEntryQueryWrapper.like("src_bill_type",srcBillType);
        List<FinPaymentEntry> finPaymentEntries = baseMapper.selectList(FinEntryQueryWrapper);
        if(finPaymentEntries!=null)
            return finPaymentEntries;
        return null;
    }

}


