package com.zeroone.star.psisysmanagement.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.conditions.query.QueryChainWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.sysmanagement.menumanagement.MenuDTO;
import com.zeroone.star.project.query.sysmanagement.menumanagement.MenusQuery;
import com.zeroone.star.project.query.sysmanagement.menumanagement.SingleMenuQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.sysmanagement.menumanagement.MenuVO;
import com.zeroone.star.psisysmanagement.entity.SysMenu;
import com.zeroone.star.psisysmanagement.mapper.SysMenuMapper;
import com.zeroone.star.psisysmanagement.service.ISysMenuService;
import lombok.var;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

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
    public JsonVO<List<MenuVO>> querySingle(SingleMenuQuery singleMenuQuery) {

        List<SysMenu> menuList = query().eq("parent_id", singleMenuQuery.getId()).list();
        ArrayList<MenuVO> menuVOS = new ArrayList<>();
        for (SysMenu sysMenu : menuList) {
            MenuVO menuVO=BeanUtil.copyProperties(sysMenu,MenuVO.class);
            menuVOS.add(menuVO);
        }
        return JsonVO.create(menuVOS, ResultStatus.SUCCESS);
    }


    @Override
    @Transactional
    public JsonVO<ResultStatus> addMenu(MenuDTO menuDTO) {

        SysMenu sysMenu = BeanUtil.copyProperties(menuDTO, SysMenu.class);
        sysMenu.setCreateTime(LocalDateTime.now());
        String parentId = menuDTO.getParentId();

        //判断是否在二级菜单下继续新增菜单
        if (!parentId.equals("0")) {
            double parentSort = query().eq("id", parentId).one().getSortNo();
            String sortString = Double.toString(parentSort);
            if (sortString.length() == 4 && !sortString.endsWith("0")) {
                return JsonVO.fail(ResultStatus.FAIL);
            }
        }

        setSortNo(sysMenu);

        return save(sysMenu) ? JsonVO.success(ResultStatus.SUCCESS) : JsonVO.fail(ResultStatus.FAIL);

    }

    /**
     * 根据menuDTO中的parentId，给sysMenu的sort_no赋值
     *
     * @param sysMenu
     */
    private void setSortNo(SysMenu sysMenu) {
        //获取父节点id
        String parentId = sysMenu.getParentId();
        if (parentId.equals("0")) {

            int temp = 1;
            double sort;
            String sortString;
            //没有父节点时
            while (true) {//修改小数点后第一位
                sortString = temp + ".00";
                //防止精度丢失，用String转为double
                sort = Double.parseDouble(sortString);
                //查询表中是否已有与sort等值的sort_no
                if (checking(sysMenu, sort)) break;
                temp++;
            }

        } else {
            //有父节点时，获取父节点的sort_no
            double parentSort = query().eq("id", parentId).one().getSortNo();
            //将sort转换为字符串
            String sortString = Double.toString(parentSort);
            //去除小数点
            String replace = sortString.replace(".", "");
            //准备int数组sortArray
            int[] sortArray = new int[replace.length()];
            //将sortString每个数字传入数组
            for (int i = 0; i < sortArray.length; i++) {
                sortArray[i] = replace.charAt(i) - '0';
            }

            if (sortArray[1] == 0) {
                //当父节点的Sort_no小数点后一位为0时，说明父节点为一级菜单，小数点第二位也必定为0，如1.00
                //temp为小数点后第一位
                int temp = 1;
                double sort;

                while (true) {
                    //修改小数点后第一位
                    sortString = sortArray[0] + "." + temp + "0";
                    //防止精度丢失，用String转为double
                    sort = Double.parseDouble(sortString);
                    //尝试查询数据库中是否含有sort等值的sort_no
                    if (checking(sysMenu, sort)) break;
                    temp++;
                }
            } else {
                //如果小数点后第一位不为0，即父节点为二级菜单，如1.10；
                //由于限制只能创建到三级菜单，所以父节点只有三种情况，为空，一级菜单，二级菜单
                //故父节点sort_no小数点后第二位没有判断的必要
                int temp = 1;
                double sort;

                while (true) {
                    //修改小数点后第二位
                    sortString = sortArray[0] + "." + sortArray[1] + temp;
                    //防止精度丢失，用String转为double
                    sort = Double.parseDouble(sortString);
                    //尝试查询数据库中是否含有sort等值的sort_no
                    if (checking(sysMenu, sort)) break;
                    temp++;
                }
            }
        }

    }
    /**
     * setSortNo方法中判断数据库中是否有重复sort_no
     *
     * @param sysMenu
     * @param sort
     * @return
     */
    private boolean checking(SysMenu sysMenu, double sort) {
        QueryWrapper<SysMenu> queryWrapper = new QueryWrapper<>();
        queryWrapper.select("sort_no").eq("sort_no", sort);
        baseMapper.selectOne(queryWrapper);
        if (baseMapper.selectOne(queryWrapper) == null) {
            //如果没有就将sort值赋给新的menu的sort_no
            sysMenu.setSortNo(sort);
            return true;
        }
        return false;
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



        List<SysMenu> listSysMenu= query().eq("parent_id", singleMenuQuery.getId()).list();
        if (listSysMenu.isEmpty()){
            SysMenu sysMenu = BeanUtil.copyProperties(singleMenuQuery, SysMenu.class);
            int num = baseMapper.deleteById(sysMenu);

            return num >= 1 ? JsonVO.success(ResultStatus.SUCCESS) : JsonVO.fail(ResultStatus.FAIL);
        }
        baseMapper.deleteById(singleMenuQuery.getId());

        boolean result = removeByIds(listSysMenu);
        return result==true? JsonVO.success(ResultStatus.SUCCESS) : JsonVO.fail(ResultStatus.FAIL);

    }

}
