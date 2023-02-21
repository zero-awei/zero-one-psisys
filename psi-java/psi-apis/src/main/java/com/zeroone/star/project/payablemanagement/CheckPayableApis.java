package com.zeroone.star.project.payablemanagement;

import com.zeroone.star.project.dto.payablemanagement.CheckPayableDto;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * @author The end
 * @date 2023/2/15
 */
public interface CheckPayableApis {

    /**
     * 新增应付核销单
     */
    JsonVO<Void> addPayableCheck(CheckPayableDto dto);

    /**
     * 新增应付核销单
     */
    JsonVO<Void> modifyPayableCheck(CheckPayableDto dto);

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
