package com.zeroone.star.systemmanagement.service.positionmanagement.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.systemmanagement.positionmanagement.PositionDTO;
import com.zeroone.star.project.query.systemmanagement.positionmanagement.PositionQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.positionmanagement.PositionVO;
import com.zeroone.star.systemmanagement.entity.positionmanagement.Position;
import com.zeroone.star.systemmanagement.mapper.positionmanagement.PositionMapper;
import com.zeroone.star.systemmanagement.service.positionmanagement.IPositionService;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

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

    @Override
    public PageVO<PositionVO> queryAll(PositionQuery positionQuery) {
        Page<Position> page = new Page<>(positionQuery.getPageIndex(),positionQuery.getPageSize());
        QueryWrapper<Position> wrapper = new QueryWrapper<>();
        Page<Position> result = positionMapper.selectPage(page,wrapper);
        return PageVO.create(result, PositionVO.class);
    }

    @Override
    public List<Position> listPosition() {
        return  baseMapper.selectList(null);
    }

    @Override
    public void insertOne(Position position) {
        baseMapper.insert(position);
    }
}
