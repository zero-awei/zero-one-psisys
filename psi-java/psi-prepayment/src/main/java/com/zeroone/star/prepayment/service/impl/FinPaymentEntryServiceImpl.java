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
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.util.List;
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

    @Resource
    private FinPaymentMapper finPaymentMapper;
    /**
     * 修改采购预付单
     * 步骤：
     *  1、finPayment表   数据修改
     *  2、finPaymentEntry表 根据id删除所有相关数据
     *  3、finPaymentEntry表 插入数据列表
     *  4、判断是否成功，如果成功
     *  5、如果失败
     * param modifyDTO 修改DTO
     * return
     * author forever爱
     */
    @Override
    @Transactional
    public JsonVO<String> modifyById(ModifyDTO modifyDTO) {
        //1、finPayment表中数据修改
        FinPayment finPayment = new FinPayment();
        BeanUtil.copyProperties(modifyDTO, finPayment);
        int i = finPaymentMapper.updateById(finPayment);

        // 2、根据id删除所有相关数据
        QueryWrapper<FinPaymentEntry> queryWrapper = new QueryWrapper();
        queryWrapper.eq("mid", modifyDTO.getId());
        baseMapper.delete(queryWrapper);
        List<FinPaymentEntryDTO> entryDTOList = modifyDTO.getEntryDTOList();
        //2.1使用java8 stream流的特性，将List<FinPaymentEntryDTO>转化为List<FinPaymentEntry>
        List<FinPaymentEntry> finPaymentEntryList = entryDTOList.stream().map(
                dto -> {
                    FinPaymentEntry entity = new FinPaymentEntry();
                    BeanUtils.copyProperties(dto, entity);
                    return entity;
                }
        ).collect(Collectors.toList());
        boolean flag = saveBatch(finPaymentEntryList);
        //3、判断如果成功，返回“成功”
        if (flag){
            return JsonVO.success("修改成功");
        }
        //4、判断如果失败，返回“失败”
        return JsonVO.fail("修改失败");
    }

}
