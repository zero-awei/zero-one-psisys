package com.zeroone.star.prepayment.service.impl;

import cn.hutool.core.util.IdUtil;
import com.alibaba.excel.EasyExcel;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.prepayment.entity.FinPayment;
import com.zeroone.star.prepayment.mapper.FinPaymentMapper;
import com.zeroone.star.prepayment.service.IFinPaymentService;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.utils.easyExcel.EasyExcelUtils;
import org.springframework.stereotype.Service;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.List;
import java.util.function.Consumer;

/**
 * @ClassName FinPaymentServiceImpl
 * @Description IFinPaymentService服务类的实现
 * @Author HZP
 * @Date 2023/2/18 21:48
 * @Version 1.0
 **/
@Service
public class FinPaymentServiceImpl extends ServiceImpl<FinPaymentMapper, FinPayment> implements IFinPaymentService {
    @Override
    public FinPayment getByBillNo(String billNo) {
        QueryWrapper<FinPayment> FinQueryWrapper = new QueryWrapper<>();
        FinQueryWrapper.eq("bill_no", billNo);
        FinPayment finPayment = baseMapper.selectOne(FinQueryWrapper);
        return finPayment;
    }

    @Resource
    FinPaymentMapper paymentMapper;

    @Override
    public void importExcelOfPayment(MultipartFile file) throws Exception {
        EasyExcel.read(file.getInputStream(), FinPayment.class, EasyExcelUtils.getListener(this.process(), 2)).sheet().doRead();
    }

    // 用于获取当前登录的用户信息
    @Resource
    UserHolder userHolder;
    /**
     * 返回一个接口实现
     */
    public Consumer<List<FinPayment>> process() {
        return payments -> {
            for (FinPayment payment : payments) {
                payment.setId(IdUtil.getSnowflake().nextIdStr());
                payment.setCreateTime(LocalDateTime.now());
                try {
                    UserDTO currentUser = userHolder.getCurrentUser();
                    payment.setCreateBy(currentUser.getUsername());
                } catch (Exception e) {
                    throw new RuntimeException(e);
                }
            }
            paymentMapper.addBatch(payments);
        };
    }
}