package com.zeroone.star.project.homepage;

import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.homepage.*;

import java.util.List;

/**
 * <p>
 * 描述：系统收支接收API接口定义
 * </p>
 * @author YinXing
 * @date 2023年02月11日
 */
public interface InventoryApis {

    /**
     * 通过编号查询系统收支概况
     * @return 查询出来的系统收支信息
     */
    JsonVO<List<SystemRevenueAndExpenditureInformationVO>> querySystemInfoById();
}
