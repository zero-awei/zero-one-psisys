package com.zeroone.star.project.homepage;

import com.zeroone.star.project.query.homepage.HomeDoingBillQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.homepage.HomeDoingBillVO;

import java.util.List;

/**
 * @author Third uncle
 * @date 2023/2/11 - 22:47
 */
public interface HomeDoingBillApis {

    /**
     * 查询处理中单据
     * @return
     */
    JsonVO<PageVO<HomeDoingBillVO>> queryAll(HomeDoingBillQuery condition);

    JsonVO<List<HomeDoingBillVO>> queryAll2();
}
