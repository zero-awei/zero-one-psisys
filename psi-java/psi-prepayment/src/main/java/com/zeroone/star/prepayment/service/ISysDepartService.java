package com.zeroone.star.prepayment.service;

import com.zeroone.star.prepayment.entity.SysDepart;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.vo.prepayment.SysDepartVO;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * <p>
 * 组织机构表 服务类
 * </p>
 *
 * @author Kong
 * @since 2023-02-17
 */
public interface ISysDepartService extends IService<SysDepart> {

    /**
     * 获取部门显示对象
     * @return SysDepart 部门显示对象
     * @author 空
     */
    public List<SysDepartVO> getDeparts();
}
