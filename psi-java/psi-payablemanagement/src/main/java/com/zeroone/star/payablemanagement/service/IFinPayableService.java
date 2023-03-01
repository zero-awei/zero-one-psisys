package com.zeroone.star.payablemanagement.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.payablemanagement.entity.FinPayable;
import com.zeroone.star.project.dto.payablemanagement.DeleteDTO;
import com.zeroone.star.project.dto.payablemanagement.PayableDTO;
import com.zeroone.star.project.dto.payablemanagement.PayableStatusDTO;
import com.zeroone.star.project.query.payablemanagement.PayableBillNoQuery;
import com.zeroone.star.project.query.payablemanagement.PayableBySupplierQuery;
import com.zeroone.star.project.query.payablemanagement.PayableQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payablemanagement.PayableVO;
import org.springframework.validation.annotation.Validated;

/**
 * <p>
 * 应付单 服务类
 * </p>
 *
 * @author j3
 * @since 2023-02-14
 */
public interface IFinPayableService extends IService<FinPayable> {
    public PageVO<PayableVO> getAll(PayableQuery query);

    public PayableVO getByBillNO(@Validated PayableBillNoQuery query);
    /**
     * 根据条件分页查询
     * @param query 查询条件
     * @return 查询结果
     */
    PageVO<PayableVO> queryAll(PayableQuery query);

    /**
     * 根据单据编号查询
     * @param billNo 单据编号
     * @return 查询结果
     */
    PayableVO getByBillNo(String billNo);

    /**
     * 根据供应商ID查询
     * @param condition 供应商ID
     * @return 查血结果
     */
    public PageVO<PayableVO> queryPayableBySupplierId(PayableBySupplierQuery condition);

    /**
     * 新增其他应付单
     * @param newPayable 新增其他应付单DTO
     * @return 返回大于0的数或0，大于0代表添加成功，0代表添加失败
     */
    int addOtherPayable(PayableDTO newPayable);

    /**
     * 新增其他应付单
     * @param updatePayable 待更新其他应付单DTO
     * @return 返回大于0的数或0，大于0代表修改成功，0代表修改失败
     */
    int updateOtherPayable(PayableDTO updatePayable);


    /**
     * 删除其他应付单
     * @param delPayable 待删除其他应付单DTO
     * @return 返回大于0的数或0，大于0代表删除成功，0代表删除失败
     */
    int delOtherPayable(DeleteDTO delPayable);

    /**
     * 更新其他应付单状态
     * @param payableStatus 其他应付单状态DTO
     * @return 返回大于0的数或0，大于0代表更新状态成功，0代表更新状态失败
     */
    int updateOtherPayableStatus(PayableStatusDTO payableStatus);
}
