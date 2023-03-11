package com.zeroone.star.project.sample;

import com.zeroone.star.project.query.sample.SampleQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.sample.SampleVO;

/**
 * <p>
 * 描述：测试API接口定义
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 阿伟学长
 * @version 1.0.0
 */
public interface SampleApis {
    /**
     * 测试分页查询
     * @param condition 查询条件
     * @return 查询结果
     */
    JsonVO<PageVO<SampleVO>> queryAll(SampleQuery condition);

    /**
     * 通过编号查询数据
     * @param id 编号
     * @return 查询结果
     */
    JsonVO<SampleVO> queryById(int id);
}
