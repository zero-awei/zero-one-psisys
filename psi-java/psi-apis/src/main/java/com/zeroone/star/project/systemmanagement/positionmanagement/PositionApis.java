package com.zeroone.star.project.systemmanagement.positionmanagement;

import com.zeroone.star.project.dto.systemmanagement.positionmanagement.PositionDTO;
import com.zeroone.star.project.query.systemmanagement.positionmanagement.PositionQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.positionmanagement.PositionVO;
import io.swagger.annotations.ApiOperation;

/**
 * @Description position apis
 * @Author j2 - mumu
 * @Data 2023-02-11 16:43
 */
public interface PositionApis {
    /**
     * 根据查询条件和页数 获取职务信息
     * @param positionQuery, 包含分页信息和查询职务的3个查询条件
     * @return position message
     */
    JsonVO<PageVO<PositionVO>> listPositionByPageAndCondition(PositionQuery positionQuery);

    /**
     * 添加职务信息
     * @param positionDTO 根据DTO添加职务
     * @return 结果的字符串
     */
    JsonVO<String> savePosition(PositionDTO positionDTO);

    /**
     * 修改指定职务信息
     * @param positionDTO 根据DTO修改职务
     * @return 结果的字符串
     */
    JsonVO<String> updatePosition(PositionDTO positionDTO);

    /**
     * 删除指定职务信息
     * @param positionId 根据DTO删除职务
     * @return 结果的字符串
     */
    JsonVO<String> deletePosition(String positionId);

    // TODO: 2023/2/11 导入功能

    // TODO: 2023/2/11 导出功能

}
