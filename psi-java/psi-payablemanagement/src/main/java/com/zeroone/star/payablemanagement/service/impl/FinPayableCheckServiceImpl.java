package com.zeroone.star.payablemanagement.service.impl;

import com.alibaba.nacos.common.utils.StringUtils;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.payablemanagement.entity.FinPayableCheck;
import com.zeroone.star.payablemanagement.mapper.FinPayableCheckMapper;
import com.zeroone.star.payablemanagement.service.IFinPayableCheckService;
import com.zeroone.star.project.query.payablemanagement.CheckPayableQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payablemanagement.CheckPayableVO;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

/**
 * <p>
 * 应付核销单 服务实现类
 * </p>
 *
 * @author j3
 * @since 2023-02-14
 */
@Service
public class FinPayableCheckServiceImpl extends ServiceImpl<FinPayableCheckMapper, FinPayableCheck> implements IFinPayableCheckService {

    /**
     * @author spk
     * @description 参考G.的实现，基本上一模一样，IDEA都报Duplicated了...
     */
    @Override
    public PageVO<CheckPayableVO> queryAll(CheckPayableQuery query) {
        //TODO 缺少处理DictText

        // 构建分页对象
        Page<FinPayableCheck> page = new Page<>(query.getPageIndex(), query.getPageSize());
        // 构建查询条件
        QueryWrapper<FinPayableCheck> wrapper = new QueryWrapper<>();
        // 构建Wrapper
        //1. 单据编号
        wrapper.eq(StringUtils.hasText(query.getBillNo()), "bill_no", query.getBillNo());
        //2. 单据的起始日期和终止日期
        if(query.getBillDateBegin() != null) {
            wrapper.ge("bill_date", query.getBillDateBegin());
        }
        if(query.getBillDateEnd() != null) {
            wrapper.le("bill_date", query.getBillDateEnd());
        }
        //3. 单据主题
        wrapper.eq(StringUtils.hasText(query.getSubject()), "subject", query.getSubject());
        //4. 供应商
        wrapper.eq(StringUtils.hasText((query.getSupplierId())), "supplier_id", query.getSupplierId());
        //5. 单据阶段
        wrapper.eq(StringUtils.hasText(query.getBillStage()), "bill_stage", query.getBillStage());
        //6. 已生效
        if(query.getIsEffective() != null) {
            wrapper.eq("is_effective", query.getIsEffective());
        }
        //7. 已关闭
        if(query.getIsClosed() != null) {
            wrapper.eq("is_closed", query.getIsClosed());
        }
        //8. 已作废
        if(query.getIsVoided() != null) {
            wrapper.eq("is_voided", query.getIsVoided());
        }
        //执行分页查询
        Page<FinPayableCheck> result = baseMapper.selectPage(page, wrapper);

        return createPageVO(result);
    }

    //将查询得到的单条数据逐个转换为VO
    private static CheckPayableVO checkPayableEntityToVO(FinPayableCheck entity) {
        CheckPayableVO vo = new CheckPayableVO();
        vo.setId(entity.getId());
        vo.setAmt(entity.getAmt());
        vo.setApprovalRemark(entity.getApprovalRemark());
        // TODO 把具体的值变为DictText
        vo.setApprovalResultTypeDictText(entity.getApprovalResultType());
        // TODO
        vo.setApproverDictText(entity.getApprover());
        vo.setAttachment(entity.getAttachment());
        vo.setBillDate(entity.getBillDate());
        vo.setBillNo(entity.getBillNo());
        // TODO
        vo.setBillStageDictText(entity.getBillStage());
//        vo.setBillType
        // TODO
        vo.setCreateByDictText(entity.getCreateBy());
        vo.setCreateTime(entity.getCreateTime());
        vo.setEffectiveTime(entity.getEffectiveTime());
        vo.setIsAutoDictText(entity.getIsAuto() == 1 ? "是" : "否");
        vo.setIsClosedDictText(entity.getIsClosed() == 1 ? "是" : "否");
        //Boolean转换为Integer，再转换为String，>=是为了避免报错
        vo.setIsEffectiveDictText(entity.getIsEffective().compareTo(false) >= 1 ? "是" : "否");
        vo.setIsRubricDictText(entity.getIsRubric() == 1? "是" : "否");
        vo.setIsVoidedDictText(entity.getIsVoided().compareTo(false) >= 1? "是" : "否");
        // TODO
        vo.setPayableCheckTypeDictText(entity.getPayableCheckType());
        vo.setRemark(entity.getRemark());
        // TODO
        vo.setSrcBillTypeDictText(entity.getSrcBillType());
        vo.setSrcNo(entity.getSrcNo());
        vo.setSubject(entity.getSubject());
        // TODO
        vo.setSupplierIdDictText(entity.getSupplierId());
        // TODO
        vo.setSysOrgCodeDictText(entity.getSysOrgCode());
        // TODO
        vo.setUpdateByDictText(entity.getUpdateBy());
        vo.setUpdateTime(entity.getUpdateTime());

        return vo;
    }

    //将具体的数据
    public static PageVO<CheckPayableVO> createPageVO(Page<FinPayableCheck> page) {
        PageVO<CheckPayableVO> pageResult = new PageVO<>();
        pageResult.setTotal(page.getTotal());
        pageResult.setPageIndex(page.getCurrent());
        pageResult.setPageSize(page.getSize());
        pageResult.setPages(page.getPages());
        //转换数据
        List<FinPayableCheck> records = page.getRecords();
        if (records != null && !records.isEmpty()) {
            List<CheckPayableVO> rows = page.getRecords().stream().map(finPayableCheck -> {
                CheckPayableVO checkPayableVO = new CheckPayableVO();
                checkPayableVO = checkPayableEntityToVO(finPayableCheck);
                return checkPayableVO;
            }).collect(Collectors.toList());
            pageResult.setRows(rows);
        }
        return pageResult;
    }
}
