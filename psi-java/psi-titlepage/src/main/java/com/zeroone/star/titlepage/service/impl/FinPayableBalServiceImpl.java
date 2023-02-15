package com.zeroone.star.titlepage.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.vo.homepage.SystemRevenueAndExpenditureInformationVO;
import com.zeroone.star.titlepage.entity.FinPayableBal;
import com.zeroone.star.titlepage.entity.FinReceivableBal;
import com.zeroone.star.titlepage.mapper.FinPayableBalMapper;
import com.zeroone.star.titlepage.service.IFinPayableBalService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.math.BigDecimal;
import java.util.Map;

/**
 * <p>
 * VIEW 服务实现类
 * </p>
 *
 * @author yx
 * @since 2023-02-11
 */
@Service
public class FinPayableBalServiceImpl extends ServiceImpl<FinPayableBalMapper, FinPayableBal> implements IFinPayableBalService {

    @Autowired
    FinPayableBalMapper mapper;

    /**
     * 获取欠供应商(元)的视图对象
     * @return 欠供应商(元)的视图对象
     */
    @Override
    public SystemRevenueAndExpenditureInformationVO getMyDebtVO() {
        QueryWrapper<FinPayableBal> wrapper = new QueryWrapper<>();
        wrapper.select("IFNULL(SUM(credit_bal), 0) as `value`");
        Map<String, Object> map = getMap(wrapper);
        if(!(map.get("value") instanceof BigDecimal)){
            return null;
        }
        SystemRevenueAndExpenditureInformationVO informationVO = new SystemRevenueAndExpenditureInformationVO();
        informationVO.setLabel("欠供应商(元)");
        informationVO.setValue((BigDecimal)map.get("value"));
        return informationVO;
    }
}
