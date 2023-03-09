package com.zeroone.star.project.systemmanagement.classifieddictionary;

import com.zeroone.star.project.dto.systemmanagement.classifieddictionary.ClassifiedDictionarySaveDTO;
import com.zeroone.star.project.dto.systemmanagement.classifieddictionary.ClassifiedDictionaryUpdateDTO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.classifieddictionary.ClassifiedDictionaryVO;

/**
 * <p>
 * 描述：分类字典接口定义
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author suqier
 * @version 1.0.0
 */
public interface ClassifiedDictionaryApis {

    /**
     * 查询所有根字典
     * @param condition
     * @return
     */
    JsonVO<PageVO<ClassifiedDictionaryVO>> queryAll(PageQuery condition);

    /**
     * 查询指定根字典
     * @param pid（父节点id）
     * @return
     */
    JsonVO<PageVO<ClassifiedDictionaryVO>> queryChildren(String pid);


    /**
     * 更新指定根字典
     * @param data
     * @return
     */
    JsonVO<String> modify(ClassifiedDictionaryUpdateDTO data);

    /**
     * 删除指定根字典
     * @param id
     * @return
     */
    JsonVO<String> remove(String id);


    /**
     * 添加指定根字典
     * @param data
     * @return
     */
    JsonVO<String> add(ClassifiedDictionarySaveDTO data);


}
