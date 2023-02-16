package com.zeroone.star.project.accountPayable.otherPayableAPI;

import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.query.payable.FinPayableQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.accountPayable.otherPayable.OtherPayableVO;

import java.util.List;

/**
 * 描述：测试API接口定义
 *
 * @author: G.
 * @date: 2023/2/15 13:01
 */
public interface OtherPayableApis {
    /**
     * 其他应付界面根据查询条件分页查询
     * @param condition 查询条件
     * @return 查询结果
     */
    JsonVO<PageVO<OtherPayableVO>> queryAll(FinPayableQuery condition);


    /**
     * 点击‘其他应付’查询显示所有
     * @param condition 查询条件
     * @return 查询结果
     */
    JsonVO<PageVO<OtherPayableVO>> listAllFinPayable(PageQuery condition);

    /**
     * 通过单据编号查询数据
     * @param billNo 单据编号
     * @return 查询结果
     */
    JsonVO<OtherPayableVO> queryByBillNo(String billNo);
}
