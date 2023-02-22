package com.zeroone.star.psisysmanagement.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.vo.sysmanagement.usermanagement.DepartVO;
import com.zeroone.star.psisysmanagement.entity.Depart;
import com.zeroone.star.psisysmanagement.service.DepartService;
import com.zeroone.star.psisysmanagement.mapper.DepartMapper;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

/**
* @author dan
* @description 针对表【sys_depart(组织机构表)】的数据库操作Service实现
* @createDate 2023-02-22 22:18:42
*/
@Service
@Slf4j
public class DepartServiceImpl extends ServiceImpl<DepartMapper, Depart> implements DepartService{

    @Override
    public List<DepartVO> listDepart() {
        List<Depart> departs = this.list();
        List<DepartVO> result = new ArrayList<>();
        for (Depart depart : departs) {
            DepartVO departVO = new DepartVO(depart.getId(), depart.getDepartName());
            result.add(departVO);
        }
        log.info("result: {}", result);
        return result;
    }
}
