package com.zeroone.star.psisysmanagement.service;

import com.zeroone.star.project.vo.sysmanagement.usermanagement.DepartVO;
import com.zeroone.star.psisysmanagement.entity.Depart;
import com.baomidou.mybatisplus.extension.service.IService;

import java.util.List;

/**
* @author Reynolds
* @description 针对表【sys_depart(组织机构表)】的数据库操作Service
* @createDate 2023-02-22 22:18:42
*/
public interface DepartService extends IService<Depart> {

    List<DepartVO> listDeparts();
}
