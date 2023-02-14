package com.zeroone.star.role.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.query.role.MenuQuery;
import com.zeroone.star.role.entity.SysMenu;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public interface IMenuService extends IService<SysMenu> {
    List<MenuQuery> showList(int RId);

    Boolean addMenuOrJurisdiction(List<MenuQuery> listMenu) ;

    Boolean deleteMenuOrJurisdiction(int RId, int MId) ;
}
