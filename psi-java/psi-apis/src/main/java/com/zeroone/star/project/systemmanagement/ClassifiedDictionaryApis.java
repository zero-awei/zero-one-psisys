package com.zeroone.star.project.systemmanagement;

import com.zeroone.star.project.query.sample.SampleQuery;
import com.zeroone.star.project.query.systemmanagement.ClassifiedDictionaryQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.sample.SampleVO;
import com.zeroone.star.project.vo.systemmanagement.ClassifiedDictionaryVO;

/**
 * @author wangxiaohu
 */
public interface ClassifiedDictionaryApis {

    /**
     * 查询所有根字典
     * @param condition
     * @return
     */
    JsonVO<PageVO<ClassifiedDictionaryVO>> queryAll(ClassifiedDictionaryQuery condition);
}
