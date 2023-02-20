package com.zeroone.star.psisysmanagement.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.extension.conditions.query.QueryChainWrapper;
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
        SysMenu sysMenu = baseMapper.selectById(singleMenuQuery.getId());
        MenuVO menuVO = BeanUtil.copyProperties(sysMenu, MenuVO.class);

        return menuVO == null ?
                JsonVO.create(null, ResultStatus.FAIL) : JsonVO.create(menuVO, ResultStatus.SUCCESS);
    }

    @Override
    @Transactional
    public JsonVO<ResultStatus> addMenu(MenuDTO menuDTO) {

        SysMenu sysMenu = BeanUtil.copyProperties(menuDTO, SysMenu.class);
        sysMenu.setCreateTime(LocalDateTime.now());

        //获取父节点id
        String parentId = menuDTO.getParentId();
        if (parentId.isEmpty()) {

            double sort = 1.00;
            //没有父节点时
            while (true) {
                //查询表中是否已有与sort等值的sort_no
                QueryChainWrapper<SysMenu> menuEntity = query().eq("sort_no", sort);
                if (menuEntity.isEmptyOfEntity()) {
                    //如果没有就将sort值赋给新的menu的sort_no
                    sysMenu.setSortNo(sort);
                    break;
                }
                sort += 1.00;
            }

        } else {

            //有父节点时，获取父节点的sort_no
            double parentSort = query().eq("id", parentId).one().getSortNo();
            //将sort转换为字符串并去除小数点
            String sortString = Double.toString(parentSort).replace(".", "");
            //准备int数组sortArray
            int[] sortArray = new int[sortString.length()];
            //将sortString每个数字传入数组
            for (int i = 0; i < sortArray.length; i++) {
                sortArray[i] = sortString.charAt(i) - '0';
            }

            if (sortArray[1] == 0) {

                //当父节点的Sort_no小数点后一位为0时，说明父节点为一级菜单，小数点第二位也必定为0，如1.00
                double sort = parentSort + 0.10;
                while (true) {
                    //尝试查询数据库中是否含有sort等值的sort_no
                    QueryChainWrapper<SysMenu> menuEntity = query().eq("sort_no", sort);
                    if (menuEntity.isEmptyOfEntity()) {
                        //如果没有就将sort值赋给新的menu的sort_no
                        sysMenu.setSortNo(sort);
                        break;
                    }
                    sort += 0.10;
                }
            } else {

                //如果小数点后第一位不为0，即父节点为二级菜单，如1.10；
                //由于限制只能创建到三级菜单，所以父节点只有三种情况，为空，一级菜单，二级菜单
                //故父节点sort_no小数点后第二位没有判断的必要
                double sort = parentSort + 0.01;
                while (true) {
                    //尝试查询数据库中是否含有sort等值的sort_no
                    QueryChainWrapper<SysMenu> menuEntity = query().eq("sort_no", sort);
                    if (menuEntity.isEmptyOfEntity()) {
                        //如果没有就将sort值赋给新的menu的sort_no
                        sysMenu.setSortNo(sort);
                        break;
                    }
                    sort += 0.01;
                }
            }
        }

        return save(sysMenu) ? JsonVO.success(ResultStatus.SUCCESS) : JsonVO.fail(ResultStatus.FAIL);

    }

    @Transactional
    @Override
    public JsonVO<ResultStatus> updateMenu(MenuDTO menuDTO) {
        boolean result = update().eq("id", menuDTO.getId())
                .set("parent_id", menuDTO.getParentId())
                .set("name", menuDTO.getName())
                .set("url", menuDTO.getUrl())
                .set("icon", menuDTO.getIcon())
                .set("update_time", LocalDateTime.now()).update();

        return result ? JsonVO.success(ResultStatus.SUCCESS) : JsonVO.fail(ResultStatus.FAIL);
    }

    @Override
    public JsonVO<ResultStatus> deleteMenu(SingleMenuQuery singleMenuQuery) {

        SysMenu sysMenu = BeanUtil.copyProperties(singleMenuQuery, SysMenu.class);

        int num = baseMapper.deleteById(sysMenu);

        return num >= 1 ? JsonVO.success(ResultStatus.SUCCESS) : JsonVO.fail(ResultStatus.FAIL);
    }
}
