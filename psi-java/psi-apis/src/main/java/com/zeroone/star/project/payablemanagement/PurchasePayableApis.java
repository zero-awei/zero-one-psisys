package com.zeroone.star.project.payablemanagement;

import com.zeroone.star.project.query.payablemanagement.PayableQuery;
import com.zeroone.star.project.query.payablemanagement.PayableBillNoQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payablemanagement.PayableVO;

/**
 * <p>
 * 应付单 服务类 采购应付模块接口定义
 * </p>
 * 
 * @author chosen1, naturezh
 * @since 2023-02-13
 */
public interface PurchasePayableApis {
    /**
     * 分页查询
     * @return 查询结果
     */
    JsonVO<PageVO<PayableVO>> getAll(PayableQuery query);

    /**
     * 根据ID查询
     * @param query 编号
     * @return 查询结果
     */
    JsonVO<PayableVO> getById(PayableBillNoQuery query);

    /**
     * 文件导出
     * return 返回下载路径
     * author naturezh
     */
    JsonVO<String> fileExport();

}
