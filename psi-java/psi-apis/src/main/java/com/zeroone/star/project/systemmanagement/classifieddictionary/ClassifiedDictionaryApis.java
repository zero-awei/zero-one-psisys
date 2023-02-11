package com.zeroone.star.project.systemmanagement.classifieddictionary;

import com.zeroone.star.project.dto.systemmanagement.classifieddictionary.ClassifiedDictionaryDTO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.query.systemmanagement.classifieddictionary.ClassifiedDictionaryQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.classifieddictionary.ClassifiedDictionaryVO;

import java.util.List;

/**
 * @author wangxiaohu
 */
public interface ClassifiedDictionaryApis {

    /**
     * 查询所有根字典
     * @param condition
     * @return
     */
    JsonVO<PageVO<List<ClassifiedDictionaryVO>>> queryAll(PageQuery condition);

    /**
     * 查询指定根字典
     * @param pid
     * @return
     */
    JsonVO<PageVO<List<ClassifiedDictionaryVO>>> queryOne(String pid);


    /**
     * 更新指定根字典
     * @param data
     * @return
     */
    JsonVO update(ClassifiedDictionaryDTO data);

    /**
     * 删除指定根字典
     * @param id
     * @return
     */
    JsonVO delete(String id);


    /**
     * 添加指定根字典
     * @param data
     * @return
     */
    JsonVO insert(ClassifiedDictionaryDTO data);


}
