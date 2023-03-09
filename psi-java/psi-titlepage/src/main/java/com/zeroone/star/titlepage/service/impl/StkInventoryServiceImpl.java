package com.zeroone.star.titlepage.service.impl;

import com.baomidou.mybatisplus.core.conditions.Wrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.vo.homepage.SystemRevenueAndExpenditureInformationVO;
import com.zeroone.star.titlepage.entity.StkInventory;
import com.zeroone.star.titlepage.mapper.StkInventoryMapper;
import com.zeroone.star.titlepage.service.IStkInventoryService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.math.BigDecimal;
import java.util.Map;

/**
 * <p>
 * 实时库存 服务实现类
 * </p>
 *
 * @author yx
 * @since 2023-02-11
 */
@Service
public class StkInventoryServiceImpl extends ServiceImpl<StkInventoryMapper, StkInventory> implements IStkInventoryService {

    @Autowired
    StkInventoryMapper mapper;

    /**
     * 获取即时库存(元)视图对象
     * @return 系统收支概况视图对象
     */
    @Override
    public SystemRevenueAndExpenditureInformationVO getInventoryVO() {
        QueryWrapper<StkInventory> wrapper = new QueryWrapper<>();
        wrapper.select("IFNULL(SUM(cost), 0) as `value`");
        Map<String, Object> map = getMap(wrapper);
        if(!(map.get("value") instanceof BigDecimal)){
            return null;
        }
        SystemRevenueAndExpenditureInformationVO informationVO = new SystemRevenueAndExpenditureInformationVO();
        informationVO.setLabel("即时库存(元)");
        informationVO.setValue((BigDecimal)map.get("value"));
        return informationVO;
    }
}
