package com.zeroone.star.psisysmanagement.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.vo.sysmanagement.usermanagement.DepartVO;
import com.zeroone.star.psisysmanagement.entity.Depart;
import com.zeroone.star.psisysmanagement.service.DepartService;
import com.zeroone.star.psisysmanagement.mapper.DepartMapper;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

/**
* @author dan
* @description 针对表【sys_depart(组织机构表)】的数据库操作Service实现
* @createDate 2023-02-22 22:18:42
*/
@Service
@Slf4j
public class DepartServiceImpl extends ServiceImpl<DepartMapper, Depart> implements DepartService{

    @Override
    public List<DepartVO> listDeparts() {
        QueryWrapper<Depart> queryWrapper = new QueryWrapper<>();
        queryWrapper.select("id", "depart_name");
        List<Depart> departs = baseMapper.selectList(queryWrapper);
        List<DepartVO> result = departs.stream().map(depart -> new DepartVO(depart.getId(), depart.getDepartName())).collect(Collectors.toList());
        log.info("result: {}", result);
        return result;
    }
}
