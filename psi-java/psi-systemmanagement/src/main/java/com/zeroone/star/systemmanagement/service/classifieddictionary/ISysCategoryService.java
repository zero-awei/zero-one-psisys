package com.zeroone.star.systemmanagement.service.classifieddictionary;

import com.zeroone.star.project.dto.systemmanagement.classifieddictionary.ClassifiedDictionarySaveDTO;
import com.zeroone.star.project.dto.systemmanagement.classifieddictionary.ClassifiedDictionaryUpdateDTO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.classifieddictionary.ClassifiedDictionaryVO;
import com.zeroone.star.systemmanagement.entity.classifieddictionary.SysCategory;
import com.baomidou.mybatisplus.extension.service.IService;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author suqier
 * @since 2023-02-11
 */
public interface ISysCategoryService extends IService<SysCategory> {
    /**
     * 查询所有
     * @param condition
     * @return 查询结果
     */
    PageVO<ClassifiedDictionaryVO> listAll(PageQuery condition);

    /**
     * 根据pid查询子节点
     * @param condition
     * @return 查询结果
     */
    PageVO<ClassifiedDictionaryVO> listChildren(String condition);

    /**
     * 更新操作
     * @param data
     * @return 更新结果
     */
    String update(ClassifiedDictionaryUpdateDTO data);

    /**
     * 根据id删除
     * @param id
     * @return 删除结果
     */
    String remove(String id);

    /**
     * 插入操作
     * @param data
     * @return 插入结果
     */
    String save(ClassifiedDictionarySaveDTO data);

}
