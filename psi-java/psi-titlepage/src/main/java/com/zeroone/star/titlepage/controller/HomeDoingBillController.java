package com.zeroone.star.titlepage.controller;


import com.zeroone.star.project.query.systemmanagement.ClassifiedDictionaryQuery;
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
 * VIEW 前端控制器
 * </p>
 *
 * @author ss
 * @since 2023-02-12
 */
@RestController
@RequestMapping("/homepage/home-doing-bill")
@Api(tags = "处理中主要单据")
public class HomeDoingBillController {

    @ApiOperation("查询所有根字典")
    @GetMapping("/queryall")
    public JsonVO<PageVO<ClassifiedDictionaryVO>> queryAll(ClassifiedDictionaryQuery condition) {
        return null;
    }
}

