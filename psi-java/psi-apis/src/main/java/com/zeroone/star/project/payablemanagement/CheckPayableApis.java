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
import com.zeroone.star.project.vo.paymentmanagement.PaymentVO;
import org.springframework.web.multipart.MultipartFile;

import com.zeroone.star.project.dto.payablemanagement.CheckPayableDTO;

import java.util.List;

/**
 * @author spk, naturezh, the end
 * @description 应付核销接口
*/

public interface CheckPayableApis {

    /**
     * 在应付核销首页上查询
     * @param condition 查询条件
     */
    JsonVO<PageVO<CheckPayableVO>> queryAll(CheckPayableQuery condition);

    /**
     * 根据ID查询单据详情
     * @param condition 单据id
     * @return null
     */
    JsonVO<List<CheckPayableEntryVO>> getByMainId(CheckPayableEntryQuery condition);

    /**
     * 在新增界面上根据供应商ID查询应付单
     * @param condition 查询条件
     */
    JsonVO<PageVO<PayableVO>> listPayableBySupplier(PayableBySupplierQuery condition);

    /**
     * 在新增页面上根据供应商ID查询付款单
     * @param condition 查询条件
     */
    JsonVO<PageVO<PaymentVO>> listPaymentBySupplier(PaymentBySupplierQuery condition);

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
     *
     * @param dto    新增表单数据
     * @param action 判断保存或提交
     * @return 无数据返回
     */
    JsonVO<String> addPayableCheck(CheckPayableDTO dto, String action);

    /**
     * 修改应付核销单
     *
     * @param dto    新增表单数据
     * @param action 判断保存或提交
     * @return 无数据返回
     */
    JsonVO<String> modifyPayableCheck(CheckPayableDTO dto, String action);

    /**
     * 关闭应付核销单（批量）
     *
     * @param ids 单据id集合
     * @return 无数据返回
     */
    JsonVO<String> closePayableCheck(List<String> ids);

    /**
     * 反关闭应付核销单（批量）
     *
     * @param ids 单据id集合
     * @return 无数据返回
     */
    JsonVO<String> unclosePayableCheck(List<String> ids);

    /**
     * 删除应付核销单（批量）
     *
     * @param ids 单据id集合
     * @return 无数据返回
     */
    JsonVO<String> deletePayableCheck(List<String> ids);

    /**
     * 审核应付核销单
     *
     * @param id                 单据id
     * @param approvalResultType 核批结果
     * @param approvalRemark     核批意见
     * @return 无数据返回
     */
    JsonVO<String> checkPayableCheck(String id, String approvalResultType, String approvalRemark);

    /**
     * 作废应付核销单
     *
     * @param id 单据id
     * @return 无数据返回
     */
    JsonVO<String> voidPayableCheck(String id);

}
