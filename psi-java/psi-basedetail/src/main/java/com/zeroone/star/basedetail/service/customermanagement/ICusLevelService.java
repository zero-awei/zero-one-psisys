package com.zeroone.star.basedetail.service.customermanagement;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.basedetail.entity.customermanagement.CusLevel;
import com.zeroone.star.project.vo.basedetail.customermanagement.CustomerLevelVO;


import java.util.List;

/**
 * @Description
 * @auther j2-yizhiyang
 * @date 2023/2/13 19:15
 */
public interface ICusLevelService extends IService<CusLevel> {
    List<CustomerLevelVO> listAllCusLevel();
}
