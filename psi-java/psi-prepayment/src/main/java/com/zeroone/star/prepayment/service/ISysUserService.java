package com.zeroone.star.prepayment.service;

import com.zeroone.star.prepayment.entity.SysUser;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.vo.prepayment.SysUserVO;

import java.util.List;

/**
 * <p>
 * 用户表 服务类
 * </p>
 *
 * @author Kong
 * @since 2023-02-17
 */
public interface ISysUserService extends IService<SysUser> {

    /**
     * 获取用户列表 （用户名、真实姓名）
     * @return SysUserVO 用户显示对象
     * @author Kong
     */
    public List<SysUserVO> getSysUserList();

}
