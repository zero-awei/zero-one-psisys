package com.zeroone.star.prepayment.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.prepayment.entity.SysDepart;
import com.zeroone.star.prepayment.mapper.SysDepartMapper;
import com.zeroone.star.prepayment.service.ISysDepartService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.vo.prepayment.SysDepartVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 组织机构表 服务实现类
 * </p>
 *
 * @author Kong
 * @since 2023-02-17
 */
@Service
public class SysDepartServiceImpl extends ServiceImpl<SysDepartMapper, SysDepart> implements ISysDepartService {

    @Autowired
    SysDepartMapper sysDepartMapper;

    @Override
    public List<SysDepartVO> getDeparts() {
        //查询sys_depart表数据 获取所有部门对象
        QueryWrapper queryWrapper = new QueryWrapper<>();
        List<SysDepart> departList = sysDepartMapper.selectList(queryWrapper);

        //封装成vo
        ArrayList<SysDepartVO> departVOS = new ArrayList<>();
        for (SysDepart depart:departList){
            SysDepartVO sysDepartVO = new SysDepartVO(depart.getOrgCode(),depart.getDepartName(),depart.getDepartName(),depart.getDepartName());
            departVOS.add(sysDepartVO);
        }

        return departVOS;
    }
}
