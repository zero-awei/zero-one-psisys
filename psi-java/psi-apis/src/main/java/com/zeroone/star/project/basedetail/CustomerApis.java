package com.zeroone.star.project.basedetail;


import com.zeroone.star.project.vo.JsonVO;

/**
 * @author suqier
 */

public interface CustomerApis {

    /**
     * 导出客户信息
     * @return
     */
    JsonVO<String> download();


}
