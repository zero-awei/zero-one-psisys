package com.zeroone.star.prepayment.service.impl;
import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.prepayment.entity.FinPayment;
import com.zeroone.star.prepayment.entity.FinPaymentEntry;
import com.zeroone.star.prepayment.mapper.FinPaymentEntryMapper;
import com.zeroone.star.prepayment.mapper.FinPaymentMapper;
import com.zeroone.star.prepayment.service.IFinPaymentEntryService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.prepayment.FinPaymentEntryDTO;
import com.zeroone.star.project.dto.prepayment.ModifyDTO;
import com.zeroone.star.project.dto.prepayment.PrepaymentDTO;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
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
     * 修改付款单明细
     * author forever爱
     */
    @Override
    public boolean updateById(ModifyDTO modifyDTO) {
        QueryWrapper<FinPaymentEntry> queryWrapper = new QueryWrapper();
        queryWrapper.eq("mid", modifyDTO.getId());
        baseMapper.delete(queryWrapper);
        List<FinPaymentEntryDTO> entryDTOList = modifyDTO.getEntryDTOList();
        //使用java8 stream流的特性，将List<FinPaymentEntryDTO>转化为List<FinPaymentEntry>
        List<FinPaymentEntry> finPaymentEntryList = entryDTOList.stream().map(
                dto -> {
                    //生成19位id
                    long timestamp = System.currentTimeMillis(); // 毫秒级时间戳
                    int randNum = new Random().nextInt(1000000000); // 生成9位随机数
                    String uniqueId = timestamp + String.format("%09d", randNum); // 将时间戳和随机数拼接起来
                    String id = uniqueId.substring(0, 19);// 截取前19位作为最终的唯一ID
                    FinPaymentEntry entity = new FinPaymentEntry();
                    entity.setId(id);
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
        //获取主表id
        String id1 = prepaymentDTO.getId();
        int res = 0;
        for (FinPaymentEntryDTO finPaymentEntryDTO:prepaymentDTO.getFinPaymentEntryList()){
            //生成明细表id
            long timestamp2 = System.currentTimeMillis(); // 毫秒级时间戳
            int randNum2 = new Random().nextInt(1000000000); // 生成9位随机数
            String uniqueId2 = timestamp2 + String.format("%09d", randNum2); // 将时间戳和随机数拼接起来
            String id2 = uniqueId2.substring(0, 19);// 截取前19位作为最终的唯一ID
            FinPaymentEntry finPaymentEntry = new FinPaymentEntry();
            BeanUtils.copyProperties(finPaymentEntryDTO,finPaymentEntry);
            finPaymentEntry.setId(id2);
            finPaymentEntry.setMid(id1);//将主表id放入mid
            finPaymentEntry.setBillNo(prepaymentDTO.getBillNo());//获取单号
            res = baseMapper.insert(finPaymentEntry);
        }
        return res;
    }

}
