package com.zeroone.star.systemmanagement.service.positionmanagement.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.systemmanagement.positionmanagement.PositionDTO;
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
        if(result == 0){
            return "删除失败";
        }
        return "删除成功";
    }

    @Override
    public String update(PositionDTO positionDTO) {
        Position position = new Position();
        BeanUtil.copyProperties(positionDTO,position);
        int result =positionMapper.updateById(position);
        if(result == 0){
            return "更新失败";
        }
        return "更新成功";
    }

    @Override
    public String insert(PositionDTO positionDTO) {
        Position position = new Position();
        BeanUtil.copyProperties(positionDTO,position);
        int result =positionMapper.insert(position);
        if(result == 0){
            return "添加失败";
        }
        return "添加成功";
    }
}
