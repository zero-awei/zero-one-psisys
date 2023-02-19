package com.zeroone.star.psisysmanagement.service.impl;

import cn.hutool.core.bean.BeanUtil;
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
import org.springframework.transaction.annotation.Transactional;

import java.time.LocalDateTime;

/**
 * <p>
 * 服务实现类
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
    @Transactional
    public JsonVO<ResultStatus> addMenu(MenuDTO menuDTO) {

        SysMenu sysMenu = BeanUtil.copyProperties(menuDTO, SysMenu.class);
        sysMenu.setCreateTime(LocalDateTime.now());

        Double sort = query().eq("id", menuDTO.getParentMenuId()).one().getSortNo();

        int index = (String.valueOf(sort)).indexOf(".") + 1;//获取小数点的位置
        int count = (String.valueOf(sort)).length() - index;//获取小数点后的个数
        int temp = 1;
        if (count == 1) {
            temp = temp * 10;
        } else if (count == 2) {
            temp = temp * 100;
        } else {
            temp = temp * 1000;
        }
        //获取下一个父节点sort_no
        double d = sort + (double) 1 / temp;
        //查询该父节点当中子节点个数
        Long con = query().gt("sort_no", sort).lt("sort_no", d).count();
        sysMenu.setSortNo(sort + (double) (con + 1) / (temp * 10));

        return save(sysMenu) ? JsonVO.success(ResultStatus.SUCCESS) : JsonVO.fail(ResultStatus.FAIL);

    }

    @Transactional
    @Override
    public JsonVO<ResultStatus> updateMenu(MenuDTO menuDTO) {
        boolean result = update().eq("id", menuDTO.getId())
                .set("parent_id", menuDTO.getParentMenuId())
                .set("name", menuDTO.getName())
                .set("url", menuDTO.getPath())
                .set("icon", menuDTO.getIcon())
                .set("update_time", LocalDateTime.now()).update();

        return result ? JsonVO.success(ResultStatus.SUCCESS) : JsonVO.fail(ResultStatus.FAIL);
    }

    @Override
    public JsonVO<ResultStatus> deleteMenu(SingleMenuQuery singleMenuQuery) {

        SysMenu sysMenu = BeanUtil.copyProperties(singleMenuQuery, SysMenu.class);

        int num = baseMapper.deleteById(sysMenu);

        return num >=1 ? JsonVO.success(ResultStatus.SUCCESS) : JsonVO.fail(ResultStatus.FAIL);
    }
}
