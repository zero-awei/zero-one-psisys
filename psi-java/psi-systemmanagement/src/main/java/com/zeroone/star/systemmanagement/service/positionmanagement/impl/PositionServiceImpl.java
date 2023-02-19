package com.zeroone.star.systemmanagement.service.positionmanagement.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.systemmanagement.entity.positionmanagement.Position;
import com.zeroone.star.systemmanagement.mapper.positionmanagement.PositionMapper;
import com.zeroone.star.systemmanagement.service.positionmanagement.IPositionService;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 * @Description
 * @Author mumu
 * @Data 2023-02-12 19:47
 */
@Service
public class PositionServiceImpl extends ServiceImpl<PositionMapper, Position> implements IPositionService {
    @Resource
    private PositionMapper positionMapper;

    @Override
    public String deletePositionById(String positionId) {
        int result = positionMapper.deleteById(positionId);
        if(result == 1){
            return "删除成功";
        }
        return "删除失败";
    }
}
