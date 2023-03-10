package com.zeroone.star.systemmanagement.controller.classifieddictionary;


import com.zeroone.star.project.dto.systemmanagement.classifieddictionary.ClassifiedDictionarySaveDTO;
import com.zeroone.star.project.dto.systemmanagement.classifieddictionary.ClassifiedDictionaryUpdateDTO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.systemmanagement.classifieddictionary.ClassifiedDictionaryApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.PageVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.systemmanagement.classifieddictionary.ClassifiedDictionaryVO;
import com.zeroone.star.systemmanagement.service.classifieddictionary.impl.SysCategoryServiceImpl;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;


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

    @Resource
    private SysCategoryServiceImpl service;



    @ApiOperation("查询所有根字典")
    @GetMapping("/query-all")
    @Override
    public JsonVO<PageVO<ClassifiedDictionaryVO>> queryAll(PageQuery condition) {
        return JsonVO.success(service.listAll(condition));
    }

    @ApiOperation("查询指定根字典")
    @GetMapping("/query-children")
    @Override
    public JsonVO<PageVO<ClassifiedDictionaryVO>> queryChildren(String pid) {
        if(pid == null){
            return JsonVO.create(null, ResultStatus.FAIL);
        }
        return JsonVO.success(service.listChildren(pid));
    }

    @ApiOperation("更新指定根字典（返回值data值表示更新成功与否）")
    @PutMapping("/update-one")
    @Override
    public JsonVO<String> modify(ClassifiedDictionaryUpdateDTO data) {
        if(data.getName() == null && data.getName() == null){
            return JsonVO.create(null, ResultStatus.FAIL);
        }
        return JsonVO.success(service.update(data));
    }

    @ApiOperation("删除指定根字典（返回值data值表示删除成功与否）")
    @DeleteMapping("/delete-one")
    @Override
    public JsonVO<String> remove(String id) {
        if(id == null){
            return JsonVO.create(null, ResultStatus.FAIL);
        }
        String result = service.remove(id);
        if(result.equals("删除成功")){
            return JsonVO.success(result);
        }
        return JsonVO.fail(result);
    }


    @ApiOperation("插入根字典（返回值data值表示插入成功与否）")
    @PostMapping("/insert-one")
    @Override
    public JsonVO<String> add(ClassifiedDictionarySaveDTO data) {
        if(data == null || service.save(data).equals("数据已存在")){
            return JsonVO.create(service.save(data), ResultStatus.FAIL);
        }
        return JsonVO.success(service.save(data));
    }
}

