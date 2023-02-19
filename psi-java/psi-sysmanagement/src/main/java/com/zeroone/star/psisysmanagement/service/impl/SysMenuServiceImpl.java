package com.zeroone.star.psisysmanagement.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.extension.conditions.query.QueryChainWrapper;
import com.baomidou.mybatisplus.extension.conditions.update.UpdateChainWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.sysmanagement.menumanagement.MenuDTO;
import com.zeroone.star.project.query.sysmanagement.menumanagement.SingleMenuQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.login.MenuTreeVO;
import com.zeroone.star.psisysmanagement.entity.SysMenu;
import com.zeroone.star.psisysmanagement.mapper.SysMenuMapper;
import com.zeroone.star.psisysmanagement.service.ISysMenuService;
import lombok.val;
import lombok.var;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.time.LocalDateTime;

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
    public JsonVO<MenuTreeVO> querySingle(SingleMenuQuery singleMenuQuery) {
        return null;
    }

    @Override
    @Transactional
    public JsonVO<ResultStatus> addMenu(MenuDTO menuDTO) {
        //将MenuDTO数据复制到SysMenu对象
        SysMenu sysMenu= BeanUtil.copyProperties(menuDTO,SysMenu.class);
        sysMenu.setCreateTime(LocalDateTime.now());
//        sysMenu.setUpdateTime(LocalDateTime.now());

//        String id = menuDTO.getId();
        //获取父节点数据
        SysMenu sysMenu1= query().eq("id", menuDTO.getParentId()).one();
        //获取父节点sort_no
        Double sort=sysMenu1.getSortNo();
        //小数点后的位数
        var index = new String(String.valueOf(sort)).indexOf(".") + 1;//获取小数点的位置
        int count = new String(String.valueOf(sort)).length()- index;//获取小数点后的个数
        int temp=1;
        if (count==1){
            temp=temp*10;
        }else if (count==2){
            temp=temp*100;
        }else {
            temp=temp*1000;
        }
        //获取下一个父节点sort_no
        double d=sort+(double)1/temp;
        //查询该父节点当中子节点个数
        Long con=query().gt("sort_no",sort).lt("sort_no",d).count();
        sysMenu.setSortNo(sort+(double)(con+1)/(temp*10));
        //写入数据库
        boolean result = save(sysMenu);

        if (result=false){
            //失败返回错误
            return JsonVO.fail(ResultStatus.FAIL);
        }

        return JsonVO.success(ResultStatus.SUCCESS);
    }

    @Transactional
    @Override
    public JsonVO<ResultStatus> updateMenu(MenuDTO menuDTO) {
        boolean result= update().eq("id", menuDTO.getId()).
                set("parent_id", menuDTO.getParentId()).
                set("name", menuDTO.getName()).
                set("url", menuDTO.getUrl()).
                set("icon", menuDTO.getIcon()).
                set("update_time", LocalDateTime.now()).update();
        if (result=false){
            //失败返回错误
            return JsonVO.fail(ResultStatus.FAIL);
        }

        return JsonVO.success(ResultStatus.SUCCESS);
    }


    @Override
    public JsonVO<ResultStatus> deleteMenu(SingleMenuQuery singleMenuQuery) {

        return null;
    }
}
