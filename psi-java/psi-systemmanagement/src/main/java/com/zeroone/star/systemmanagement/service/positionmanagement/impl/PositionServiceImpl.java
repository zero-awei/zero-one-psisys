package com.zeroone.star.systemmanagement.service.positionmanagement.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.systemmanagement.positionmanagement.PositionDTO;
import com.zeroone.star.project.query.systemmanagement.positionmanagement.PositionQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.positionmanagement.PositionVO;
import com.zeroone.star.systemmanagement.entity.positionmanagement.Position;
import com.zeroone.star.systemmanagement.mapper.positionmanagement.PositionMapper;
import com.zeroone.star.systemmanagement.service.positionmanagement.IPositionService;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * @Description
 * @Author mumu
 * @Data 2023-02-12 19:47
 */
@Service
public class PositionServiceImpl extends ServiceImpl<PositionMapper, Position> implements IPositionService {
    @Resource
    private PositionMapper positionMapper;

    @Resource
    private UserHolder userHolder;

    @Override
    public String deletePositionById(String positionId) {
        int result = positionMapper.deleteById(positionId);
        if (result == 0) {
            return "删除失败";
        }
        return "删除成功";
    }

    @Override
    public String update(PositionDTO positionDTO) {
        Position position = new Position();
        BeanUtil.copyProperties(positionDTO, position);
        //获取操作者信息
        try {
            UserDTO user = userHolder.getCurrentUser();
            position.setCreateBy(user.getUsername());
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        int result = positionMapper.updateById(position);
        if (result == 0) {
            return "更新失败";
        }
        return "更新成功";
    }

    @Override
    public String insert(PositionDTO positionDTO) {
        Position position = new Position();
        BeanUtil.copyProperties(positionDTO, position);
        try {
            UserDTO user = userHolder.getCurrentUser();
            position.setUpdateBy(user.getUsername());
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        int result = positionMapper.insert(position);
        if (result == 0) {
            return "添加失败";
        }
        return "添加成功";
    }

    @Override
    public PageVO<PositionVO> queryAll(PositionQuery positionQuery) {
        Page<Position> page = new Page<>(positionQuery.getPageIndex(), positionQuery.getPageSize());
        QueryWrapper<Position> wrapper = new QueryWrapper<>();
        Page<Position> result = positionMapper.selectPage(page, wrapper);
        return PageVO.create(result, PositionVO.class);
    }

    @Override
    public List<Position> listPosition() {
        return baseMapper.selectList(null);
    }

    @Override
    public void insertOne(Position position) {
        baseMapper.insert(position);
    }

    @Override
    public List<String> listPostRank() {
        LambdaQueryWrapper<Position> wrapper = new LambdaQueryWrapper<>();
        wrapper.select(Position::getPostRank);
        List<Position> position_onlyPostRank = positionMapper.selectList(wrapper);
        Set<String> postRanks = new HashSet<>();
        for (Position position : position_onlyPostRank) {
            if(position.getPostRank().equals("1")){
                postRanks.add("员级");
            }else if(position.getPostRank().equals("2")){
                postRanks.add("助级");
            }else if(position.getPostRank().equals("3")){
                postRanks.add("中级");
            }else if(position.getPostRank().equals("4")){
                postRanks.add("副高级");
            }else if(position.getPostRank().equals("5")){
                postRanks.add("正高级");
            }
        }
        return new ArrayList<>(postRanks);
    }
}
