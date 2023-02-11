package com.zeroone.star.systemmanagement.controller;


import com.zeroone.star.project.query.systemmanagement.ClassifiedDictionaryQuery;
import com.zeroone.star.project.systemmanagement.ClassifiedDictionaryApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.ClassifiedDictionaryVO;
import org.springframework.web.bind.annotation.RequestMapping;

import org.springframework.web.bind.annotation.RestController;

/**
 * <p>
 *  前端控制器
 * </p>
 *
 * @author suqier
 * @since 2023-02-11
 */
@RestController
@RequestMapping("/systemmanagement/sys-category")
public class SysCategoryController implements ClassifiedDictionaryApis {

    @Override
    public JsonVO<PageVO<ClassifiedDictionaryVO>> queryAll(ClassifiedDictionaryQuery condition) {
        return null;
    }
}

