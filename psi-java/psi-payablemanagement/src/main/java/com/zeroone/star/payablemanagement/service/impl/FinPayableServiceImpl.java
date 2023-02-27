package com.zeroone.star.payablemanagement.service.impl.Other;

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
        // 构建分页对象
        Page<FinPayable> finPayablePage = new Page<>(query.getPageIndex(), query.getPageSize());
        // 构建查询条件
        QueryWrapper<FinPayable> finPayableQueryWrapper = new QueryWrapper<>();
        // 1.单据编号查询
        finPayableQueryWrapper.eq(StringUtils.hasText(query.getBillNo()), "bill_no", query.getBillNo());
        // 2.单据日期查询
        if(query.getBillDateBegin() != null){
            // 条件为空时，报空指针异常，换为if判断
            //finPayableQueryWrapper.ge(StringUtils.hasText(query.getBillDate_begin().toString()),"bill_date", query.getBillDate_begin());
            //finPayableQueryWrapper.le(StringUtils.hasText(query.getBillDate_end().toString()),"bill_date", query.getBillDate_end());
            finPayableQueryWrapper.ge("bill_date", query.getBillDateBegin());
        }
        if(query.getBillDateEnd() != null){
            finPayableQueryWrapper.le("bill_date", query.getBillDateEnd());
        }
        // 3.单据主题查询
        finPayableQueryWrapper.eq(StringUtils.hasText(query.getSubject()), "subject", query.getSubject());
        // 4.供应商查询
        finPayableQueryWrapper.eq(StringUtils.hasText(query.getSupplierId()), "supplier_id", query.getSupplierId());
        // 5.单据阶段查询
        finPayableQueryWrapper.eq(StringUtils.hasText(query.getBillStage()), "bill_stage", query.getBillStage());
        // 6.已生效(与日期查询问题一样，换为if判断)
        if(query.getIsEffective() != null){
            finPayableQueryWrapper.eq("is_effective", query.getIsEffective());
        }
        // 7.已关闭
        if(query.getIsClosed() != null){
            finPayableQueryWrapper.eq("is_closed", query.getIsClosed());
        }
        // 8.已作废
        if(query.getIsVoided() != null){
            finPayableQueryWrapper.eq("is_voided", query.getIsVoided());
        }
        // 执行分页查询
        Page<FinPayable> result = baseMapper.selectPage(finPayablePage, finPayableQueryWrapper);
        return PageVO.create(result,PayableVO.class);
    }

    @Override
    public PayableVO getByBillNo(String billNo) {
        // 构建查询条件
        QueryWrapper<FinPayable> wrapper = new QueryWrapper<>();
        wrapper.eq("bill_no", billNo);
        // 执行查询
        FinPayable f = baseMapper.selectOne(wrapper);
        // 返回结果
        if(f == null){
            return null;
        }
        PayableVO payableVO = new PayableVO();
        BeanUtil.copyProperties(f, payableVO);
        return payableVO;
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
        newPayable.setCreateTime(LocalDateTime.now());
        FinPayable finPayable = null;
        try {
            finPayable = TransformationUtils.convert(newPayable, FinPayable.class);
//            finPayable = TransformationUtils.transmissionCreateDTO(newPayable);
        } catch (IllegalAccessException e) {
            throw new RuntimeException(e);
        }
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
        //如果没有该条数据则无法删除
        if(finPayableDB==null){
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
