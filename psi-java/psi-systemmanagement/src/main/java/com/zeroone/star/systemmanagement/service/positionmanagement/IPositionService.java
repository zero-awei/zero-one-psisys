package com.zeroone.star.systemmanagement.service.positionmanagement;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.systemmanagement.positionmanagement.PositionDTO;
import com.zeroone.star.systemmanagement.entity.positionmanagement.Position;

/**
 * @Description
 * @Author mumu
 * @Data 2023-02-12 19:31
 */
public interface IPositionService extends IService<Position>{
    /**
     * 根据id删除职务
     * @param positionId
     */
    String deletePositionById(String positionId);

    String update(PositionDTO positionDTO);
}
