package com.zeroone.star.psisysmanagement.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.sysmanagement.menumanagement.MenuDTO;
import com.zeroone.star.project.query.sysmanagement.menumanagement.SingleMenuQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.sysmanagement.menumanagement.MenuVO;
import com.zeroone.star.psisysmanagement.entity.SysMenu;
import com.zeroone.star.psisysmanagement.mapper.SysMenuMapper;
import com.zeroone.star.psisysmanagement.service.ISysMenuService;
import org.springframework.stereotype.Service;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author 归、深夜梦想家 
 * @since 2023-02-14
 */
@Service
public class SysMenuServiceImpl extends ServiceImpl<SysMenuMapper, SysMenu> implements ISysMenuService {

    @Override
    public JsonVO<MenuVO> querySingle(SingleMenuQuery singleMenuQuery) {
        return null;
    }

    @Override
    public JsonVO<ResultStatus> addMenu(MenuDTO menuDTO) {
        return null;
    }

    @Override
    public JsonVO<ResultStatus> updateMenu(MenuDTO menuDTO) {
        return null;
    }

    @Override
    public JsonVO<ResultStatus> deleteMenu(SingleMenuQuery singleMenuQuery) {
        return null;
    }
}
