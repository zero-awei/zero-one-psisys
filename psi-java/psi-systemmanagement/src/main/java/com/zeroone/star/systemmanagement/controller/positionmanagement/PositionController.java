package com.zeroone.star.systemmanagement.controller.positionmanagement;

import com.zeroone.star.project.dto.systemmanagement.positionmanagement.PositionDTO;
import com.zeroone.star.project.query.systemmanagement.positionmanagement.PositionQuery;
import com.zeroone.star.project.systemmanagement.positionmanagement.PositionApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.positionmanagement.PositionVO;

/**
 * @Description
 * @Author j2 - mumu
 * @Data 2023-02-11 17:10
 */
public class PositionController implements PositionApis {
    @Override
    public JsonVO<PageVO<PositionVO>> listPositionByPageAndCondition(PositionQuery positionQuery) {
        return null;
    }

    @Override
    public JsonVO<String> savePosition(PositionDTO positionDTO) {
        return null;
    }

    @Override
    public JsonVO<String> updatePosition(PositionDTO positionDTO) {
        return null;
    }

    @Override
    public JsonVO<String> deletePosition(PositionDTO positionDTO) {
        return null;
    }
}
