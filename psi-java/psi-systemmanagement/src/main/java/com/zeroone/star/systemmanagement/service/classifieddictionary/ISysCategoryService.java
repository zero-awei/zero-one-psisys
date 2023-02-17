package com.zeroone.star.systemmanagement.service.classifieddictionary;

import com.zeroone.star.project.dto.systemmanagement.classifieddictionary.ClassifiedDictionaryDTO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.classifieddictionary.ClassifiedDictionaryVO;
import com.zeroone.star.systemmanagement.entity.classifieddictionary.SysCategory;
import com.baomidou.mybatisplus.extension.service.IService;

import java.util.List;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author suqier
 * @since 2023-02-11
 */
public interface ISysCategoryService extends IService<SysCategory> {

    PageVO<ClassifiedDictionaryVO> queryAll(PageQuery condition);

    PageVO<ClassifiedDictionaryVO> queryOne(String condition);

    String update(ClassifiedDictionaryDTO data);

    String delete(String id);

    String insert(ClassifiedDictionaryDTO data);

}
