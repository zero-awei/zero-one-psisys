
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.query.prepayment.PurchaseListQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.prepayment.FinPaymentReqVO;
import com.zeroone.star.prepayment.entity.FinPaymentReq;
import com.zeroone.star.project.query.prepayment.PurchaseListQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.prepayment.FinPaymentReqVO;

/**
 * <p>
 * 付款申请单 服务类
 * </p>
 *
 * @author zhd
 * @since 2023-02-18
 */
public interface IFinPaymentReqService extends IService<FinPaymentReq> {

    /**
     * 获取有申请采购单（分页）
     * @param purchaseListQuery
     * @return
     */
    public PageVO<FinPaymentReqVO> getFinPaymentReq(PurchaseListQuery purchaseListQuery);

}
