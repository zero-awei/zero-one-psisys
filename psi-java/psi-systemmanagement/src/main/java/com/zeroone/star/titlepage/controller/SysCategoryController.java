package com.zeroone.star.titlepage.controller;


import com.zeroone.star.project.query.systemmanagement.ClassifiedDictionaryQuery;
import com.zeroone.star.project.systemmanagement.ClassifiedDictionaryApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.ClassifiedDictionaryVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
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
@Api(tags = "分类字典查询")
public class SysCategoryController implements ClassifiedDictionaryApis {

    @ApiOperation("查询所有根字典")
    @GetMapping("/queryall")
    @Override
    public JsonVO<PageVO<ClassifiedDictionaryVO>> queryAll(ClassifiedDictionaryQuery condition) {
        return null;
    }
}

