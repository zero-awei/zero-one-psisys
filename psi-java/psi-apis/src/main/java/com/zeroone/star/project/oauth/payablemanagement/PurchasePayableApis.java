package com.zeroone.star.project.oauth.payablemanagement;

import com.zeroone.star.project.vo.JsonVO;

/**
 * <p>
 * 描述：采购应付模块接口定义
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author naturezh
 * @version 1.0.0
 */
public interface PurchasePayableApis {

    /**
     * 文件导出
     * return 返回下载路径
     * author naturezh
     */
    JsonVO<String> fileExport();

}
