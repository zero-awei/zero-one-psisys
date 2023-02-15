package com.zeroone.star.titlepage.controller;


import com.zeroone.star.project.dto.systemmanagement.classifieddictionary.ClassifiedDictionaryDTO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.systemmanagement.classifieddictionary.ClassifiedDictionaryApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.systemmanagement.classifieddictionary.ClassifiedDictionaryVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;


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
    @GetMapping("/query-all")
    @Override
    public JsonVO<PageVO<ClassifiedDictionaryVO>> queryAll(PageQuery condition) {
        return null;
    }
    @ApiOperation("查询指定根字典")
    @GetMapping("/query-one")
    @Override
    public JsonVO<PageVO<ClassifiedDictionaryVO>> queryOne(String pid) {
        return null;
    }
    @ApiOperation("更新指定根字典")
    @PutMapping("/updateone")
    @Override
    public JsonVO<String> update(ClassifiedDictionaryDTO data) {
        return null;
    }
    @ApiOperation("删除指定根字典")
    @DeleteMapping("/deleteone")
    @Override
    public JsonVO<String> delete(String id) {
        return null;
    }
    @ApiOperation("插入根字典")
    @PostMapping("/insertone")
    @Override
    public JsonVO<String> insert(ClassifiedDictionaryDTO data) {
        return null;
    }
}

