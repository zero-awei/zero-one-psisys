package com.zeroone.star.basedetail.service.customermanagement;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.basedetail.entity.customermanagement.CusCategory;
import com.zeroone.star.project.vo.basedetail.customermanagement.CustomerCategoryVO;



import java.util.List;

/**
 * @Description
 * @auther j2-yizhiyang
 * @date 2023/2/12 21:35
 */
public interface ICusCategoryService extends IService<CusCategory> {
    /**
     * 获取所有的分类
     * @return 查询结果
    */
    List<CustomerCategoryVO> listAllCusCategory();
}
