package com.zeroone.star.project.payablemanagement;

import com.zeroone.star.project.dto.payablemanagement.CheckPayableDTO;
import com.zeroone.star.project.query.payablemanagement.CheckPayableEntryQuery;
import com.zeroone.star.project.query.payablemanagement.CheckPayableQuery;
import com.zeroone.star.project.query.payablemanagement.PayableBySupplierQuery;
import com.zeroone.star.project.query.payablemanagement.PaymentBySupplierQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payablemanagement.CheckPayableEntryVO;
import com.zeroone.star.project.vo.payablemanagement.CheckPayableVO;
import com.zeroone.star.project.vo.payablemanagement.PayableVO;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;
/**
 * @author spk, naturezh, the end
 * @description 应付核销接口
*/

public interface CheckPayableApis {

    /**
     * 在应付核销首页上查询
     * @return null
     * @param condition 查询条件
     */
    JsonVO<PageVO<CheckPayableVO>> listFinPayableCheck(CheckPayableQuery condition);

    /**
     * 根据ID查询单据详情
     * @param condition 单据id
     * @return null
     */
    JsonVO<PageVO<CheckPayableEntryVO>> getById(CheckPayableEntryQuery condition);

    /**
     * 在新增界面上根据供应商ID查询应付单
     * @return null
     * @param condition 查询条件
     */
    JsonVO<PageVO<PayableVO>> listFinPayableBySupplier(PayableBySupplierQuery condition);

    /**
     * 在新增页面上根据供应商ID查询付款单
     * @return null
     * @param condition 查询条件
     */
    JsonVO<PageVO<PayableVO>> listFinPaymentBySupplier(PaymentBySupplierQuery condition);

    /**
    * 文件导出
    * return 返回下载路径
    * author naturezh
    */
    JsonVO<String> fileExport();

    /**
     * 文件导入
     * return 返回状态
     * author naturezh
     */
    JsonVO<String> fileImport(MultipartFile file);

    /**
    * 新增应付核销单
    */
    JsonVO<Void> addPayableCheck(CheckPayableDTO dto);

    /**
     * 修改应付核销单
     */
    JsonVO<Void> modifyPayableCheck(CheckPayableDTO dto);

    /**
     * 关闭应付核销单（批量）
     */
    JsonVO<Void> closePayableCheck(List<String> ids);

    /**
     * 反关闭应付核销单（批量）
     */
    JsonVO<Void> unclosePayableCheck(List<String> ids);

    /**
     * 删除应付核销单（批量）
     */
    JsonVO<Void> deletePayableCheck(List<String> ids);

    /**
     * 审核应付核销单
     */
    JsonVO<Void> checkPayableCheck(String id, String approvalResultType, String approvalRemark);

    /**
     * 作废应付核销单
     */
    JsonVO<Void> voidPayableCheck(String id);

}
