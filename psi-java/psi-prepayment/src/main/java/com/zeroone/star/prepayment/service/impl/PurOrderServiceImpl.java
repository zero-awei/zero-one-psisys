package com.zeroone.star.prepayment.service.impl;
import com.zeroone.star.prepayment.entity.PurOrder;
import com.zeroone.star.prepayment.mapper.PurOrderMapper;
import com.zeroone.star.prepayment.service.IPurOrderService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.query.prepayment.PurchaseListQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.prepayment.PurOrderVO;
import org.springframework.beans.factory.annotation.Autowired;
/**
 * <p>
 * 采购订单 服务实现类
 * </p>
 *
 * @author zhd
 * @since 2023-02-18
 */
@Service
public class PurOrderServiceImpl extends ServiceImpl<PurOrderMapper, PurOrder> implements IPurOrderService {
    @Autowired
    PurOrderMapper purOrderMapper;

    @Override
    public PageVO<PurOrderVO> getPurOrder(PurchaseListQuery condition) {
        Page<PurOrder> purOrderPage = new Page<>(condition.getPageIndex(), condition.getPageSize());
        QueryWrapper<PurOrder> wrapper = new QueryWrapper<>();
        wrapper.eq("supplier_id",condition.getSelf_supplier_id());
//        if (condition.getSelf_payment_type()!=null){
//            wrapper.eq("payment_type",condition.getSelf_payment_type());
//        }
        if (condition.getSelf_is_closed()!=null){
            wrapper.eq("is_closed",condition.getSelf_is_closed());
        }
        Page<PurOrder> purOrder= purOrderMapper.selectPage(purOrderPage, wrapper);
        return PageVO.create(purOrder,PurOrderVO.class);
    }
    /**
     * ClassName PurOrderServiceImpl
     * Description IPurOrderService服务类的实现
     * Author HZP
     **/
    @Override
    public PurOrder getBySrcBillId(String srcBillId) {
        QueryWrapper<PurOrder> PurOrderQueryWrapper = new QueryWrapper<>();
        PurOrderQueryWrapper.eq("id",srcBillId);
        PurOrder purOrder = baseMapper.selectOne(PurOrderQueryWrapper);
        if(purOrder!=null)
            return purOrder;
        return null;
    }
}
