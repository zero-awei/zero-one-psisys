package com.zeroone.star.project.payment;

import com.zeroone.star.project.vo.JsonVO;
import org.springframework.http.ResponseEntity;

/**
 * <p>
 * 描述：报表导出文件接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author binghujuelie
 * @version 1.0.0
 */

public interface PaymentExcelExportApis {

    // 获取数据 ： 根据id查询付款单，再根据付款单id查询付款单明细

    /**
     * 获取导出文件
     * @return 返回响应对象
     */
    ResponseEntity<byte[]> download();

    /**
     * 获取导出链接
     * @return 返回下载路径
     */
    JsonVO<String> downloadUrl();

}
