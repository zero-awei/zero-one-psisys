package com.zeroone.star.project.payablemanagement;

import com.zeroone.star.project.query.payablemanagement.PayableQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.payablemanagement.PayableVO;
import org.springframework.web.multipart.MultipartFile;

/**
 * 描述：测试API接口定义
 *
 * @author: G., natureth
 * @date: 2023/2/15 13:01
 */
public interface OtherPayableApis {
    /**
     * 其他应付界面根据查询条件分页查询
     * @param condition 查询条件
     * @return 查询结果
     */
    JsonVO<PageVO<PayableVO>> queryAll(PayableQuery condition);

    /**
     * 通过单据编号查询数据
     * @param billNo 单据编号
     * @return 查询结果
     */
    JsonVO<PayableVO> queryByBillNo(String billNo);

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

}
