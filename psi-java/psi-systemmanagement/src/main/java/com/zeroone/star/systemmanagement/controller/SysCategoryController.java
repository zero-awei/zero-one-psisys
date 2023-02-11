package com.zeroone.star.systemmanagement.controller;


import com.zeroone.star.project.dto.systemmanagement.classifieddictionary.ClassifiedDictionaryDTO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.query.systemmanagement.classifieddictionary.ClassifiedDictionaryQuery;
import com.zeroone.star.project.systemmanagement.classifieddictionary.ClassifiedDictionaryApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.classifieddictionary.ClassifiedDictionaryVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import java.util.List;

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
@Api(tags = "分类字典")
public class SysCategoryController implements ClassifiedDictionaryApis {

    @ApiOperation("查询所有根字典")
    @GetMapping("/queryall")
    @Override
    public JsonVO<PageVO<List<ClassifiedDictionaryVO>>> queryAll(PageQuery condition) {
        return null;
    }
    @ApiOperation("查询指定根字典")
    @GetMapping("/queryone")
    @Override
    public JsonVO<PageVO<List<ClassifiedDictionaryVO>>> queryOne(String pid) {
        return null;
    }
    @ApiOperation("更新指定根字典")
    @PutMapping("/updateone")
    @Override
    public JsonVO update(ClassifiedDictionaryDTO data) {
        return null;
    }
    @ApiOperation("删除指定根字典")
    @DeleteMapping("/deleteone")
    @Override
    public JsonVO delete(String id) {
        return null;
    }
    @ApiOperation("插入根字典")
    @PostMapping("/insertone")
    @Override
    public JsonVO insert(ClassifiedDictionaryDTO data) {
        return null;
    }
}

