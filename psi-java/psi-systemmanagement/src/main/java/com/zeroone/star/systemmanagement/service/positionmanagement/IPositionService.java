package com.zeroone.star.systemmanagement.service.positionmanagement;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.systemmanagement.positionmanagement.PositionDTO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.query.systemmanagement.positionmanagement.PositionQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.positionmanagement.PositionVO;
import com.zeroone.star.systemmanagement.entity.positionmanagement.Position;

import java.util.List;

/**
 * @Description
 * @Author mumu
 * @Data 2023-02-12 19:31
 */
public interface IPositionService extends IService<Position> {
    /**
     * 根据id删除职务
     *
     * @param positionId
     */
    String deletePositionById(String positionId);

    String update(PositionDTO positionDTO);

    String insert(PositionDTO positionDTO);

    PageVO<PositionVO> queryAll(PositionQuery positionQuery);

    List<Position> listPosition();

    void insertOne(Position position);

    List<String> listPostRank();
}
