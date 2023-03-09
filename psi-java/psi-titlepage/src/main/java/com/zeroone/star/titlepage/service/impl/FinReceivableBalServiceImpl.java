package com.zeroone.star.titlepage.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.vo.homepage.SystemRevenueAndExpenditureInformationVO;
import com.zeroone.star.titlepage.entity.FinReceivableBal;
import com.zeroone.star.titlepage.entity.StkInventory;
import com.zeroone.star.titlepage.mapper.FinReceivableBalMapper;
import com.zeroone.star.titlepage.service.IFinReceivableBalService;
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
public class FinReceivableBalServiceImpl extends ServiceImpl<FinReceivableBalMapper, FinReceivableBal> implements IFinReceivableBalService {

    @Autowired
    FinReceivableBalMapper mapper;

    /**
     * 获取客户欠款(元)的视图对象
     * @return 系统收支概况视图对象
     */
    @Override
    public SystemRevenueAndExpenditureInformationVO getCustomerDebtVO() {
        QueryWrapper<FinReceivableBal> wrapper = new QueryWrapper<>();
        wrapper.select("IFNULL(SUM(debit_bal), 0) as `value`");
        Map<String, Object> map = getMap(wrapper);
        if(!(map.get("value") instanceof BigDecimal)){
            return null;
        }
        SystemRevenueAndExpenditureInformationVO informationVO = new SystemRevenueAndExpenditureInformationVO();
        informationVO.setLabel("客户欠款(元)");
        informationVO.setValue((BigDecimal)map.get("value"));
        return informationVO;
    }
}
