package com.zeroone.star.prepayment.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.prepayment.entity.SysUser;
import com.zeroone.star.prepayment.mapper.SysUserMapper;
import com.zeroone.star.prepayment.service.ISysUserService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.vo.prepayment.SysUserVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 用户表 服务实现类
 * </p>
 *
 * @author Kong
 * @since 2023-02-17
 */
@Service
public class SysUserServiceImpl extends ServiceImpl<SysUserMapper, SysUser> implements ISysUserService {
    @Autowired
    SysUserMapper userMapper;

    @Override
    public List<SysUserVO> getSysUserList() {
        QueryWrapper queryWrapper = new QueryWrapper<>();
        List<SysUser> userList = userMapper.selectList(queryWrapper);

        ArrayList<SysUserVO> sysUserVOS = new ArrayList<>();
        for (SysUser user : userList){
            SysUserVO sysUserVO = new SysUserVO(user.getUsername(),user.getRealname(),user.getRealname(),user.getRealname());
            sysUserVOS.add(sysUserVO);
        }

        return sysUserVOS;
    }
}
