
import com.zeroone.star.prepayment.entity.PurOrder;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.query.prepayment.PurchaseListQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.prepayment.PurOrderVO;

import com.zeroone.star.project.query.prepayment.PurchaseListQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.prepayment.PurOrderVO;

/**
 * <p>
 * 采购订单 服务类
 * </p>
 *
 * @author zhd
 * @since 2023-02-18
 */
public interface IPurOrderService extends IService<PurOrder> {

    /**
     * 获取无申请采购单（分页）
     * @param condition 查询条件
     * @return 无申请采购单
     */
    public PageVO<PurOrderVO> getPurOrder(PurchaseListQuery condition);
}
