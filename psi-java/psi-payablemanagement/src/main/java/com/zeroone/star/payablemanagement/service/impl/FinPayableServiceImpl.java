package com.zeroone.star.payablemanagement.service.impl;
import cn.hutool.core.bean.BeanUtil;
import com.zeroone.star.project.query.payablemanagement.PayableBySupplierQuery;
import org.springframework.context.annotation.Bean;
import com.zeroone.star.project.query.payablemanagement.PayableBillNoQuery;
import com.alibaba.nacos.common.utils.StringUtils;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.payablemanagement.entity.FinPayable;
import com.zeroone.star.payablemanagement.mapper.FinPayableMapper;
import com.zeroone.star.payablemanagement.service.IFinPayableService;
import com.zeroone.star.payablemanagement.utils.SnowFlakeShortUrl;
import com.zeroone.star.payablemanagement.utils.TransformationUtils;
import com.zeroone.star.project.dto.payablemanagement.DeleteDTO;
import com.zeroone.star.project.dto.payablemanagement.PayableDTO;
import com.zeroone.star.project.dto.payablemanagement.PayableStatusDTO;
import com.zeroone.star.project.query.payablemanagement.PayableBillNoQuery;
import com.zeroone.star.project.query.payablemanagement.PayableQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payablemanagement.PayableVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;
import java.util.stream.Collectors;

import javax.annotation.Resource;
import java.util.List;

import java.time.LocalDateTime;

/**
 * <p>
 * 应付单 服务实现类
 * </p>
 *
 * @author chosen1, G.
 * @since 2023-02-14
 */
@Service
public class FinPayableServiceImpl extends ServiceImpl<FinPayableMapper, FinPayable> implements IFinPayableService {
    @Autowired
    FinPayableMapper mapper;
    SnowFlakeShortUrl snowFlake = new SnowFlakeShortUrl(5, 3);



    @Override
    public PageVO<PayableVO> getAll(PayableQuery query) {
        List<PayableVO> list = mapper.getAllPayable(query);
        if (list.isEmpty()) {
            return null;
        }
        return new PageVO<>(query.getPageIndex(), query.getPageSize(), (long) list.size(), (long) 100, list);
    }

    @Override
    public PayableVO getByBillNO(PayableBillNoQuery query) {
        return mapper.getByBillNo(query.getBillNO());
    }


    public PageVO<PayableVO> queryAll(PayableQuery query) {
        List<PayableVO> list = mapper.queryPayable(query);
        if (list.isEmpty()) {
            return null;
        }
        return new PageVO<>(query.getPageIndex(), query.getPageSize(), (long) list.size(), (long) 100, list);
    }

    @Override
    public PayableVO getByBillNo(String billNo) {
        return mapper.getOneByBillNo(billNo);
    }

    @Override
    public PageVO<PayableVO> queryPayableBySupplierId(PayableBySupplierQuery query) {

        List<PayableVO> list = mapper.getBySupplierId(query);
        if(list.isEmpty()) {
            return null;
        }
        return new PageVO<>(query.getPageIndex(), query.getPageSize(), (long) list.size(), (long) 100, list);
    }


    @Override
    public int addOtherPayable(PayableDTO newPayable) {
        if (newPayable==null){
            return 0;
        }
        //将PayableDTO转换为finPayable实体类
//        FinPayable finPayable = TransformationUtils.toAllDto(newPayable,FinPayable.class);

        //使用雪花算法生成id
        newPayable.setId(snowFlake.nextId()+"");
        //获取创建时间
        newPayable.setCreateTime(LocalDateTime.now());
        newPayable.setEffectiveTime(LocalDateTime.now());
        //设置应付类型
        newPayable.setPayableType("201");
        FinPayable finPayable = null;
        try {
            finPayable = TransformationUtils.convert(newPayable, FinPayable.class);
//            finPayable = TransformationUtils.transmissionCreateDTO(newPayable);
        } catch (IllegalAccessException e) {
            throw new RuntimeException(e);
        }
        finPayable.setIsAuto(1);
        finPayable.setIsRubric(0);
        finPayable.setIsClosed(0);
        finPayable.setIsVoided(0);
        finPayable.setIsEffective(1);
        return mapper.insert(finPayable);
    }

    @Override
    public int updateOtherPayable(PayableDTO updatePayable) {
        //传入updatePayable转换而成的实体类
        FinPayable finPayableIN = null;
        //传入值为空无法更新
        if(updatePayable==null){
            return 0;
        }


        //将PayableDTO转换为finPayable实体类
        finPayableIN = TransformationUtils.toAllDto(updatePayable,FinPayable.class);


        QueryWrapper<FinPayable> wrapper = new QueryWrapper<>();
        wrapper.eq("bill_no", updatePayable.getBillNo());

        //与传入updatePayable相同BillNo的数据库中的实体类
        FinPayable finPayableDB = baseMapper.selectOne(wrapper);
        //如果单据已作废，或者已关闭，或者没有该条数据则无法更新
        if(finPayableDB==null||finPayableDB.getIsVoided()==1||finPayableDB.getIsClosed()==1){
            return 0;
        }
        finPayableIN.setUpdateTime(LocalDateTime.now());
        finPayableIN.setId(finPayableDB.getId());
        return mapper.updateById(finPayableIN);
    }

    @Override
    public int delOtherPayable(DeleteDTO delPayable) {
//        FinPayable finPayableIN = null;
        if(delPayable==null){
            return 0;
        }
//        finPayableIN = TransformationUtils.toAllDto(delPayable,FinPayable.class);

        QueryWrapper<FinPayable> wrapper = new QueryWrapper<>();
        wrapper.eq("bill_no", delPayable.getBillNo());

        //与传入delPayable相同BillNo的数据库中的实体类
        FinPayable finPayableDB = baseMapper.selectOne(wrapper);
        //如果没有该条数据,或者处理状态不为“编制中”则无法删除
        if(finPayableDB==null||!finPayableDB.getBillStage().equals("1")){
            return 0;
        }
        return mapper.deleteById(finPayableDB);
    }

    @Override
    public int updateOtherPayableStatus(PayableStatusDTO payableStatus) {
        //传入payableStatus转换而成的实体类
        FinPayable finPayableIN = null;
        //传入值为空无法更新状态
        if(payableStatus==null){
            return 0;
        }
        finPayableIN = TransformationUtils.toAllDto(payableStatus,FinPayable.class);

        QueryWrapper<FinPayable> wrapper = new QueryWrapper<>();
        wrapper.eq("bill_no", payableStatus.getBillNo());

        //与传入payableStatus相同BillNo的数据库中的实体类
        FinPayable finPayableDB = baseMapper.selectOne(wrapper);
        //如果单据已作废，或者没有该条数据则无法更新
        if(finPayableDB==null||finPayableDB.getIsVoided()==1){
            return 0;
        }

        finPayableIN.setId(finPayableDB.getId());
        return mapper.updateById(finPayableIN);
    }
}
